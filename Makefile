##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile rush2
##

##Variables pour la compilation

SRC	=	src/check_command.c \
		src/check_type_arg.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	./asm

BIB=  -I./include/ -L./lib/my . -lmy -g

##Variables pour les tests unitaires

SRC_2 = src/check_command.c \
		src/check_type_arg.c \

SRC_TE= tests/test_check_line.c \

OBJ_2=            $(SRC_2) $(SRC_TE)

BIB=  -I./include/ -L./lib/my -lmy

CRIT = --coverage -lcriterion -lgcov -fprofile-arcs -ftest-coverage -fPIC

TEST =           test

CC_2=     gcc -o $(TEST)

##Commandes

all:	$(NAME)

$(NAME):
	make re -C lib/my
	gcc -g -Wall $(SRC) -o $(NAME) $(BIB)

tests_run:
			make re -C lib/my
			$(CC_2) $(OBJ_2) $(CRIT) $(BIB)
			./test
			gcovr --exclude tests/

out:	tests_run
	gcovr --exclude tests/ --html --html-details -o o.html
	firefox o.html

clean:
	rm -f $(OBJ)
	rm -rf *html
	rm -rf *.gcda
	rm -rf *.gcno


~clean:
	make fclean -C lib/my
	rm -rf *.o

fclean:
	rm -rf *.o
	rm -rf $(NAME)

re: fclean all
