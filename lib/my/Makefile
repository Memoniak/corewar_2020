##
## EPITECH PROJECT, 2019
## makefile
## File description:
## premier makefile
##

RM = rm -f

SRC =	my_strlen.c \
		my_printf.c \
		my_putchar.c \
		my_putstr.c \
		my_put_nbr.c \
		my_getnbr.c \
		my_putbases.c \
		my_revstr.c \
		my_strdup.c \
		my_strncat.c \
		util.c \
		put.c \
		my_strcpy.c \
		bubble_sort_1.c \
		my_str_isnum.c \
		bubble_sort_2.c \
		insertion.c \
		my_show_list.c \
		my_memset.c \
		my_params_to_list.c \
		my_str_to_word_array.c \
		is_num.c \
		my_put_error.c \
		my_strcmp.c \
		my_show_array.c \

OBJ = $(SRC:.c=.o)

NAME = libmy.a


OBJ_2=            $(SRC) $(SRC_TE)

BIB=  my.h -L . -lmy

CFLAGS += -g

all:   $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	cp my.h ../../include

clean:
	rm -f $(OBJ)

fclean: clean
		$(RM) $(NAME)
		$(RM) $(TEST)

re:     fclean all
