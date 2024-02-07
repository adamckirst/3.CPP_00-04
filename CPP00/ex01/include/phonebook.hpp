#pragma once
#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
private:
    std::string darkestSecret_;
    std::string pw_;
    std::string firstName_;
    std::string lastName_;
    std::string nickname_;
    std::string phoneNumber_;

public:

    Contact() {};
    Contact(std::string first, std::string last, std::string nick, std::string phone);

    void setSecret(std::string secret, std::string pw) {this->darkestSecret_ = secret; this->pw_ = pw;};

    std::string getFirstName() const {return this->firstName_;};
    std::string getLastName() const {return this->lastName_;};
    std::string getNickname() const {return this->nickname_;};
    std::string getPhoneNumber() const {return this->phoneNumber_;};
    std::string getSecret(std::string pw) const;
};

class PhoneBook
{
private:
    Contact contact_[8];
    std::string password_;

    Contact *newContact();
    void    fullPhonebook(int *oldest);
    void    printContact(Contact contact) const;
    void    printHeader() const;
    void    printList() const;

public:

	bool setPassword(std::string pw) {if (pw == "Invalid Password.") return false; else {this->password_ = pw; return true;}};
    void    add();
    void    search() const;
    void    secret(Contact contact) const;
};