#ifndef PHONEBOOK_HPP
# include "Contact.hpp"
# include <iostream>

class PhoneBook
{
	private:
		int		i;
	public:
		PhoneBook();
		Contact contact[8];
		void	increase_count() {i++;}
		void	decrease_count() {i--;}
		int		get_count() {return (i);}
		void	add(std::string *input);
		void	display_book();
		void	print(std::string s);
};
#endif