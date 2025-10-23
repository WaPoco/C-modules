NAME=Zombie
CCXX=c++ -Wall -Wextra -Werror -std=c++98
SRC=Zombie.cpp main.cpp newZombie.cpp randomChump.cpp 
OBJ=Zombie.o main.o newZombie.o randomChump.o

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