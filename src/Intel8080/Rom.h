#pragma once

#include <iostream>
#include <iomanip>
#include <string>

class Rom
{
public:
	Rom(std::string); //accepts a path to the ROM. will destroy itself if path is invalid.
	~Rom();

	void Dump(); //used to dump the rom (e.g. it's read from cartridge slot attached to Raspberry Pi or similar.) Dumps to the emulators /rom folder.


private:
	uint8_t * buffer; //max rom size of 64kb
	size_t size;



};

