#include "../include/PhoneBook.hpp"
Contact::Contact(std::string name, std::string last, std::string nick, std::string phone) : 
    firstName(name), 
    lastName(last), 
    nickname(nick), 
    phoneNumber(phone) {};

int Contact::showSecret(std::string pw) const {
    if (pw == this->pw)
    {
        std::cout << "\033[1m\033[31mDarkest Secret: \033[0m" << this->darkestSecret_ << std::endl;
        return (0);
    }
    else
        return (1);
};

Contact *PhoneBook::newContact() {
    std::string name, last, nick, phone, secret, pw;

    std::cout << "Enter first name: ";
    while (!getline(std::cin, name))
        std::cout << "Error" << std::endl;
    std::cout << "Enter last name: ";
    while (!getline(std::cin, last))
        std::cout << "Error" << std::endl;
    std::cout << "Enter nickname: ";
    while (!getline(std::cin, nick))
        std::cout << "Error" << std::endl;
    std::cout << "Enter phone number: ";
    while (!getline(std::cin, phone))
        std::cout << "Error" << std::endl;
    std::cout << "Enter darkest secret: ";
    while (!getline(std::cin, secret))
        std::cout << "Error" << std::endl;
    Contact *contact = new Contact(name, last, nick, phone);
    contact->setSecret(secret, this->password);
    std::cout << "Contact added" << std::endl;
    return contact;
}

void    PhoneBook::fullPhonebook(int *oldest) {
    std::string input;

    std::cout << "Phonebook is full.\nThe oldest contact is " << *oldest \
    << ".\nTo replace the oldest contact, type 'yes' or 'no'" << std::endl;
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
        std::cout << "Contact not added" << std::endl;
};
void    PhoneBook::secret(Contact contact) const {
    std::string input;
    std::cout << "\nDo you want to see the darkest secret? (yes/no)" << std::endl;
    getline(std::cin, input);
    if (input != "yes")
        return;
    std::cout << "Enter the password to see the secret or type RETURN" << std::endl;
    while (input != "RETURN")
    {
        getline(std::cin, input);
        if (!contact.showSecret(input))
            return;
        std::cout << "Invalid password. Try again or type RETURN" << std::endl;
    }
}
void    PhoneBook::printContact(Contact contact) const {
    std::cout << "\n\033[1m\033[36mFirst Name: \033[0m" << contact.firstName << std::endl;
    std::cout << "\033[1m\033[36mLast Name: \033[0m" << contact.lastName << std::endl;
    std::cout << "\033[1m\033[36mNickname: \033[0m" << contact.nickname << std::endl;
    std::cout << "\033[1m\033[36mPhone Number: \033[0m" << contact.phoneNumber << std::endl;
    this->secret(contact);
    std::cout << std::endl;
}

void    PhoneBook::printHeader() const {
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;
}
void    PhoneBook::printList() const {
    this->printHeader();
    for (int i = 0; i < 8; i++)
    {
        if (!contact_[i].firstName.empty())
        {
            std::cout << std::setw(10) << i << "|";
            if (contact_[i].firstName.length() > 10)
                std::cout.write(contact_[i].firstName.c_str(), 9) << "." << "|";
            else
                std::cout << std::setw(10) << contact_[i].firstName << "|";
            if (contact_[i].lastName.length() > 10)
                std::cout.write(contact_[i].lastName.c_str(), 9) << "." << "|";
            else
                std::cout << std::setw(10) << contact_[i].lastName << "|";
            if (contact_[i].nickname.length() > 10)
                std::cout.write(contact_[i].nickname.c_str(), 9) << ".";
            else
                std::cout << std::setw(10) << contact_[i].nickname;
            std::cout << std::endl;
        }
    }
}
void    PhoneBook::add() {	
    static int oldest = 0;

    for (int i = 0; i < 8; i++)
    {
        while (!this->contact_[i].firstName.empty())
        {
            if (i++ == 7)
            {
                this->fullPhonebook(&oldest);
                return;
            }
        }
        this->contact_[i] = *this->newContact();
        oldest = i;
        return;
    }
}
void    PhoneBook::search() const {
    std::string input;

    if (contact_[0].firstName.empty())
    {
        std::cout << "Phonebook is empty.\n" << std::endl;
        return;
    }
    this->printList();
    std::cout << "Enter the index of the contact you want to see" << std::endl;
    getline(std::cin, input);
    if (input.length() == 1 && input[0] >= '0' && input[0] <= '7' && !contact_[input[0] - '0'].firstName.empty())
        this->printContact(contact_[input[0] - '0']);
    else
        std::cout << "Invalid input" << std::endl;
}