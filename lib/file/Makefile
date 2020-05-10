##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make file to compile
##

RM	=	rm -f

CC	=	gcc

SRC 	=	fill_file.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libfile.a

MY_NAME	=	file.h

all:	$(NAME)


$(NAME):	$(OBJ)
		$(CC) -I./ -c $(SRC) && ar rc $(NAME) $(OBJ)
		mv $(NAME) ..

clean:
		$(RM) $(OBJ) $(NAME)

fclean: 	clean
		$(RM) $(NAME) *.gc*
		$(RM) ../$(NAME)

re:	fclean all
