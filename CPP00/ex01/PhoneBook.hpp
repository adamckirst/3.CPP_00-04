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

    void setSecret(std::string secret) {
        darkestSecret = secret;
    };
    void showSecret() {
        std::cout << darkestSecret << std::endl;
    };
};

class PhoneBook
{
private:
    Contact contact[8];
    Contact	*getContact() {
        Contact *contact = new Contact();
        std::string input;

        std::cout << contact->lastName << std::endl;
        std::cout << "Enter first name: ";
        while (!getline(std::cin, contact->firstName))
            std::cout << "Error" << std::endl;
        std::cout << "Enter last name: ";
        while (!getline(std::cin, contact->lastName))
            std::cout << "Error" << std::endl;
        std::cout << "Enter nickname: ";
        while (!getline(std::cin, contact->nickname))
            std::cout << "Error" << std::endl;
        std::cout << "Enter phone number: ";
        while (!getline(std::cin, contact->phoneNumber))
            std::cout << "Error" << std::endl;
        std::cout << "Enter darkest secret: ";
        while (!getline(std::cin, input))
            std::cout << "Error" << std::endl;
        contact->setSecret(input);
        std::cout << "Contact added" << std::endl;
        return contact;
    }

    void    fullPhonebook(int *oldest) {
        std::string input;

        std::cout << "Phonebook is full.\nThe oldest contact is " << *oldest \
        << ".\nTo replace the oldest contact, type 'yes' or 'no'" << std::endl;
        getline(std::cin, input);
        if (input == "yes")
        {
            this->contact[*oldest] = *this->getContact();
            if (*oldest == 7)
                *oldest = 0;
            else
                (*oldest)++;
        }
        else
            std::cout << "Contact not added" << std::endl;
    };
    void    printContact(Contact contact) {
        std::cout << "\n\033[1m\033[36mFirst Name: \033[0m" << contact.firstName << std::endl;
        std::cout << "\033[1m\033[36mLast Name: \033[0m" << contact.lastName << std::endl;
        std::cout << "\033[1m\033[36mNickname: \033[0m" << contact.nickname << std::endl;
        std::cout << "\033[1m\033[36mPhone Number: \033[0m" << contact.phoneNumber << std::endl;
        std::cout << "\033[1m\033[31mDarkest Secret: \033[0m";
        contact.showSecret();
        std::cout << std::endl;
    }

    void printHeader() {
        std::cout << std::setw(10) << "Index" << "|";
        std::cout << std::setw(10) << "First Name" << "|";
        std::cout << std::setw(10) << "Last Name" << "|";
        std::cout << std::setw(10) << "Nickname" << std::endl;
    }
    void    printList() {
        this->printHeader();
        for (int i = 0; i < 8; i++)
        {
            if (!contact[i].firstName.empty())
            {
                std::cout << std::setw(10) << i << "|";
                if (contact[i].firstName.length() > 10)
                    std::cout.write(contact[i].firstName.c_str(), 9) << "." << "|";
                else
                    std::cout << std::setw(10) << contact[i].firstName << "|";
                if (contact[i].lastName.length() > 10)
                    std::cout.write(contact[i].lastName.c_str(), 9) << "." << "|";
                else
                    std::cout << std::setw(10) << contact[i].lastName << "|";
                if (contact[i].nickname.length() > 10)
                    std::cout.write(contact[i].nickname.c_str(), 9) << ".";
                else
                    std::cout << std::setw(10) << contact[i].nickname;
                std::cout << std::endl;
            }
        }
    }
public:
    void add() {	
        static int oldest = 0;

        for (int i = 0; i < 8; i++)
        {
            while (!this->contact[i].firstName.empty())
            {
                if (i++ == 7)
                {
                    this->fullPhonebook(&oldest);
                    return;
                }
            }
            this->contact[i] = *this->getContact();
            oldest = i;
            return;
        }
    };
    void search() {
        std::string input;

        if (contact[0].firstName.empty())
        {
            std::cout << "Phonebook is empty.\n" << std::endl;
            return;
        }
        this->printList();
        std::cout << "Enter the index of the contact you want to see" << std::endl;
        getline(std::cin, input);
        if (input.length() == 1 && input[0] >= '0' && input[0] <= '7' && !contact[input[0] - '0'].firstName.empty())
            this->printContact(contact[input[0] - '0']);
        else
            std::cout << "Invalid input" << std::endl;
    }
};