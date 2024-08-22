/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:01:45 by achien-k          #+#    #+#             */
/*   Updated: 2024/08/22 16:06:19 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"

// Canonical form
Contact::Contact() {}

Contact::Contact(std::string first, std::string last, std::string nick, std::string phone)
    : firstName_(first), lastName_(last), nickname_(nick), phoneNumber_(phone) {}

Contact::Contact(const Contact &other)
    : darkestSecret_(other.darkestSecret_),
      pw_(other.pw_),
      firstName_(other.firstName_),
      lastName_(other.lastName_),
      nickname_(other.nickname_),
      phoneNumber_(other.phoneNumber_) {}

Contact &Contact::operator=(const Contact &other)
{
    if (this != &other)
    {
        darkestSecret_ = other.darkestSecret_;
        pw_ = other.pw_;
        firstName_ = other.firstName_;
        lastName_ = other.lastName_;
        nickname_ = other.nickname_;
        phoneNumber_ = other.phoneNumber_;
    }
    return *this;
}

Contact::~Contact() {}

// Methods
void Contact::setSecret(std::string secret, std::string pw)
{
    this->darkestSecret_ = secret;
    this->pw_ = pw;
}

std::string Contact::getFirstName() const
{
    return this->firstName_;
}

std::string Contact::getLastName() const
{
    return this->lastName_;
}

std::string Contact::getNickname() const
{
    return this->nickname_;
}

std::string Contact::getPhoneNumber() const
{
    return this->phoneNumber_;
}

std::string Contact::getSecret(std::string pw) const
{
    if (pw == this->pw_)
    {
        return this->darkestSecret_;
    }
    return "Invalid password.";
}
