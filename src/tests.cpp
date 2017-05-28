#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Intel8080_Disassembler/Disassembler.h"
#include "../Intel8080_Disassembler/Rom.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Intel8080Test
{		
	TEST_CLASS(DisassemblerTests)
	{
	public:
		
		TEST_METHOD(NOP_Test)
		{
			//Create a ROM.
			uint8_t data[] = { 0x00, 0x00, 0x00 };
			Rom * rom = new Rom(data, 3);

			//Create a disassember and give it the rom.
			Disassembler dis(rom);

			//Start the disassembly
			dis.Disassemble();

			//Get the result.
			std::string result = dis.GetBuffer();

			//Assert equal
		}

	};
}