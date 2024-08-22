#pragma once
#include <iomanip>
#include <iostream>
#include <string>

#include "Contact.hpp"

class PhoneBook
{
private:
  Contact contact_[8];
  std::string password_;

  Contact *newContact();
  void fullPhonebook(int *oldest);
  void printContact(Contact contact) const;
  void printHeader() const;
  void printList() const;

public:
  PhoneBook();
  PhoneBook(const PhoneBook &other);
  PhoneBook &operator=(const PhoneBook &other);
  ~PhoneBook();

  bool setPassword(std::string pw);
  void add();
  void search() const;
  void secret(Contact contact) const;
};