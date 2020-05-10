##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile my_screensaver
##

SRC	=	src/main.c \
		src/get_label.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	test

C_FLAGS = -Wall -Wextra

all:	$(NAME)

$(NAME):
	 make -C lib/my
	 gcc $(C_FLAGS) $(SRC) -o $(NAME) -I./include -L./lib -lmy

clean:
	$(RM) *.o

fclean:
	make fclean  -C lib/my/
	$(RM) *.o
	$(RM) $(NAME)

re: fclean all
