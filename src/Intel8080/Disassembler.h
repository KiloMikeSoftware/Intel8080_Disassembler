#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Rom.h"

//The purpose of this class is to disassemble games using an Intel 8080 CPU.
//This class is not used in the emulator thus I am not concerned with performance.
class Disassembler
{
public:
	Disassembler(Rom r);
	~Disassembler();
	bool Begin();					//A blocking function which will start the disassembly process
	bool WriteToFile();				//A function which will write the disassembled assembly code to a file

private:
	Rom rom;						//The rom which in which we are going to disassemble.
	std::ostringstream outBuffer;	//This buffer is used to store the dissassembled assembly.

	int DisassembleOpCode(uint8_t * buffer, int pc);
	std::string NOP_NoOperation_0x00(uint8_t * opcode, int &cycles, int &pc);
};

