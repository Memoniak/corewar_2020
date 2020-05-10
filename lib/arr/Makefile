##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make file to compile
##

RM	=	rm -f

CC	=	gcc

SRC 	=	get_dbl_arr_len.c		\
			get_string_op.c			\
			parser_w_sep.c			\
			my_memset.c				\
			remove_spaces.c			\
			copy_from.c				\
			get_word_pos_arr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libarr.a

MY_NAME	=	arr.h

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
