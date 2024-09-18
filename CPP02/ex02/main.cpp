/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:37:32 by achien-k          #+#    #+#             */
/*   Updated: 2024/09/11 18:42:52 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a(14.2f);
	Fixed b(14.2f);

	std::cout << BLUE_TEXT << BOLD_TEXT << "Values" << RESET_FORMAT << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl
			  << std::endl;

	std::cout << GREEN_TEXT << BOLD_TEXT << "Arithmetic operators" << RESET_FORMAT << std::endl;
	std::cout << "a + b: " << (a + b) << std::endl;
	std::cout << "a - b: " << (a - b) << std::endl;
	std::cout << "a * b: " << (a * b) << std::endl;
	std::cout << "a / b: " << (a / b) << std::endl
			  << std::endl;

	std::cout << YELLOW_TEXT << BOLD_TEXT << "Increment and decrement operators" << RESET_FORMAT << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl
			  << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "--b: " << --b << std::endl;
	std::cout << "b--: " << b-- << std::endl;
	std::cout << "b: " << b << std::endl
			  << std::endl;

	std::cout << CYAN_TEXT << BOLD_TEXT << "Comparison operators" << RESET_FORMAT << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl
			  << std::endl;
	std::cout << "a == b: " << std::boolalpha << (a == b) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl
			  << std::endl;

	std::cout << RED_TEXT << BOLD_TEXT << "Min and Max" << RESET_FORMAT << std::endl;
	std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;
	std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;

	const Fixed c = a;
	const Fixed d = b;
	std::cout << "const max(c, d): " << Fixed::max(c, d) << std::endl;
	std::cout << "const min(c, d): " << Fixed::min(c, d) << std::endl
			  << std::endl;

	return 0;
}