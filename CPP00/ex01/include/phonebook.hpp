#pragma once
#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
private:
    std::string darkestSecret_;
    std::string pw;

public:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;

    Contact() {};
    Contact(std::string first, std::string last, std::string nick, std::string phone);

    void setSecret(std::string secret, std::string pw) {this->darkestSecret_ = secret; this->pw = pw;};
    void setPw(std::string pw) {this->pw = pw;};
    int showSecret(std::string pw) const;
};

class PhoneBook
{
private:
    Contact contact_[8];

    Contact *newContact();
    void    fullPhonebook(int *oldest);
    void    printContact(Contact contact) const;
    void    printHeader() const;
    void    printList() const;

public:
    std::string password;

    void    add();
    void    search() const;
    void    secret(Contact contact) const;
};