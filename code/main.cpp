using result = Cpu<my_program>::run;
using printer = printer<result::Reg, result::Mem>;

std::cout << "Executed " << result::instr_count << " instructions\n" << std::endl;
std::cout << "Registers:" << std::endl;
printer::reg();

std::cout << "\nMemory:" << std::endl;
printer::mem();
