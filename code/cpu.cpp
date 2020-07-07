template<Program program, std::size_t old_pc, Registers registers, Memory memory>
struct ExecuteInstr {
    static constexpr auto pc = InstrImpl<typename GetType<program, old_pc>::type, registers, memory, old_pc>::pc;
    using reg = typename InstrImpl<typename GetType<program, old_pc>::type, registers, memory, old_pc>::reg;
    using mem = typename InstrImpl<typename GetType<program, old_pc>::type, registers, memory, old_pc>::mem;
};

template<Program program, std::size_t size, std::size_t PC, Registers registers, Memory memory>
struct CpuState {
    using val = typename CpuState<
                            program,
                            size,
                            ExecuteInstr<program, PC, registers, memory>::pc,
                            typename ExecuteInstr<program, PC, registers, memory>::reg,
                            typename ExecuteInstr<program, PC, registers, memory>::mem
                        >::val;
};

template<Program program, std::size_t size, Registers registers, Memory memory, >
struct CpuState<program, size, size, registers, memory, instr_count, max_instructions> {
    using val = Result<registers, memory, size>;
};

