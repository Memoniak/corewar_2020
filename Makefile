##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile my_screensaver
##

SRC	=	src/op.c \
		src/check_command.c \
		src/check_type_arg.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	./ass

C_FLAGS = -Wall -Wextra

all:	$(NAME)

$(NAME):
	 make -C lib/my
	 gcc $(C_FLAGS) $(SRC) -o $(NAME) -I./include -L./lib -lmy

clean:
	rm -f *.o

fclean:
	make fclean  -C lib/my/
	rm -rf *.o
	rm -rf $(NAME)

re: fclean all
