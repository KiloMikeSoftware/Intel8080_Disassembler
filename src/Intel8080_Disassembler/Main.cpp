// Intel8080.cpp : Defines the entry point for the console application.
#include <iostream>
#include <string>
#include <ios>
#include <fstream>
#include "Rom.h"
#include "Disassembler.h"

int main()
{
	//Introduce the user to the emulator, and ask for a ROM to play.
	std::cout << "Welcome to the Intel8080 emulator. Please write or paste the full path to a ROM you wish to load." << std::endl;

	//Create the ROM:
	Rom * rom;

	//Boolean to determine if the rom was successfully found (not yet loaded, though)
	bool got = false;
	while (!got)
	{
		//Get the rom's path
		std::string path;
		std::cout << "Path: ";
		std::getline(std::cin, path);

		//Try to get initialize a rom with the user inputted path - it will throw an error if it can't initialize.
		try
		{
			std::cout << "Trying to load ROM." << std::endl;
			rom = new Rom(path);
			got = true;
		}
		catch (std::exception e)
		{
			got = false;
			std::cout << "Error loading ROM, the error message is: \"" << e.what() << "\". Try again." << std::endl;
		}

	}

	std::cout << "ROM Loaded. Press enter to continue." << std::endl;
	std::cin.ignore();

	//Create the disassembler.
	Disassembler disassembler(rom);
	disassembler.Disassemble(); //this will block until it's finished.

	//Destroy the rom.
	rom->Dump();
	delete rom;

	//Close the application.
	return 0;
}

