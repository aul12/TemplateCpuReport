template<Register res, Registers registers, Memory memory, std::size_t old_pc>
struct InstrImpl<Jump<res>, registers, memory, old_pc> {
    using reg = registers;
    static constexpr std::size_t pc = GetVal<registers, static_cast<std::size_t>(res)>::val;
    using mem = memory;
};

