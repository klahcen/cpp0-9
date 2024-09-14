NAME = ex00

CXX      = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98  

SRC  = Bureaucrat.cpp  main.cpp

OBJ = $(SRC:.cpp=.o)

%.o: %.c $(SRC)
	$(CXX) -c -o   $@ $< $(CFLAGS)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS)   $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME) $(OBJ)

re: fclean all clean

.PHONY: all re clean fclean