# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 09:34:40 by feliciencat       #+#    #+#              #
#    Updated: 2023/09/29 12:26:15 by feliciencat      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Human
SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
HDR = Weapon.hpp HumanA.hpp HumanB.hpp
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC) $(HDR)
	g++ $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all
