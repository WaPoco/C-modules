NAME=myPhoneBook
CCXX=c++ -Wall -Wextra -Werror -std=c++98
SRC=PhoneBook.cpp main.cpp
OBJ=PhoneBook.o main.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CCXX) $(OBJ) -o $(NAME)

%.o: %.cpp
	 $(CCXX) -c $< -o $@
 
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
