##
## EPITECH PROJECT, 2019
## my_ls
## File description:
## Main Makefile
##

MAIN = src/main.c
OBJ = $(notdir $(MAIN:.c=.o))

I_PATH = include/
FLAGS = -Wall -Wextra

NAME = my_ls

all: $(NAME)

$(NAME) : $(OBJ)
	gcc -o $(NAME) $(OBJ) $(FLAGS)

$(OBJ):
	gcc -c $(MAIN) -I$(INCLUDE) $(FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
