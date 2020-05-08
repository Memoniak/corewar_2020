## EPITECH PROJECT, 2019
## makefile
## File description:
## makes lib
##

RM	=	rm -f

CC	=	gcc

SRC	=	$(SRC_DIR)file_to_struct.c	\

SRC_DIR	=	src/

LIB_DIR	=	lib/

LIB_PRINT	=	print

LIB_MY		=	my

LIB_ARR		=	arr

LIB_LIST	=	$(LIB_PRINT) $(LIB_MY) $(LIB_ARR)

OBJ	=	$(SRC:.c=.o)

NAME	=	asm

CFLAGS	=	-Wall -Wextra -I./include/ -L./$(LIB_DIR) -l$(LIB_ARR) -l$(LIB_MY) -l$(LIB_PRINT)

all:		$(NAME)

$(NAME):	$(OBJ)
		for p in $(LIB_LIST);	\
		do	\
		make -C $(LIB_DIR)$$p;	\
		done
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

debug:		$(OBJ)
		for p in $(LIB_LIST);	\
		do	\
		make -C $(LIB_DIR)$$p;	\
		done
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -g
clean:
		$(RM) $(OBJ) $(NAME)

fclean:		clean
		for p in $(LIB_LIST);	\
		do 	\
		make -C $(LIB_DIR)$$p fclean;	\
		done
		$(RM) $(NAME) $(EXEC_N) *.gc*

re:		fclean all
