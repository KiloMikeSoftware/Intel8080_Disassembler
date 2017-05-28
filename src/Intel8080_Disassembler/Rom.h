#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <ios>
#include <fstream>
#include <sstream>
#include <vector>

class Rom
{
public:
	Rom(std::string path); //accepts a path to the ROM. will destroy itself if path is invalid.
	Rom(std::vector<uint8_t> data);
	~Rom();
	uint8_t Size() { return size; }
	void Dump(); //used to dump the rom (e.g. it's read from cartridge slot attached to Raspberry Pi or similar.) Dumps to the emulators /rom folder.

	//Overload of the [] operator to give us the buffers instructions at that memory address.
	uint8_t& operator[] (int i);
private:
	Rom();
	std::vector<uint8_t> buffer; //max rom size of 64kb
	size_t size;
};

