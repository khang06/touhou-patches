{
    binhacks: {
        quick_load_hook: {
            addr: "0x440FDF",
            code: "E8[codecave:quick_load_cave]"
        },
        quick_load_no_title_load_wait: {
            addr: "0x4511AF",
            code: "<nop:2>"
        },
        quick_load_no_title_input_wait1: {
            addr: "0x452204",
            code: "<nop:6>"
        },
        quick_load_no_title_input_wait2: {
            addr: "0x45200F",
            code: "<nop:6>"
        },
        quick_load_unlzss_hook: {
            addr: "0x45ECF0"
        }
    },
    codecaves: {
        quick_load_cave: {
            access: "rx",
            code: "53 8B5C2408 53 E8[0x4747F0] 83BB2801000000 75F1 5B C20400"
        }
    }
}