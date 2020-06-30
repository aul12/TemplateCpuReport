template<Register addr_reg, Register reg, Registers registers, Memory memory, std::size_t old_pc>
struct InstrImpl<Store<addr_reg, reg>, registers, memory, old_pc> {
    using Reg = registers;
    static constexpr std::size_t PC = old_pc + 1;
    using Mem = typename SetVal<
                            base_type,
                            memory,
                            GetVal<registers, static_cast<std::size_t>(addr_reg)>::val,
                            GetVal<registers, static_cast<std::size_t>(reg)>::val
                        >::type;
};
