/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 00:27:33 by achien-k          #+#    #+#             */
/*   Updated: 2024/08/26 14:32:15y achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/helpers.hpp"

int error_return(std::string msg)
{
	std::cerr << BOLD_TEXT << RED_TEXT << "ERROR: " << msg << std::endl;
	return (-1);
}

std::string replace_text(const std::string &text, const std::string s1, const std::string s2)
{
	std::ostringstream result;
	size_t pos = 0;
	size_t prev_pos = 0;

	while ((pos = text.find(s1, pos)) != std::string::npos)
	{
		result << text.substr(prev_pos, pos - prev_pos) << s2;
		pos += s1.length();
		prev_pos = pos;
	}
	result << text.substr(prev_pos);
	return result.str();
}

int main(int argc, char **argv)
{
	if (argc != 4)
		return error_return("Wrong number of arguments. Please provide a filename and two strings.");

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty())
		return error_return("Please provide a non-empty source string.");

	std::ifstream sourceFile;
	sourceFile.open(filename.c_str());
	if (!sourceFile.is_open())
		return error_return("Failed to open the file.");

	std::ostringstream text;
	text << sourceFile.rdbuf();
	if (text.str().empty())
		return error_return("File is empty.");

	filename += ".replace";

	std::ofstream replaceFile(filename.c_str());
	replaceFile << replace_text(text.str(), s1, s2);
	std::cout << GREEN_TEXT << BOLD_TEXT << filename << RESET_FORMAT << GREEN_TEXT
			  << " was created/updated succesfully!" << RESET_FORMAT << std::endl;
	return 0;
}