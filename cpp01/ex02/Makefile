NAME = ex02

CXX      = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 

SRC  = main.cpp

OBJ = $(SRC:.cpp=.o)

%.o: %.c $(SRC)
	$(CXX) -c -o $@ $< $(CFLAGS)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME) $(OBJ)

re: fclean all

.PHONY: all re clean fclean