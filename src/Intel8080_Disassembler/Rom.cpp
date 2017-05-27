#include "Rom.h"
#include <ios>
#include <fstream>
#include <sstream>

Rom::Rom(std::string path)
{
	//Try open it
	std::ifstream file = std::ifstream(path, std::ios::in | std::ios::binary);

	//Die if not exist
	if (!file.good())
		throw std::runtime_error("Error opening the file. It does not exist");

	//Go to EOF - get size - return to start.
	file.seekg(0, std::ios::end);
	size = file.tellg();
	file.seekg(0, std::ios::beg);

	buffer = new uint8_t[size];

	file.read(reinterpret_cast<char *>(buffer), size);
}


Rom::~Rom()
{
	delete[] buffer;
}

void Rom::Dump()
{
	std::ostringstream ss;
	ss << std::hex << std::setfill('0');

	for (int i = 0; i < size; i++)
	{
		ss << std::setw(2) << static_cast<unsigned>(buffer[i]);
	}


	std::cout << ss.str();
}
