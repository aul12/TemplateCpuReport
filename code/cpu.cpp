template<Program program, std::size_t old_pc, Registers registers, Memory memory>
struct ExecuteInstr {
    static constexpr auto PC = InstrImpl<typename GetType<program, old_pc>::type, registers, memory, old_pc>::PC;
    using Reg = typename InstrImpl<typename GetType<program, old_pc>::type, registers, memory, old_pc>::Reg;
    using Mem = typename InstrImpl<typename GetType<program, old_pc>::type, registers, memory, old_pc>::Mem;
};

template<Program program, std::size_t size, std::size_t PC, Registers registers, Memory memory>
struct CpuState {
    using val = typename CpuState<
                            program,
                            size,
                            ExecuteInstr<program, PC, registers, memory>::PC,
                            typename ExecuteInstr<program, PC, registers, memory>::Reg,
                            typename ExecuteInstr<program, PC, registers, memory>::Mem
                        >::val;
};

template<Program program, std::size_t size, Registers registers, Memory memory, >
struct CpuState<program, size, size, registers, memory, instr_count, max_instructions> {
    using val = Result<registers, memory, size>;
};

