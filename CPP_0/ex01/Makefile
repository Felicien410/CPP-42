NAME = Phonebook
SRC = main.cpp Contact.cpp Phonebook.cpp utils.cpp
HDR = Contact.hpp Phonebook.hpp utils.hpp
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC) $(HDR)
	g++ $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all
