##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make file to compile
##

ECHO    =       /bin/echo -e
DEF     =       "\e[m"
BLACK   =       "\e[1;30m"
RED     =       "\e[31m"
GREEN   =       "\e[32m"
YELLOW  =       "\e[33m"
BLUE    =       "\e[34m"
MAGENTA =       "\e[35m"
TEAL    =       "\e[1;36m"
WHITE   =       "\e[1;37m"
BLINK   =       "\e[5m"
BOLD    =       "\e[1m"
BORDER  =       "\e[9m"
BLANCO  =       "\e[9;37m"
FONT    =       "\e[7m"

SRCDIR	=	src/
INCDIR	=	include/

SRC	=	$(SRCDIR)fill_file.c

OBJ	=	$(SRC:.c=.o)

ARRC	=	ar rc

CFLAGS	+=	-I $(INCDIR)

NAME	=	libfile.a

all:		title $(NAME)

title:
		@$(ECHO) $(WHITE) && $(ECHO) -n $(NAME) | cut -zd'.' -f1 |      \
		tr a-z A-Z | sed 's/LIB*/LIB./' &&                              \
		$(ECHO) -n ' '$(BLANCO)'/\n'$(DEF)

$(NAME):	$(OBJ)
		@$(ARRC) $(NAME) $(OBJ)
		@mv $(NAME) ..

clean:
		@$(RM) $(OBJ) $(NAME)

fclean:		clean
		@$(RM) $(NAME) *.gc*
		@$(RM) ../$(NAME)

debug:		CFLAGS += -g

re:		fclean all

%.o:            %.c
		@$(CC) -c -o $@ $^ $(CFLAGS) &&         \
		$(ECHO) -n $(BOLD)$(GREEN)"[OK]" ||     \
		$(ECHO) $(BOLD)$(RED)"[NO]"$< &&        \
		$(ECHO) -n $(DEF)

.PHONY:         title all clean fclean re debug
