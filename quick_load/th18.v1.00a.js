{
    binhacks: {
        quick_load_hook: {
            addr: "0x4535CB",
            code: "E8[codecave:quick_load_cave]"
        },
        quick_load_no_title_load_wait: {
            addr: "0x464C28",
            code: "EB"
        },
        quick_load_no_title_input_wait: {
            addr: "0x465CCB",
            code: "<nop:6>"
        }
    },
    codecaves: {
        quick_load_cave: {
            access: "rx",
            code: "53 8B5C2408 53 E8[0x486920] 83BB2801000000 75F1 5B C20400"
        }
    }
}