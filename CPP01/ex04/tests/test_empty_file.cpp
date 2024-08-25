#include "../include/tests.hpp"

void testEmptyFile(void)
{
	std::ofstream testFile("test4.txt");
	testFile.close();

	system("./SedForLosers test4.txt a b");

	std::ifstream outputFile("test4.txt.replace");
	std::string result((std::istreambuf_iterator<char>(outputFile)), std::istreambuf_iterator<char>());
	outputFile.close();

	assert(result == "");

	std::cout << "Test 4 passed: Empty file" << std::endl;
}