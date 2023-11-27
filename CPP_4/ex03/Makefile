# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/28 09:00:00 by feliciencat       #+#    #+#              #
#    Updated: 2023/10/02 16:53:26 by feliciencat      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Materia
SRC = AMateria.cpp Cure.cpp Ice.cpp main.cpp Character.cpp MateriaSource.cpp
HDR = AMateria.hpp Cure.hpp ICharacter.hpp Ice.hpp Character.hpp MateriaSource.hpp
FLAGS = #-Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC) $(HDR)
	g++ $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all