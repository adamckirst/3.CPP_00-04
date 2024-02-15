#include <iostream>
#include <string>

int	main(void) {
	std::string	string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << "String address: " << &string << std::endl;
	std::cout << "Pointer address: " << &stringPTR << std::endl;
	std::cout << "Reference address: " << &stringREF << std::endl;
	std::cout << "\nString value: " << string << std::endl;
	std::cout << "Value pointed by PTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed by REF: " << stringREF << std::endl;
	return (0);
}