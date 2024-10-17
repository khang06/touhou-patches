{
    binhacks: {
        quick_load_hook: {
            addr: "0x460446",
            code: "E8[codecave:quick_load_cave]"
        },
        quick_load_no_title_load_wait: {
            addr: "0x43F357",
            code: "EB"
        },
        quick_load_no_title_input_wait1: {
            addr: "0x4402E1",
            code: "<nop:6>"
        },
        quick_load_no_title_input_wait2: {
            addr: "0x43FF21",
            code: "<nop:6>"
        }
    },
    codecaves: {
        quick_load_cave: {
            access: "rx",
            code: "53 57 89FB 89DF E8[0x45FFC0] 83BB2401000000 75F0 5F 5B C3"
        }
    }
}