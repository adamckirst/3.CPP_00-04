/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:06:47 by achien-k          #+#    #+#             */
/*   Updated: 2024/08/27 16:55:38 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"
#include "../include/helpers.hpp"

// Canonical form
PhoneBook::PhoneBook() : oldest_(0) {}

PhoneBook::PhoneBook(const PhoneBook &other)
{
  for (int i = 0; i < 8; ++i)
    contact_[i] = other.contact_[i];
  password_ = other.password_;
}

PhoneBook &PhoneBook::operator=(const PhoneBook &other)
{
  if (this == &other)
    return *this;
  for (int i = 0; i < 8; ++i)
    contact_[i] = other.contact_[i];
  password_ = other.password_;
  return *this;
}

PhoneBook::~PhoneBook() {}

// Methods
static void prompt_data(std::string &data, std::string prompt)
{
  std::cout << "Enter " << prompt << ": ";
  ft_getline(data);
  while (data == "")
  {
    std::cerr << BOLD_TEXT << RED_TEXT << "Error: " << RESET_FORMAT << prompt
              << " cannot be empty. Please try again." << std::endl;
    ft_getline(data);
  }
}

Contact PhoneBook::newContact()
{
  std::string name, last, nick, phone, secret;

  prompt_data(name, "first name");
  prompt_data(last, "last name");
  prompt_data(nick, "nickname");
  prompt_data(phone, "phone number");
  prompt_data(secret, "darkest secret");

  Contact contact = Contact(name, last, nick, phone);
  contact.setSecret(secret, this->password_);
  std::cout << "Contact added" << std::endl;
  return contact;
}

void PhoneBook::secret(Contact contact) const
{
  std::string input;
  std::string output;

  if (this->password_ == "")
  {
    std::cout << BOLD_TEXT << RED_TEXT << "Darkest Secret: " << RESET_FORMAT
              << contact.getSecret("") << std::endl;
    return;
  }
  std::cout << "Enter the password to see the darkest secret or type BACK"
            << std::endl;
  while (input != "BACK")
  {
    ft_getline(input);
    if (input == "BACK")
      return;
    output = contact.getSecret(input);
    if (output == "Invalid password.")
    {
      std::cout << output << " Try again or type BACK" << std::endl;
      continue;
    }
    std::cout << BOLD_TEXT << RED_TEXT << "Darkest Secret: " << RESET_FORMAT << output
              << std::endl;
    return;
  }
}

void PhoneBook::printContact(Contact contact) const
{
  std::cout << "\n\033[1m\033[36mFirst Name: " << RESET_FORMAT << contact.getFirstName()
            << std::endl;
  std::cout << BOLD_TEXT << "\033[36mLast Name: " << RESET_FORMAT << contact.getLastName()
            << std::endl;
  std::cout << BOLD_TEXT << "\033[36mNickname: " << RESET_FORMAT << contact.getNickname()
            << std::endl;
  std::cout << BOLD_TEXT << "\033[36mPhone Number: " << RESET_FORMAT
            << contact.getPhoneNumber() << std::endl;
  this->secret(contact);
  std::cout << std::endl;
}

void PhoneBook::printHeader() const
{
  std::cout << std::setw(10) << "Index" << "|";
  std::cout << std::setw(10) << "First Name" << "|";
  std::cout << std::setw(10) << "Last Name" << "|";
  std::cout << std::setw(10) << "Nickname" << std::endl;
}

static std::string formatName(std::string name)
{
  if (name.length() > 10)
    return name.substr(0, 9) + ".";
  return name;
}

void PhoneBook::printList() const
{
  this->printHeader();
  for (int i = 0; i < 8; i++)
  {
    if (!contact_[i].getFirstName().empty())
    {
      std::cout << std::setw(10) << i << "|";
      std::cout << std::setw(10) << formatName(contact_[i].getFirstName()) << "|";
      std::cout << std::setw(10) << formatName(contact_[i].getLastName()) << "|";
      std::cout << std::setw(10) << formatName(contact_[i].getNickname()) << std::endl;
    }
  }
}

bool PhoneBook::setPassword(std::string pw)
{
  if (pw == "Invalid Password.")
    return false;
  else
  {
    this->password_ = pw;
    return true;
  }
}

void PhoneBook::add()
{
  this->contact_[this->oldest_++ % 8] = this->newContact();
}

void PhoneBook::search() const
{
  std::string input;

  if (contact_[0].getFirstName().empty())
  {
    std::cout << "Phonebook is empty.\n"
              << std::endl;
    return;
  }
  this->printList();
  std::cout << "Enter the index of the contact you want to see" << std::endl;
  ft_getline(input);
  if (input.length() == 1 && input[0] >= '0' && input[0] <= '7' &&
      !contact_[input[0] - '0'].getFirstName().empty())
    this->printContact(contact_[input[0] - '0']);
  else
  {
    std::cout << BOLD_TEXT << RED_TEXT << "Invalid input. Try again." << RESET_FORMAT << std::endl
              << std::endl;
    this->search();
  }
}