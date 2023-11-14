# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 09:34:40 by feliciencat       #+#    #+#              #
#    Updated: 2023/09/29 12:26:34 by feliciencat      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FixedNumbers
SRC = main.cpp Fixed.cpp
HDR = Fixed.hpp
FLAGS = -Wall -Wextra -Werror -std=c++98
all: $(NAME)

$(NAME): $(SRC) $(HDR)
	g++ $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all
