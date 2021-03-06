#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Intel8080_Disassembler/Disassembler.h"
#include "../Intel8080_Disassembler/Disassembler.cpp"
#include "../Intel8080_Disassembler/Rom.h"
#include "../Intel8080_Disassembler/Rom.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Disassembler_Tests
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(NOP_Test)
		{
			//Create a ROM.
			std::vector<uint8_t> data = { 0x00, 0x00 };
			Rom * rom = new Rom(data);

			//Create a disassember and give it the rom.
			Disassembler dis(rom);

			//Start the disassembly
			dis.Disassemble();

			//Get the result.
			std::string actual = dis.GetBuffer();
			std::string expect = "0000	NOP\n0001	NOP\n";
			//Assert equal
			Assert::AreEqual(expect, actual);
		}

	};
}