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
