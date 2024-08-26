/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:20:57 by achien-k          #+#    #+#             */
/*   Updated: 2024/08/26 18:21:02 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "String address: " << &string << std::endl;
	std::cout << "Pointer address: " << &stringPTR << std::endl;
	std::cout << "Reference address: " << &stringREF << std::endl;
	std::cout << "\nString value: " << string << std::endl;
	std::cout << "Value pointed by PTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed by REF: " << stringREF << std::endl;
	return (0);
}