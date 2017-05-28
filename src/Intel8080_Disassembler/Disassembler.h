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
	Disassembler(Rom * r);
	~Disassembler();
	bool Disassemble();				//A blocking function which will start the disassembly process
	bool WriteToFile();				//A function which will write the disassembled assembly code to a file

	std::string GetBuffer();
private:
	Rom * rom;						//The rom which in which we are going to disassemble.
	std::string outStr;				//This buffer is used to store the dissassembled assembly.

	void DisassembleOpCode(const uint8_t& opcode, uint8_t& pc);
	void NOP_NoOperation_0x00(int& cycles, uint8_t& pc);
	void PrintPC(std::ostringstream& in, uint8_t pc);
};

