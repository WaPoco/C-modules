NAME=ZombieHorde
CCXX=c++ -Wall -Wextra -Werror -std=c++98
SRC=Zombie.cpp main.cpp zombieHorde.cpp
OBJ=Zombie.o main.o zombieHorde.o

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