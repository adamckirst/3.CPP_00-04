#include "../include/tests.hpp"

void testBasic(void)
{
	std::ofstream testFile("test1.txt");
	testFile << "Hello world, hello everyone.";
	testFile.close();

	system("./SedForLosers test1.txt hello HELLO");

	std::ifstream outputFile("test1.txt.replace");
	std::string result((std::istreambuf_iterator<char>(outputFile)), std::istreambuf_iterator<char>());
	outputFile.close();

	assert(result == "Hello world, HELLO everyone.");

	std::cout << "Test 1 passed: Basic replacement" << std::endl;
}