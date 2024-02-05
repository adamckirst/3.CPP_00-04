#pragma once
#include <iostream>
#include <string>

class Contact
{
private:
    std::string darkestSecret;

public:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;

    void setSecret(std::string secret)
    {
        darkestSecret = secret;
    };
    void showSecret()
    {
        std::cout << darkestSecret << std::endl;
    };
};

class PhoneBook
{
private:
    Contact contact[8];
    void    fullPhonebook(Contact *contact, int oldest)
    {
        std::string input;

        std::cout << "Phonebook is full, to replace the oldest contact, type 'yes' or 'no' to cancel" << std::endl;
        getline(std::cin, input);
        if (input == "yes")
        {
            this->contact[oldest] = *contact;
            return;
        }
        else
        {
            std::cout << "Contact not added" << std::endl;
            return;
        }
    };

public:
    PhoneBook()
    {
        for (int i = 0; i < 8; i++)
        {
            this->contact[i].firstName = "";
            this->contact[i].lastName = "";
            this->contact[i].nickname = "";
            this->contact[i].phoneNumber = "";
        }
    };
    void add(Contact *contact)
    {	
        static int oldest = 0;

        for (int i = 0; i < 8; i++)
        {
            if (this->contact[i].firstName.empty())
            {
                this->contact[i] = *contact;
                oldest = i;
                return;
            }
            if (i == 7)
            {
                this->fullPhonebook(contact, oldest);
                if (oldest == 7)
                    oldest = 0;
                else
                    oldest++;
            }
        }
    };
    // void search();
};

