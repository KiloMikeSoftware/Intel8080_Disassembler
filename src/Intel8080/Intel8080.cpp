// Intel8080.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ios>
#include <fstream>
#include "CPU.h"
#include "Rom.h"

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

		try
		{
			rom = new Rom(path);
			got = true;
		}
		catch (std::exception e)
		{
			got = false;
			std::cout << "Error loading rom, the error message is: \"" << e.what() << "\". Try again." << std::endl;
		}

	}

	std::cout << "Rom Loaded. Initializing." << std::endl;




	return 0;
}

