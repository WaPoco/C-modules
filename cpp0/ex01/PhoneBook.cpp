#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): i(0)
{
}

void	PhoneBook::print(std::string s)
{
	int		len;
	bool	end;

	len = s.size();
	if (len >= 10)
	{
		len = 10;
		end = true;
	}
	for(int i = 0; i < 10; i++)
	{
		if (end == true && i == 9)
			std::cout << '.';
		else if (i >= 10 - len)
			std::cout << s.at(i - 10 + len);
		else
			std::cout << " ";
	}
}

void	PhoneBook::display_book()
{
	int	count;

	count = get_count();
	std::cout << "index     " << "|" << "first name" << "|" << "last name " << "|" << "nickname  " << std::endl;
	for (int i = 0; i < count; i++)
	{
		std::cout <<  i << "         ";
		std::cout << "|";
		print(contact[i].first_name);
		std::cout << "|";
		print(contact[i].last_name);
		std::cout << "|";
		print(contact[i].nickname);
		std::cout <<  "\n";
	}
}

void	PhoneBook::add(std::string *input)
{
	int	index;

	index = get_count();
	if (index == 8)
	{
		decrease_count();
		index = 7;
	}
	contact[index].first_name = input[0];
	contact[index].last_name = input[1] ;
	contact[index].nickname = input[2];
	contact[index].phone_number = input[3];
	contact[index].darkest_secret = input[4];
	increase_count();
}

