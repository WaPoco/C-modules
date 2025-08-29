#include "MyAwesomePhoneBook.hpp"

PhoneBook::PhoneBook(int count)
{
	i = count;
}

void	assign(char *value, char *variable)
{
	int	i;

	i = 0;
	while (i <= 9)
	{
		variable[i] = value[i];
		i++;
	}
	variable[i] = '\0';
}

void	print(char s[])
{
	int		len;
	bool	end;

	len = 0;
	while (s[len])
		len++;
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
			std::cout << s[i - 10 + len];
		else
			std::cout << " ";
	}
}

void	PhoneBook::display_book()
{
	int	count;

	count = get_count();
	std::cout << "index     " << "|" << "first name" << "|" << "last name " << "|" << "nickname  \n";
	for (int i = 0; i < count; i++)
	{
		std::cout <<  i << "         ";
		std::cout << "|";
		print(conctact[i].first_name);
		std::cout << "|";
		print(conctact[i].last_name);
		std::cout << "|";
		print(conctact[i].nickname);
		std::cout <<  "\n";
	}
}

void	PhoneBook::add(char	*first_name, char *last_name, char	*nickname, char	*phone_number, char	*darkest_secret)
{
	int	index;

	index = get_count();
	if (index == 8)
	{
		decrease_count();
		index = 7;
	}
	assign(first_name, conctact[index].first_name);
	assign(last_name, conctact[index].last_name);
	assign(nickname, conctact[index].nickname);
	assign(phone_number, conctact[index].phone_number);
	assign(darkest_secret, conctact[index].darkest_secret);
	increase_count();
}

int	comp(char *command, const char *input)
{
	while (*command && *input && *command == *input)
	{
		command++;
		input++;
	}
	return (*command - *input);
}

void	SEARCH(PhoneBook *book)
{
	int	index;

	book->display_book();
	std::cout << "Enter index:";
	std::cin >> index;
	if (0 <= index && index < book->get_count())
	{
		std::cout << "First Name:" << book->conctact[index].first_name << "\n";
		std::cout << "Last Name:" << book->conctact[index].last_name << "\n";
		std::cout << "Nickname:" << book->conctact[index].nickname << "\n";
		std::cout << "Phone number:" << book->conctact[index].phone_number << "\n";
		std::cout << "Darkest secret:" << book->conctact[index].darkest_secret << "\n";
	}
	else
		std::cout << "No entry\n";
	std::cout << "\n";
}

void	ADD(PhoneBook *book)
{
	char 	input[5][256];
	
	for(int i = 0; i < 5; i++)
	{
		if (i == 0)
			std::cout << "First Name:";
		else if (i == 1)
			std::cout << "Last Name:";
		else if (i == 2)
			std::cout << "Nickname:";
		else if (i == 3)
			std::cout << "Phone Number:";
		else if (i == 4)
			std::cout << "Darkest secret:";
		std::cin >> input[i]; 
	}
	book->add(input[0], input[1], input[2], input[3], input[4]);
}

int	main(void)
{
	PhoneBook	myBook (0);
	char		command[7] = {0};
	char		*input;

	do
	{
		std::cout << "Enter command (ADD, SEARCH or EXIT): ";
		std::cin >> command;
		if (comp(command, "ADD") == 0)
			ADD(&myBook);
		else if (comp(command, "SEARCH") == 0)
			SEARCH(&myBook);
	} while (comp(command, "EXIT") != 0);
	return (1);
}
