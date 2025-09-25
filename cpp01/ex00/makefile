NAME=Zombie
CC=c++ -Wall -Wextra -Werror -std=c++98
SRC=Zombie.cpp main.cpp
OBJ=Zombie.o main.o

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