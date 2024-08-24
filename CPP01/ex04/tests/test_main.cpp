#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdlib>

void runTests()
{
	// Test 1: Basic replacement
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

	// Test 2: No occurrence of s1
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

	// Test 3: Empty s1 (should leave file unchanged)
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

	// Test 4: Empty file
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

	// Test 5: s1 is equal to s2 (file should remain unchanged)
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

	// Test 6: Non-existent file
	{
		int result = system("./SedForLosers nonexistent.txt a b");
		assert(result != 0); // Expecting a non-zero exit code for error

		std::cout << "Test 6 passed: Non-existent file" << std::endl;
	}
}

int main()
{
	runTests();
	std::cout << "All tests passed!" << std::endl;
	return 0;
}
