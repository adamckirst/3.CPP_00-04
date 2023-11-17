#pragma once
#include <iostream>

class Contact
{
    private:
        string	darkestSecret;

    public:
        string	firstName;
        string	lastName;
        string	nickname;
        string  phoneNumber;
}

class PhoneBook
{
    private:

    public:
            Add(Contact contact);
        Search();
}
