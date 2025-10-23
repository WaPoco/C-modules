NAME=Violance
CCXX=c++ -Wall -Wextra -Werror -std=c++98
SRC=main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJ=main.o HumanA.o HumanB.o Weapon.o

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