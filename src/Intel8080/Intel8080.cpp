// Intel8080.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ios>
#include "CPU.h"

int main()
{
	//Introduce the user to the emulator, and ask for a ROM to play.
	std::cout << "Welcome to the Intel8080 emulator. Please write or paste the full path to a ROM you wish to load." << std::endl;

	//temp bool
	bool got = false;

	while (!got)
	{
		std::string path;

		//Get the rom's path
		std::cout << "Path: ";
		std::getline(std::cin, path);

		std::cout << path << std::endl;
		got = true;
	}

	//todo: validate rom
	//...


	//create cpu on the stack, maybe move to heap later.
	CPU cpu = CPU();

	//Give it a 0x00 opcode for testing
	cpu.TestOpCode(0x00);


	return 0;
}

