# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 09:34:40 by feliciencat       #+#    #+#              #
#    Updated: 2023/09/29 12:26:03 by feliciencat      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Zombie
SRC = main.cpp Zombie.cpp zombieHorde.cpp
HDR = Zombie.hpp
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC) $(HDR)
	g++ $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all
