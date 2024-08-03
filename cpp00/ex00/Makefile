
NAME = megaphone
CXX  = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC  = megaphone.cpp

OBJ = $(SRC:.cpp=.o)

%.o: %.c $(SRC)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME) $(OBJ)

re: fclean all

.PHONY: all re clean fclean