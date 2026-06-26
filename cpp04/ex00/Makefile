NAME=Animal
CCXX=c++ -Wall -Wextra -Werror -std=c++98
SRC=Animal.cpp main.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp
OBJ=Animal.o main.o Cat.o Dog.o WrongAnimal.o WrongCat.o

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