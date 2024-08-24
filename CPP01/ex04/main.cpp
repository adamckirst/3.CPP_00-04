/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 00:27:33 by achien-k          #+#    #+#             */
/*   Updated: 2024/08/25 00:44:53 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: Wrong number of arguments. Please provide a filename and two strings.";
		return 1;
	}
	std::ifstream sourceFile(argv[1]);
	if (!sourceFile.is_open())
	{
		std::cerr << "Failed to open the file." << std::endl;
	}
}