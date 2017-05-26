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
	//byte opcode;
	//byte programCounter;


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

