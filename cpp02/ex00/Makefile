NAME = a.out

CXX      = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98  

SRC  = main.cpp Fixed.cpp 

OBJ = $(SRC:.cpp=.o)

%.o: %.c $(SRC)
	$(CXX) -c -o   $@ $< $(CFLAGS)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS)  -fsanitize=address -g3 $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME) $(OBJ)

re: fclean all 

.PHONY: all re clean fclean
