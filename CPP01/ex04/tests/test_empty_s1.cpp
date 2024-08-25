#include "../include/tests.hpp"

void testEmptyS1(void)
{
	std::ofstream testFile("test3.txt");
	testFile << "Another test case.";
	testFile.close();

	system("./SedForLosers test3.txt \"\" HELLO");

	std::ifstream outputFile("test3.txt.replace");
	std::string result((std::istreambuf_iterator<char>(outputFile)), std::istreambuf_iterator<char>());
	outputFile.close();

	assert(result == "Another test case.");

	std::cout << "Test 3 passed: Empty s1" << std::endl;
}