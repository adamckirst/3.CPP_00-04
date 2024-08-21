#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

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

	bool    setPassword(std::string pw); 
    void    add();
    void    search() const;
    void    secret(Contact contact) const;
};