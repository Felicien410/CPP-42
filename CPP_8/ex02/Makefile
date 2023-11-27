# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/28 09:00:00 by feliciencat       #+#    #+#              #
#    Updated: 2023/11/25 21:04:41 by feliciencat      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Stack
SRC = main.cpp
HDR = Mutanstack.hpp

FLAGS = -Wall -Wextra -Werror -std=c++98

GREEN = \033[0;32m
RED = \033[0;31m

all: $(NAME)

$(NAME): $(SRC) $(HDR)
	@echo "$(GREEN)Compiling $(NAME)..."
	@clang++ $(FLAGS) $(SRC) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled !"
	
clean:
	@echo "$(RED)Cleaning $(NAME)..."
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) cleaned !"

fclean: clean

re: fclean all

.PHONY: all clean fclean re
