#pragma once

#include <iostream>


//Create a type to act as a byte
typedef unsigned char byte;

class CPU
{
public:
	CPU();
	~CPU();

	void TestOpCode(byte opcode);

private:
	//The Intel 8080 has 5 registers, each of which have 8 bit storage.
	uint8_t _A, _B, _C, _D, _E;

	//Also has a program counter
	uint8_t * programCounter;

	void Fetch();
	void Decode();
	void Execute();

	void(CPU::*Intel8080Function[255])() = 
	{ 
		&CPU::OpCodeOne
	};


	//OPCODES HERE
	void OpCodeOne();
};

