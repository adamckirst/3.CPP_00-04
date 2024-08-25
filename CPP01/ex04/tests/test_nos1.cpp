#include "../include/tests.hpp"

void testNoS1(void)
{
	std::ofstream testFile("test2.txt");
	testFile << "This is a test file.";
	testFile.close();

	system("./SedForLosers test2.txt hello HELLO");

	std::ifstream outputFile("test2.txt.replace");
	std::string result((std::istreambuf_iterator<char>(outputFile)), std::istreambuf_iterator<char>());
	outputFile.close();

	assert(result == "This is a test file.");

	std::cout << "Test 2 passed: No occurrence of s1" << std::endl;
}