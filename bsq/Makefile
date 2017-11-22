# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpop <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/25 02:05:19 by gpop              #+#    #+#              #
#    Updated: 2017/08/02 20:11:05 by gpop             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SOURCE_DIR = srcs/
HEADER_DIR = includes/
FUNCTIONS = bsq_memory bsq display ft_atoi ft_file ft_utility validator
FLAGS = -Wall -Wextra -Werror
MAIN = main.c

.PHONY: all clean fclean re

all:
	@gcc -I $(HEADER_DIR) $(FLAGS) -c $(patsubst %,$(SOURCE_DIR)%.c,$(FUNCTIONS)) 
	@gcc -I $(HEADER_DIR) $(FLAGS) $(patsubst %,%.o,$(FUNCTIONS)) $(MAIN) -o $(NAME)

clean:
	@rm -f $(patsubst %,%.o,$(FUNCTIONS))

fclean: clean
	@rm -f $(NAME)

re: fclean all
