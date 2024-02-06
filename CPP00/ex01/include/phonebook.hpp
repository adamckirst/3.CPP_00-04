#pragma once
#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
private:
    std::string darkestSecret;

public:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;

    void setSecret(std::string secret) {darkestSecret = secret;};
    void showSecret() const {std::cout << darkestSecret << std::endl;};
};

class PhoneBook
{
private:
    Contact contact[8];

    Contact *newContact();
    void    fullPhonebook(int *oldest);
    void    printContact(Contact contact) const;
    void    printHeader() const;
    void    printList() const;

public:
    void add();
    void search() const;
};