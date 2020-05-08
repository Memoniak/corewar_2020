## EPITECH PROJECT, 2019
## makefile
## File description:
## makes lib
##

RM	=	rm -f

CC	=	gcc

SRC	=	my_putchar_buff.c			\
		my_strlen.c				\
		my_put_nbr_buff.c			\
		my_putstr_buff.c			\
		conv_octal.c				\
		conv_hex.c				\
		put_nbr_bin.c				\
		my_revstr.c				\
		non_print.c				\
		my_getnbr.c				\
		padded_nb.c				\
		my_strcat.c				\
		conv_hex_c.c				\
		my_putstr.c				\
		my_strdup.c				\
		my_putchar.c				\
		get_nbr_len.c				\
		special_flags.c				\
		my_strcpy.c				\
		init_tables.c				\
		my_printf.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libprint.a

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -I. -c $(SRC) && ar rc $(NAME) $(OBJ)
		mv $(NAME) ..
clean:
		$(RM) $(OBJ) $(NAME)

fclean:		clean
		$(RM) $(EXEC_N) *.gc*
		$(RM) ../$(NAME)

re:		fclean all
