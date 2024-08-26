/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:55:32 by achien-k          #+#    #+#             */
/*   Updated: 2024/08/26 18:19:11 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl harl;

	std::cout << BOLD_TEXT << CYAN_TEXT << "DEBUG" << RESET_COLOR << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl
			  << BOLD_TEXT << GREEN_TEXT << "INFO" << RESET_COLOR << std::endl;
	harl.complain("INFO");
	std::cout << std::endl
			  << BOLD_TEXT << YELLOW_TEXT << "WARNING" << RESET_COLOR << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl
			  << BOLD_TEXT << RED_TEXT << "ERROR" << RESET_COLOR << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl
			  << BOLD_TEXT << RED_TEXT << "INVALID" << RESET_COLOR << std::endl;
	harl.complain("INVALID");

	return (0);
}