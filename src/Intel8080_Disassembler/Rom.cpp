#include "Rom.h"

uint8_t& Rom::operator[](int i)
{
	return buffer[i];
}

Rom::Rom()
{
}

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

	//Resize vector to be equal to the file size in terms of bytes
	buffer.resize(size);

	//Next, we read the file in to buffer. It's saying - start at the 0th element, and extract size elements.
	//Note we are passing buffer as a reference - so that the copy in this scope, and the copy in the methods scope, is the same.
	//Otherwise, our copy of buffer won't change after the method finishes. (We could do buffer = file.read(...) but that is not possible given the method signature.
	file.read(reinterpret_cast<char*>(&buffer[0]), size);
}

Rom::Rom(std::vector<uint8_t> data)
{
	buffer = data;
	size = buffer.size();
}


Rom::~Rom()
{
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
