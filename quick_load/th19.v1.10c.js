{
    binhacks: {
        quick_load_hook: {
            addr: "Rx1345F0",
            code: "E8[codecave:quick_load_cave]"
        },
        quick_load_no_title_load_wait: {
            addr: "Rx15BB01",
            code: "EB"
        },
        quick_load_no_title_input_wait1: {
            addr: "Rx15A343",
            code: "<nop:6>"
        },
        quick_load_no_title_input_wait2: {
            addr: "Rx15A303",
            code: "<nop:2>"
        }
    },
    codecaves: {
        quick_load_cave: {
            access: "rx",
            code: "53 8B5C2408 53 E8[RxCE490] 83BB2C02000000 75F1 5B C20400"
        }
    }
}