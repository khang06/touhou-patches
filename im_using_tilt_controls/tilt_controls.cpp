// clang++ -m32 -msse -msse2 -mfpmath=sse -O2 -c tilt_controls.cpp -o tilt_controls.obj

#include <WinSock2.h>
#include <Windows.h>
#include <Ws2tcpip.h>
#include <d3d9.h>
#include <stdio.h>
#include <stdint.h>
#include <dinput.h>

#define _USE_MATH_DEFINES
#include <math.h>

#define PROJECT_NAME                "ImUsingTiltControls"
#define CEMUHOOK_PROTOCOL_VERSION   1001
#define CEMUHOOK_SERVER_PORT        26760
#define CEMUHOOK_CLIENT_PORT        42069
#define CEMUHOOK_CLIENT_MAGIC       0x43555344 // DSUC
#define CEMUHOOK_SERVER_MAGIC       0x53555344 // DSUS
#define CEMUHOOK_CLIENT_ID          0x12345678

struct D3DXQUATERNION {
    float x, y, z, w;
};

extern "C" {
    void log_mboxf(const char* caption, const UINT type, const char* format, ...);
    unsigned long __declspec(dllimport) crc32_z(unsigned long crc, const unsigned char *buf, size_t len);

    __declspec(dllimport) WINAPI D3DMATRIX* D3DXMatrixPerspectiveFovLH(
        D3DMATRIX *pOut, float fovy, float Aspect, float zn, float zf);
    __declspec(dllimport) WINAPI D3DMATRIX* D3DXMatrixLookAtLH(
        D3DMATRIX *pOut, const D3DVECTOR *pEye, const D3DVECTOR *pAt, const D3DVECTOR *pUp);
    __declspec(dllimport) WINAPI D3DMATRIX* D3DXMatrixTranslation(
        D3DMATRIX *pOut, float x, float y, float z);
    __declspec(dllimport) WINAPI D3DMATRIX* D3DXMatrixMultiply(
        D3DMATRIX *pOut, const D3DMATRIX *pM1, const D3DMATRIX *pM2 );
    __declspec(dllimport) WINAPI D3DMATRIX* D3DXMatrixRotationYawPitchRoll(
        D3DMATRIX *pOut, float Yaw, float Pitch, float Roll );
    __declspec(dllimport) WINAPI D3DMATRIX* D3DXMatrixRotationQuaternion(
        D3DMATRIX *pOut, const D3DXQUATERNION *pQ);
    __declspec(dllimport) WINAPI D3DXQUATERNION* D3DXQuaternionInverse(
        D3DXQUATERNION *pOut, const D3DXQUATERNION *pQ);
    __declspec(dllimport) WINAPI D3DXQUATERNION* D3DXQuaternionMultiply(
        D3DXQUATERNION *pOut, CONST D3DXQUATERNION *pQ1, const D3DXQUATERNION *pQ2);
}

static SOCKET g_send_socket = {};
static sockaddr_in g_dest_addr = {};

enum class PacketType : uint32_t {
    Version = 0x100000,
    Info = 0x100001,
    Data = 0x100002,
};

#pragma pack(push, 1)
template<typename T>
struct Packet {
    uint32_t magic;
    uint16_t version;
    uint16_t length;
    uint32_t crc;
    uint32_t peer_id;
    T data;

    static Packet<T> Create(T data) {
        Packet<T> packet{
            .magic = CEMUHOOK_CLIENT_MAGIC,
            .version = CEMUHOOK_PROTOCOL_VERSION,
            .length = sizeof(data),
            .crc = 0,
            .peer_id = CEMUHOOK_CLIENT_ID,
            .data = data,
        };
        packet.crc = crc32_z(0, (const unsigned char*)&packet, sizeof(packet));
        return packet;
    }
};

struct DataRequest {
    PacketType id;
    uint8_t flags;
    uint8_t slot;
    uint8_t mac[6];
};

struct DataResponse {
    PacketType id;
    uint8_t slot;
    uint8_t slot_state;
    uint8_t model;
    uint8_t connection_type;
    uint8_t mac[6];
    uint8_t battery;
    bool connected;
    uint32_t packet_num;
    uint8_t buttons[20];
    uint8_t touch[12];
    uint64_t motion_timestamp;
    float accel[3];
    float pitch;
    float yaw;
    float roll;
};
#pragma pack(pop)

struct ControllerData {
    bool connected;
    D3DXQUATERNION quat;
    float accel[3];
    float pitch;
    float yaw;
    float roll;
};
static ControllerData g_controller = {};

void init_socket() {
    ULONG pton;
    inet_pton(AF_INET, "127.0.0.1", &pton);
    auto port = htons(CEMUHOOK_CLIENT_PORT);

    sockaddr_in local{
        .sin_family = AF_INET,
        .sin_port = htons(CEMUHOOK_CLIENT_PORT),
        .sin_addr = {
            .S_un = {
                .S_addr = pton
            }
        }
    };
    g_dest_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(CEMUHOOK_SERVER_PORT),
        .sin_addr = {
            .S_un = {
                .S_addr = pton
            }
        }
    };

    g_send_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (bind(g_send_socket, (sockaddr*)&local, sizeof(local)) < 0)
        log_mboxf(PROJECT_NAME, MB_ICONHAND, "bind failed with code: %d", WSAGetLastError());
}

// https://x-io.co.uk/open-source-imu-and-ahrs-algorithms/
float q0 = sqrtf(0.5f), q1 = sqrtf(0.5f), q2 = 0.0f, q3 = 0.0f;
float g_beta = 10.0f;
void MadgwickAHRSupdateIMU(float dt, float gx, float gy, float gz, float ax, float ay, float az) {
	float recipNorm;
	float s0, s1, s2, s3;
	float qDot1, qDot2, qDot3, qDot4;
	float _2q0, _2q1, _2q2, _2q3, _4q0, _4q1, _4q2 ,_8q1, _8q2, q0q0, q1q1, q2q2, q3q3;

	// Rate of change of quaternion from gyroscope
	qDot1 = 0.5f * (-q1 * gx - q2 * gy - q3 * gz);
	qDot2 = 0.5f * (q0 * gx + q2 * gz - q3 * gy);
	qDot3 = 0.5f * (q0 * gy - q1 * gz + q3 * gx);
	qDot4 = 0.5f * (q0 * gz + q1 * gy - q2 * gx);

	// Compute feedback only if accelerometer measurement valid (avoids NaN in accelerometer normalisation)
	if(!((ax == 0.0f) && (ay == 0.0f) && (az == 0.0f))) {

		// Normalise accelerometer measurement
		recipNorm = 1.0f / sqrtf(ax * ax + ay * ay + az * az);
		ax *= recipNorm;
		ay *= recipNorm;
		az *= recipNorm;   

		// Auxiliary variables to avoid repeated arithmetic
		_2q0 = 2.0f * q0;
		_2q1 = 2.0f * q1;
		_2q2 = 2.0f * q2;
		_2q3 = 2.0f * q3;
		_4q0 = 4.0f * q0;
		_4q1 = 4.0f * q1;
		_4q2 = 4.0f * q2;
		_8q1 = 8.0f * q1;
		_8q2 = 8.0f * q2;
		q0q0 = q0 * q0;
		q1q1 = q1 * q1;
		q2q2 = q2 * q2;
		q3q3 = q3 * q3;

		// Gradient decent algorithm corrective step
		s0 = _4q0 * q2q2 + _2q2 * ax + _4q0 * q1q1 - _2q1 * ay;
		s1 = _4q1 * q3q3 - _2q3 * ax + 4.0f * q0q0 * q1 - _2q0 * ay - _4q1 + _8q1 * q1q1 + _8q1 * q2q2 + _4q1 * az;
		s2 = 4.0f * q0q0 * q2 + _2q0 * ax + _4q2 * q3q3 - _2q3 * ay - _4q2 + _8q2 * q1q1 + _8q2 * q2q2 + _4q2 * az;
		s3 = 4.0f * q1q1 * q3 - _2q1 * ax + 4.0f * q2q2 * q3 - _2q2 * ay;
		recipNorm = 1.0f / sqrtf(s0 * s0 + s1 * s1 + s2 * s2 + s3 * s3); // normalise step magnitude
		s0 *= recipNorm;
		s1 *= recipNorm;
		s2 *= recipNorm;
		s3 *= recipNorm;

		// Apply feedback step
		qDot1 -= g_beta * s0;
		qDot2 -= g_beta * s1;
		qDot3 -= g_beta * s2;
		qDot4 -= g_beta * s3;
	}

	// Integrate rate of change of quaternion to yield quaternion
	q0 += qDot1 * dt;
	q1 += qDot2 * dt;
	q2 += qDot3 * dt;
	q3 += qDot4 * dt;

	// Normalise quaternion
	recipNorm = 1.0f / sqrtf(q0 * q0 + q1 * q1 + q2 * q2 + q3 * q3);
	q0 *= recipNorm;
	q1 *= recipNorm;
	q2 *= recipNorm;
	q3 *= recipNorm;
}

bool g_recenter_requested = false;
DWORD WINAPI recv_thread(LPVOID) {
    int recv_len;
    sockaddr_in sender;
    int sender_size = sizeof(sender);
    char buf[1024] = {};
    
    uint32_t last_packet_num = 0;
    uint64_t last_motion_timestamp = 0;
    while (true) {
        if ((recv_len = recvfrom(g_send_socket, buf, sizeof(buf), 0, (struct sockaddr*)&sender, &sender_size)) == SOCKET_ERROR) {
            log_mboxf(PROJECT_NAME, MB_ICONHAND, "recvfrom failed with code: %d", WSAGetLastError());
            return 1;
        }
        if (recv_len != sizeof(Packet<DataResponse>))
            continue;

        auto packet = (Packet<DataResponse>*)&buf;
        if (packet->magic != CEMUHOOK_SERVER_MAGIC ||
            packet->version != CEMUHOOK_PROTOCOL_VERSION ||
            packet->length != sizeof(DataResponse) ||
            packet->data.id != PacketType::Data ||
            packet->data.packet_num <= last_packet_num) // will drop the first packet but who cares
            continue;

        auto crc = packet->crc;
        packet->crc = 0;
        if (crc != crc32_z(0, (const unsigned char*)packet, sizeof(Packet<DataResponse>)))
            continue;

        g_controller.connected = packet->data.slot_state == 2;
        memcpy(&g_controller.accel, &packet->data.accel, sizeof(float) * 3);
        g_controller.pitch = packet->data.pitch * (M_PI / 180.0f);
        g_controller.yaw = packet->data.yaw * (M_PI / 180.0f);
        g_controller.roll = packet->data.roll * (M_PI / 180.0f);
        if (last_motion_timestamp && (last_motion_timestamp != packet->data.motion_timestamp)) {
            if (g_recenter_requested) {
                q0 = sqrtf(0.5f);
                q1 = sqrtf(0.5f);
                q2 = 0.0;
                q3 = 0.0;
                g_beta = 10.0f;
                g_recenter_requested = false;
            }

            float dt = (float)(packet->data.motion_timestamp - last_motion_timestamp) * 0.000001;
            MadgwickAHRSupdateIMU(dt, g_controller.pitch, g_controller.yaw, g_controller.roll,
                g_controller.accel[0], -g_controller.accel[1], -g_controller.accel[2]);
            g_controller.quat = { -q0, q1, q2, -q3 }; // Weird stuff I have to do to get the right rotation. I figured this out by brute force...
            if (g_beta > 0.1) {
                g_beta -= (g_beta - 0.1f) * dt * 4.0;
                if (g_beta < 0.1)
                    g_beta = 0.1;
            }
        }
        last_motion_timestamp = packet->data.motion_timestamp;
    }

    return 0;
}

class CCalcChain {
public:
    uint32_t priority;
    uint32_t flags;
    int(__fastcall* calc)(void*);
    int(__fastcall* init)(void*);
    int(__fastcall* destroy)(void*);
    int list_node;
    BYTE gap18[12];
    void* this_ptr;

    static CCalcChain* __stdcall Create(int(__fastcall*)(void*));
    static int __stdcall RegisterCalc(CCalcChain* chain, int priority);
    static int __stdcall RegisterDraw(CCalcChain* chain, int priority);
};

class CAscii {
public:
    static CAscii* Instance;

    void Draw(float* pos, const char* format, ...);
};

struct ZunVertex {
    float x, y, z, w;
    DWORD color;
    float u, v;
};

class CAnmManager {
public:
    char gap0[0xCC];
    uint32_t flush_count;
    char gapD0[0xBC80C3];
    char blend_op;
    char gapBC8194[0x5C];
    uint32_t sprite_count;
    char gapBC81F4[0x380000];
    ZunVertex *next_vertex_buffer;
    ZunVertex *vertex_buffer;
    char gapF481FC[0xAD0D8];
};

extern "C" IDirect3DDevice9* g_device;
extern "C" LPDIRECTINPUTDEVICE8A g_joypad;
extern "C" D3DPRESENT_PARAMETERS g_present_params;

struct CustomVertex {
    float x, y, z;
    DWORD color;
    float u, v;
};

static CustomVertex* g_vertex_buffer = nullptr;
static uint32_t g_vertex_buffer_capacity = 0;
static D3DMATRIX g_world_transform = {};
static D3DMATRIX g_proj_transform = {};
static D3DMATRIX g_tex0_transform = {};

inline D3DMATRIX* D3DXMatrixIdentity(D3DMATRIX *pOut) {
    pOut->m[0][1] = pOut->m[0][2] = pOut->m[0][3] =
    pOut->m[1][0] = pOut->m[1][2] = pOut->m[1][3] =
    pOut->m[2][0] = pOut->m[2][1] = pOut->m[2][3] =
    pOut->m[3][0] = pOut->m[3][1] = pOut->m[3][2] = 0.0f;

    pOut->m[0][0] = pOut->m[1][1] = pOut->m[2][2] = pOut->m[3][3] = 1.0f;
    return pOut;
}

extern "C" int __fastcall flush_sprites(CAnmManager* self) {
    if (self->sprite_count) {
        // Convert the vertices from (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1) to (D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1)
        // The vertices are pretransformed by default, so this will let us have the GPU do more matrix multiplications on them
        if (self->sprite_count * 6 > g_vertex_buffer_capacity) {
            if (g_vertex_buffer)
                free(g_vertex_buffer);
            g_vertex_buffer = (CustomVertex*)malloc(self->sprite_count * 6 * sizeof(CustomVertex));
        }
        for (uint32_t i = 0; i < self->sprite_count * 6; i++) {
            memcpy(&g_vertex_buffer[i].x, &self->vertex_buffer[i].x, offsetof(ZunVertex, w));
            memcpy(&g_vertex_buffer[i].color, &self->vertex_buffer[i].color, sizeof(CustomVertex) - offsetof(CustomVertex, color));
        }

        // Calculate view transform
        D3DMATRIX view_transform;
        D3DXQUATERNION inv;
        D3DXQuaternionInverse(&inv, &g_controller.quat);
        D3DXMatrixRotationQuaternion(&view_transform, &inv);

        // Backup the current transforms and apply our own
        D3DMATRIX orig_world;
        D3DMATRIX orig_view;
        D3DMATRIX orig_proj;
        D3DMATRIX orig_tex0;
        g_device->GetTransform(D3DTS_WORLD, &orig_world);
        g_device->SetTransform(D3DTS_WORLD, &g_world_transform);
        g_device->GetTransform(D3DTS_VIEW, &orig_view);
        g_device->SetTransform(D3DTS_VIEW, &view_transform);
        g_device->GetTransform(D3DTS_PROJECTION, &orig_proj);
        g_device->SetTransform(D3DTS_PROJECTION, &g_proj_transform);
        g_device->GetTransform(D3DTS_TEXTURE0, &orig_tex0);
        g_device->SetTransform(D3DTS_TEXTURE0, &g_tex0_transform);

        // Original CAnmManager::FlushSprites code but with the modified vertices and FVF
        if (self->blend_op != 1) {
            g_device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
            g_device->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
            self->blend_op = 1;
        }
        g_device->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);
        g_device->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
        g_device->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);
        g_device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, self->sprite_count * 2, g_vertex_buffer, sizeof(CustomVertex));
        self->flush_count++;
        self->next_vertex_buffer = self->vertex_buffer;
        self->sprite_count = 0;

        // Restore transforms
        g_device->SetTransform(D3DTS_WORLD, &orig_world);
        g_device->SetTransform(D3DTS_VIEW, &orig_view);
        g_device->SetTransform(D3DTS_PROJECTION, &orig_proj);
        g_device->SetTransform(D3DTS_TEXTURE0, &orig_tex0);
    }
    return 1;
}

float g_tilt[3] = {};
extern "C" int g_vel[2] = {};
extern "C" uint32_t g_input;

int __fastcall calc_func(void*) {
    static DWORD last_request = 0;
    if (timeGetTime() > last_request + 1000) {
        auto packet = Packet<DataRequest>::Create({
            .id = PacketType::Data,
            .flags = 1, // Slots only, no MAC
            .slot = 0,
        });
        if (sendto(g_send_socket, (char*)&packet, sizeof(packet), 0, (struct sockaddr*)&g_dest_addr, sizeof(g_dest_addr)) == SOCKET_ERROR) {
            log_mboxf(PROJECT_NAME, MB_ICONHAND, "sendto failed with code: %d", WSAGetLastError());
            return 1;
        }
        last_request = timeGetTime();
    }

    DIJOYSTATE2 joypad_state = {};
    if (g_joypad &&
        SUCCEEDED(g_joypad->Poll()) &&
        SUCCEEDED(g_joypad->GetDeviceState(sizeof(joypad_state), &joypad_state)))
    {
        if (joypad_state.rgbButtons[4] & 0x80)
            g_recenter_requested = true;
    }

    // BOO!!!! D3DX FUNCTIONS IN GAME UPDATE CODE!!!!
    D3DXQUATERNION forward = {1.0, 0.0, 0.0, 0.0};
    D3DXQUATERNION up = {0.0, 1.0, 0.0, 0.0};
    D3DXQUATERNION right = {0.0, 0.0, 1.0, 0.0};
    D3DXQUATERNION inv;
    D3DXQuaternionInverse(&inv, &g_controller.quat);
    D3DXQuaternionMultiply(&forward, D3DXQuaternionMultiply(&forward, &inv, &forward), &g_controller.quat);
    D3DXQuaternionMultiply(&up, D3DXQuaternionMultiply(&up, &inv, &up), &g_controller.quat);
    D3DXQuaternionMultiply(&right, D3DXQuaternionMultiply(&right, &inv, &right), &g_controller.quat);
    g_tilt[0] = forward.z;
    g_tilt[1] = -forward.x;
    g_tilt[2] = forward.y;

    // Too lazy to scale this to the actual move/focus speed per character
    float multiplier = (g_input & 8) ? 750 : 1500;
    bool flip_x = right.z > 0.0f; // Seija joke hack
    bool flip_y = up.x > 0.0f;
    g_vel[0] = g_tilt[0] * multiplier * (flip_x ? -1.0f : 1.0f);
    g_vel[1] = g_tilt[1] * multiplier * (flip_y ? -1.0f : 1.0f);
    return 1;
}

int __fastcall draw_func(void*) {
    float pos[3] = {0.0, 0.0, 0.0};
    if (CAscii::Instance) {
        CAscii::Instance->Draw(
            pos, "Controller connected: %s\nTilt X: %s%f\nTilt Y: %s%f\nTilt Z: %s%f",
            g_controller.connected ? "true" : "false",
            g_tilt[0] >= 0 ? " " : "",
            g_tilt[0],
            g_tilt[1] >= 0 ? " " : "",
            g_tilt[1],
            g_tilt[2] >= 0 ? " " : "",
            g_tilt[2]
        );
    }
    return 1;
}

extern "C" int hook_entry() {
    WSAData data;
    WSAStartup(MAKEWORD(2, 2), &data);
    init_socket();
    CreateThread(NULL, 0, recv_thread, NULL, 0, NULL);

    auto calc = CCalcChain::Create(calc_func);
    calc->flags |= 2;
    CCalcChain::RegisterCalc(calc, 1);

    auto draw = CCalcChain::Create(draw_func);
    draw->flags |= 2;
    CCalcChain::RegisterDraw(draw, 66);

    // Set up matrices
    // Translate to the origin, rotate, look at, perspective project, translate again
    // The look at, projection, and second translation can be merged
    auto ui_scale = (float)g_present_params.BackBufferWidth / 640.0f;
    D3DMATRIX translation;
    D3DMATRIX rotation;
    D3DXMatrixTranslation(&translation, -224.0 * ui_scale + 0.5f, -240.0 * ui_scale + 0.5f, 0.0f);
    D3DXMatrixRotationYawPitchRoll(&rotation, M_PI_2, M_PI_2, 0.0f);
    D3DXMatrixMultiply(&g_world_transform, &translation, &rotation);

    D3DMATRIX look_at;
    D3DMATRIX projection;
    D3DMATRIX screen_translation;
    float dist = g_present_params.BackBufferHeight / 1.75f / tan(M_PI / 6.0f);
    D3DVECTOR eye = { dist, 0.0f, 0.0f };
    D3DVECTOR at = { 0.0f, 0.0f, 0.0f };
    D3DVECTOR up = { 0.0f, 1.0f, 0.0f };
    D3DXMatrixLookAtLH(&look_at, &eye, &at, &up);
    D3DXMatrixPerspectiveFovLH(&projection, M_PI / 3.0f, 4.0f / 3.0f, 0.0f, 10000.0f);
    D3DXMatrixTranslation(&screen_translation, -96.0f / 640.0f * 2.0f, 0.0f, 0.0f);
    D3DXMatrixMultiply(&g_proj_transform, &look_at, &projection);
    D3DXMatrixMultiply(&g_proj_transform, &g_proj_transform, &screen_translation);

    D3DXMatrixIdentity(&g_tex0_transform);
    return 0;
}
