#include "CPU.h"



CPU::CPU()
{

}


CPU::~CPU()
{
}

void CPU::TestOpCode(byte opcode)
{
	std::cout << "Testing the opcode: " << opcode << std::endl;

	//De-reference this and call the correct member function from pointer.
	(this->*Intel8080Function[opcode])();
}

void CPU::Fetch()
{
}

void CPU::Decode()
{
}

void CPU::Execute()
{
}

void CPU::OpCodeOne()
{
	std::cout << "Called with the first opcode." << std::endl;
}