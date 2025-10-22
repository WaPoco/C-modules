NAME=Harl
CCXX=c++ -Wall -Wextra -Werror -std=c++98
SRC=Harl.cpp main.cpp
OBJ=Harl.o main.o

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