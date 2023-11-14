# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/28 09:00:00 by feliciencat       #+#    #+#              #
#    Updated: 2023/10/23 22:21:38 by feliciencat      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrat3
SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
HDR = Bureaucrat.hpp AForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp ShrubberyCreationForm.hpp
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC) $(HDR)
	g++ $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all
