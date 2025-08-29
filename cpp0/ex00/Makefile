NAME=megaphone
CC=c++ -Wall -Wextra -Werror -std=c++98
SRC=megaphone.cpp
OBJ=megaphone.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	 $(CC) -c $< -o $@
 
clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
