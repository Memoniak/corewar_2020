##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make file to compile
##

RM	=	rm -f

CC	=	gcc

SRC 	=	concat_params.c			\
		copy_rr.c			\
		free_rr.c			\
		my_compute_power_rec.c		\
		my_compute_square_root.c	\
		my_find_prime_sup.c		\
		my_isneg.c			\
		my_is_prime.c			\
		my_show_word_array.c		\
		my_sort_int_array.c		\
		my_strcapitalize.c		\
		my_strcat_pimp.c		\
		my_str_isalpha.c		\
		my_str_islower.c		\
		my_str_isnum.c			\
		my_str_isprintable.c		\
		my_str_isupper.c		\
		my_strlowcase.c			\
		my_str_to_word_array.c		\
		my_strstr.c			\
		my_strupcase.c			\
		my_strncmp.c			\
		my_strncpy.c			\
		my_strdup.c			\
		my_strcmp.c			\
		is_num.c			

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

MY_NAME	=	my.h

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
