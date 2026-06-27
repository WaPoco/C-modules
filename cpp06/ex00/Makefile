NAME = converter

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = converters.cpp main.cpp ScalarConverter.cpp which_type.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re