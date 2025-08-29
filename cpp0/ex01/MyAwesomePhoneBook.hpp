#include <iostream>

class Contact
{
	public:
		char	first_name[10] = {0};
		char	last_name[10] = {0};
		char	nickname[10] = {0};
		char	phone_number[10] = {0};
		char	darkest_secret[10] = {0};

};

class PhoneBook
{
	int		i;
	public:
		PhoneBook (int);
		Contact conctact[8];
		void	increase_count() {i++;}
		void	decrease_count() {i--;}
		int		get_count() {return (i);}
		void	add(char *first_name, char *last_name, char	*nickname, char	*phone_number, char	*darkest_secret);
		void	display_book();
};