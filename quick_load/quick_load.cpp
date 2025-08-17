// clang++ -m32 -msse -msse2 -std=c++20 "-IC:\Program Files (x86)\Microsoft DirectX SDK (June 2010)\Include" -O3 -c quick_load.cpp -o quick_load.obj

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define LZSS_DICTSIZE 0x2000
#define LZSS_DICTSIZE_MASK (LZSS_DICTSIZE - 1)
#define LZSS_MIN_MATCH 3

// Based on thtk's thlzss.c and https://fgiesen.wordpress.com/2018/02/20/reading-bits-in-far-too-many-ways-part-2/
extern "C" uint8_t* __fastcall unlzss_fast(uint8_t* __restrict src, size_t src_len, uint8_t* __restrict dst, size_t dst_len) {
    if (!dst) {
        dst = (uint8_t*)malloc(dst_len);
        if (!dst)
            return nullptr;
    }

    size_t src_pos = 0;
    size_t dst_pos = 0;
    uint32_t bit_buf = 0;
    uint8_t bit_count = 0;

    auto refill = [&](uint8_t count) __attribute__((always_inline)) {
        while (bit_count < count) {
            bit_buf |= (uint32_t)(__builtin_expect(src_pos == src_len, false) ? 0 : src[src_pos++]) << (24 - bit_count);
            bit_count += 8;
        }
    };
    auto get_bits = [&](uint8_t count) __attribute__((always_inline)) {
        uint32_t ret = bit_buf >> (32 - count);
        bit_buf <<= count;
        bit_count -= count;
        return ret;
    };

    while (true) {
        refill(1 + 13 + 4);
        if (get_bits(1)) {
            uint8_t c = get_bits(8);
            dst[dst_pos++] = c;
        } else {
            uint32_t match_offset = get_bits(13);
            if (__builtin_expect(!match_offset, false))
                break;

            uint32_t match_len = get_bits(4) + LZSS_MIN_MATCH;
            for (uint32_t i = 0; i < match_len; i++) {
                uint32_t dict_offset = (match_offset + i - 1) & LZSS_DICTSIZE_MASK;
                uint8_t c = dst[(dst_pos & ~LZSS_DICTSIZE_MASK) + dict_offset - (dict_offset >= (dst_pos & LZSS_DICTSIZE_MASK) ? LZSS_DICTSIZE : 0)];
                dst[dst_pos++] = c;
            }
        }
    }

    return dst;
}
