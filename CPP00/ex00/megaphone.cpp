/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:18:55 by achien-k          #+#    #+#             */
/*   Updated: 2023/09/28 12:29:27 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

static void	print_upper(char *str)
{
	unsigned char c;

	while (*str)
	{
		c = static_cast<unsigned char>(*str++);
		std::cout << static_cast<char>(toupper(c));
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		while (*++argv)
			print_upper(*argv);
		std::cout << std::endl;
	}
	return (0);
}
