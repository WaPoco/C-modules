#include "PhoneBook.hpp"
#include <iostream>

void	SEARCH(PhoneBook *book)
{
	std::string	index;
    int         index_nb;

	book->display_book();
	std::cout << "Enter index(0 until 9):";
    std::cin >> index;
    while (true)
    {
        if (index.size() == 1 && '0' <= index.c_str()[0] && index.c_str()[0] <= '9')
        {
            index_nb = std::atoi(index.c_str());
            break ;
        }
        std::cout << "Invalid input." << std::endl; 
        std::cout << "Please enter a valid integer:";
        std::cin >> index;
    }
	if (0 <= index_nb && index_nb < book->get_count())
	{
		std::cout << "First Name:" << book->contact[index_nb].first_name << "\n";
		std::cout << "Last Name:" << book->contact[index_nb].last_name << "\n";
		std::cout << "Nickname:" << book->contact[index_nb].nickname << "\n";
		std::cout << "Phone number:" << book->contact[index_nb].phone_number << "\n";
		std::cout << "Darkest secret:" << book->contact[index_nb].darkest_secret << "\n";
	}
	else
		std::cout << "No entry\n";
}

void	ADD(PhoneBook *book)
{
	std::string 	input[5] = {{0}};
	std::string		output[5] = {"First Name:", "Last Name:", "Nickname:", "Phone Number:", "Darkest secret:"};
	
	for(int i = 0; i < 5; i++)
	{
		std::cout << output[i]; 
        if (i == 0)
            std::cin.ignore();
		std::getline(std::cin, input[i]);
	}
	book->add(input);
}


int	main(void)
{
	PhoneBook		myBook;
	std::string		command;

	do
	{
		std::cout << "Enter command (ADD, SEARCH or EXIT): ";
		std::cin >> command;
		if (command == "ADD")
			ADD(&myBook);
		else if (command == "SEARCH")
			SEARCH(&myBook);
	} while (command != "EXIT");
	return (1);
}