#include "../include/tests.hpp"

void testEqual(void)
{
	std::ofstream testFile("test5.txt");
	testFile << "This string will remain unchanged.";
	testFile.close();

	system("./SedForLosers test5.txt unchanged unchanged");

	std::ifstream outputFile("test5.txt.replace");
	std::string result((std::istreambuf_iterator<char>(outputFile)), std::istreambuf_iterator<char>());
	outputFile.close();

	assert(result == "This string will remain unchanged.");

	std::cout << "Test 5 passed: s1 equals s2" << std::endl;
}