##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## CPD10ysk01
##

SRC	=	malloc.c	\
		list.c

TEST	=
OBJ	=	$(SRC:.c=.o)

NAME	=	 libmy_malloc.so

UNIT_TEST   =	unit_tests

CFLAGS	=	-Wall -Wextra -fpic -ggdb -g3

FDFLAGS	=	$(CFLAGS) -lcriterion --coverage

LIB	=	

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -shared -o $(NAME) $(OBJ)

tests_run:
		gcc -o $(UNIT_TEST) $(TEST) $(LIB) $(FDFLAGS)
		./unit_tests

clean:
		rm -f $(OBJ)
		rm -rf	*.gc*

fclean:	clean
		rm -f $(NAME)
		rm -f $(UNIT_TEST)

re: fclean all


.PHONY:		all tests_run clean fclean re