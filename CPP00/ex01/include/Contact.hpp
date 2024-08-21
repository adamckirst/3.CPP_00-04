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

    Contact();
    Contact(std::string first, std::string last, std::string nick, std::string phone);

    void setSecret(std::string secret, std::string pw);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getSecret(std::string pw) const;
};