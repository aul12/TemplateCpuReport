template<Register addr_reg, Register data_reg, Registers registers, Memory memory, std::size_t old_pc>
struct InstrImpl<Store<addr_reg, data_reg>, registers, memory, old_pc> {
    using reg = registers;
    static constexpr std::size_t pc = old_pc + 1;
    using mem = typename SetVal<
                            base_type,
                            memory,
                            GetVal<registers, static_cast<std::size_t>(addr_reg)>::val,
                            GetVal<registers, static_cast<std::size_t>(data_reg)>::val
                        >::type;
};
