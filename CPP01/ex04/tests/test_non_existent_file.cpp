#include "../include/tests.hpp"

void testNonExistentFile(void)
{
	// Redirect std::cerr to a stringstream to capture the error output
	std::stringstream errorStream;
	std::streambuf *oldCerrBuffer = std::cerr.rdbuf(errorStream.rdbuf());

	system("./SedForLosers nonexistent_file.txt hello HELLO");

	// Reset std::cerr to its original state
	std::cerr.rdbuf(oldCerrBuffer);

	// Check if the captured output matches the expected error message
	std::string errorMessage = errorStream.str();
	assert(errorMessage == "Error: Failed to open the file.\n");

	std::cout << "Test 0 passed: Non-existent file error handling." << std::endl;
}