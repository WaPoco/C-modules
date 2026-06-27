NAME=FragTrap
CCXX=c++ -Wall -Wextra -Werror -std=c++98
SRC=ClapTrap.cpp main.cpp ScavTrap.cpp FragTrap.cpp
OBJ=ClapTrap.o main.o ScavTrap.o FragTrap.o

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