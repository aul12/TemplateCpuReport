template<Register res, Register a, Register b, Registers registers, Memory memory, std::size_t old_pc>
struct InstrImpl<Add<res, a, b>, registers, memory, old_pc> {
    using Reg = typename SetVal<typename registers::elem::type,
                        registers,
                        static_cast<std::size_t>(res),
            GetVal<registers, static_cast<std::size_t>(a)>::val + GetVal<registers, static_cast<std::size_t>(b)>::val
                >::type;
    static constexpr auto PC = old_pc + 1;
    using Mem = memory;
};
