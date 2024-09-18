/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:12:13 by achien-k          #+#    #+#             */
/*   Updated: 2024/09/18 11:52:11 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

Brain::Brain()
{
	std::cout << GREEN_TEXT << "Brain constructor called" << RESET_FORMAT << std::endl;
}

Brain::Brain(const Brain &other)
{
	for (size_t i = 0; i < 100; i++)
		ideas_[i] = other.ideas_[i];
	std::cout << GREEN_TEXT << "Brain copy constructor called" << RESET_FORMAT << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		std::cout << GREEN_TEXT << "Brain assigned" << RESET_FORMAT << std::endl;
		for (size_t i = 0; i < 100; i++)
			ideas_[i] = other.ideas_[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << RED_TEXT << "Brain destructor called" << RESET_FORMAT << std::endl;
}

void Brain::setIdea(size_t index, std::string idea)
{
	if (index < 100)
		ideas_[index] = idea;
}

std::string Brain::getIdea(size_t index)
{
	if (index < 100)
		return ideas_[index];
	else
		return NULL;
}