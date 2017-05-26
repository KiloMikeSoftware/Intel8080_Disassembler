#include "Rom.h"
#include <ios>
#include <fstream>


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
	std::string name;
	std::cout << "Save as (with extension): ";
	std::getline(std::cin, name);

	std::ofstream bin("../../roms/" + name, std::ios::out | std::ios::binary); //TODO: MAKE THIS PORTABLE.
	bin.write(reinterpret_cast<char *>(buffer), size);
	bin.close();
}
