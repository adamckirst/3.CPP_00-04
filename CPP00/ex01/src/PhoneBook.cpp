/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achien-k <achien-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:06:47 by achien-k          #+#    #+#             */
/*   Updated: 2024/08/22 16:08:56 by achien-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

// Canonical form
PhoneBook::PhoneBook() {}

PhoneBook::PhoneBook(const PhoneBook &other)
{
  for (int i = 0; i < 8; ++i)
  {
    contact_[i] = other.contact_[i];
  }
  password_ = other.password_;
}

PhoneBook &PhoneBook::operator=(const PhoneBook &other)
{
  if (this != &other)
  {
    for (int i = 0; i < 8; ++i)
    {
      contact_[i] = other.contact_[i];
    }
    password_ = other.password_;
  }
  return *this;
}

PhoneBook::~PhoneBook() {}

// Methods
static void prompt_data(std::string *data, std::string prompt)
{
  std::cout << "Enter " << prompt << ": ";
  getline(std::cin, *data);
  while (*data == "")
  {
    std::cerr << "\033[1m\033[31mError: \033[0m" << prompt
              << " cannot be empty. Please try again." << std::endl;
    getline(std::cin, *data);
  }
}

Contact *PhoneBook::newContact()
{
  std::string name, last, nick, phone, secret;

  prompt_data(&name, "first name");
  prompt_data(&last, "last name");
  prompt_data(&nick, "nickname");
  prompt_data(&phone, "phone number");
  prompt_data(&secret, "darkest secret");

  Contact *contact = new Contact(name, last, nick, phone);
  contact->setSecret(secret, this->password_);
  std::cout << "Contact added" << std::endl;
  return contact;
}

void PhoneBook::fullPhonebook(int *oldest)
{
  std::string input;
  std::string name = this->contact_[*oldest].getFirstName();

  std::cout << "Phonebook is full.\nThe oldest contact is index " << *oldest
            << ": " << name << ".\nTo replace the oldest contact, type 'yes' or 'no'"
            << std::endl;
  getline(std::cin, input);
  if (input == "yes")
  {
    this->contact_[*oldest] = *this->newContact();
    if (*oldest == 7)
      *oldest = 0;
    else
      (*oldest)++;
  }
  else
    std::cout << "Contact not added." << std::endl;
};

void PhoneBook::secret(Contact contact) const
{
  std::string input;
  std::string output;

  if (this->password_ == "")
  {
    std::cout << "\033[1m\033[31mDarkest Secret: \033[0m"
              << contact.getSecret("") << std::endl;
    return;
  }
  std::cout << "Enter the password to see the darkest secret or type BACK"
            << std::endl;
  while (input != "BACK")
  {
    getline(std::cin, input);
    if (input == "BACK")
      return;
    output = contact.getSecret(input);
    if (output == "Invalid password.")
    {
      std::cout << output << " Try again or type BACK" << std::endl;
      continue;
    }
    std::cout << "\033[1m\033[31mDarkest Secret: \033[0m" << output
              << std::endl;
    return;
  }
}

void PhoneBook::printContact(Contact contact) const
{
  std::cout << "\n\033[1m\033[36mFirst Name: \033[0m" << contact.getFirstName()
            << std::endl;
  std::cout << "\033[1m\033[36mLast Name: \033[0m" << contact.getLastName()
            << std::endl;
  std::cout << "\033[1m\033[36mNickname: \033[0m" << contact.getNickname()
            << std::endl;
  std::cout << "\033[1m\033[36mPhone Number: \033[0m"
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

void PhoneBook::printList() const
{
  this->printHeader();
  for (int i = 0; i < 8; i++)
  {
    if (!contact_[i].getFirstName().empty())
    {
      std::cout << std::setw(10) << i << "|";
      if (contact_[i].getFirstName().length() > 10)
        std::cout.write(contact_[i].getFirstName().c_str(), 9) << "." << "|";
      else
        std::cout << std::setw(10) << contact_[i].getFirstName() << "|";
      if (contact_[i].getLastName().length() > 10)
        std::cout.write(contact_[i].getLastName().c_str(), 9) << "." << "|";
      else
        std::cout << std::setw(10) << contact_[i].getLastName() << "|";
      if (contact_[i].getNickname().length() > 10)
        std::cout.write(contact_[i].getNickname().c_str(), 9) << ".";
      else
        std::cout << std::setw(10) << contact_[i].getNickname();
      std::cout << std::endl;
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
  static int oldest = 0;

  for (int i = 0; i < 8; i++)
  {
    while (!this->contact_[i].getFirstName().empty())
    {
      if (i++ == 7)
      {
        this->fullPhonebook(&oldest);
        return;
      }
    }
    this->contact_[i] = *this->newContact();
    return;
  }
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
  getline(std::cin, input);
  if (input.length() == 1 && input[0] >= '0' && input[0] <= '7' &&
      !contact_[input[0] - '0'].getFirstName().empty())
    this->printContact(contact_[input[0] - '0']);
  else
  {
    std::cout << "\033[1m\033[31mInvalid input. Try again.\033[0m" << std::endl
              << std::endl;
    this->search();
  }
}