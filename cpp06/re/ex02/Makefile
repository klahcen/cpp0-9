NAME = identify

CXX      = c++

CXXFLAGS = -std=c++98  -Wall -Wextra -Werror  

SRC  = A.cpp C.cpp B.cpp Base.cpp main.cpp
 
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