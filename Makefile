## EPITECH PROJECT, 2019
## makefile
## File description:
## makes lib
##

RM	=	rm -f

CC	=	gcc

SRC	=	$(SRC_DIR)main.c				\
		$(PARS_DIR)file_to_struct.c		\
		$(PARS_DIR)check_file.c			\
		$(PARS_DIR)get_func_param.c		\
		$(PARS_DIR)init_cmd_struct.c	\
		$(PARS_DIR)count_commands.c		\
		$(PARS_DIR)command_loop.c		\
		$(ERR_PARS_DIR)file_errors.c



SRC_DIR	=	src/

PARS_DIR	=	$(SRC_DIR)parsing/

ERR_PARS_DIR	=	$(PARS_DIR)error_handling/

LIB_DIR	=	lib/

LIB_PRINT	=	print

LIB_MY		=	my

LIB_ARR		=	arr

LIB_FILE	=	file

LIB_LIST	=	$(LIB_PRINT) $(LIB_MY) $(LIB_ARR) $(LIB_FILE)

OBJ	=	$(SRC:.c=.o)

NAME	=	asm

NAME_T	=	test_asm

CFLAGS	=	-Wall -Wextra -I./include/ -L./$(LIB_DIR) -l$(LIB_ARR) -l$(LIB_MY) -l$(LIB_PRINT) -l$(LIB_FILE) -g

TESTFLAGS       =       --coverage -lcriterion

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

testing:	$(OBJ)
		for p in $(LIB_LIST);   \
                do      \
		make -C $(LIB_DIR)$$p;  \
                done
		$(CC) -o $(NAME_T) $(OBJ) tests/$(TEST_NAME) $(CFLAGS) $(TESTFLAGS)

clean:
		$(RM) $(OBJ) $(NAME)

fclean:		clean
		for p in $(LIB_LIST);	\
		do 	\
		make -C $(LIB_DIR)$$p fclean;	\
		done
		$(RM) $(NAME) $(EXEC_N) *.gc*

re:		fclean all
