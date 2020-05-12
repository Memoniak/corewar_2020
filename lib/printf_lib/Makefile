##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makes library
##

ECHO	=       /bin/echo -e
DEF	=       "\e[m"
BLACK	=       "\e[1;30m"
RED	=       "\e[31m"
GREEN	=       "\e[32m"
YELLOW	=       "\e[33m"
BLUE	=       "\e[34m"
MAGENTA	=       "\e[35m"
TEAL	=       "\e[1;36m"
WHITE	=       "\e[1;37m"
BLINK	=	"\e[5m"
BOLD	=	"\e[1m"
BORDER	=       "\e[9m"
BLANCO	=       "\e[9;37m"
FONT	=	"\e[7m"

INCDIR	=	include/
SRCDIR	=	src/

SRC     =	$(SRCDIR)my_printf.c		\
		$(SRCDIR)my_strlen.c		\
		$(SRCDIR)void_putchar.c		\
		$(SRCDIR)void_put_nbr.c		\
		$(SRCDIR)void_putstr.c		\
		$(SRCDIR)my_revstr.c		\
		$(SRCDIR)void_puthexa.c		\
		$(SRCDIR)void_puthexa_c.c	\
		$(SRCDIR)void_putbin.c		\
		$(SRCDIR)void_putoctal.c	\
		$(SRCDIR)void_putunsnbr.c	\
		$(SRCDIR)void_put_word_array.c	\
		$(SRCDIR)void_putword_array.c	\
		$(SRCDIR)void_putoct.c

OBJ     =       $(SRC:.c=.o)

ARRC	=	ar rc

CFLAGS	+=	-Wall -W -Werror	\
		-I $(INCDIR)

NAME    =       libprintf.a

all:		title $(NAME)

title:
		@$(ECHO) $(WHITE) && $(ECHO) -n $(NAME) | cut -zd'.' -f1 |	\
		tr a-z A-Z | sed 's/LIB*/LIB./' &&				\
		$(ECHO) -n ' '$(BLANCO)'/                                            \n'$(DEF)

$(NAME):        $(OBJ)
		@$(ARRC) $(NAME) $(OBJ) || $(ECHO)			\
		$(BOLD)$(RED)"\n\n\t     ╽ ─╼━━━━━━━━╾─ ╽\n\t╼━━━┿╉"	\
		$(DEF)$(BOLD)"BUILD FAILED "$(RED)"╊┿━━━╾\n\t     ╿ ─╼━━━━━━━━╾─ ╿"$(DEF)
		@mv $(NAME) ../

clean:
		@$(RM) $(OBJ)

fclean:		clean
		@$(RM) ../$(NAME)

debug:		CFLAGS += -g

re:		fclean all

%.o:		%.c
		@gcc -c -o $@ $^ $(CFLAGS) &&		\
		$(ECHO) -n $(BOLD)$(GREEN)"[OK]" ||	\
		$(ECHO) $(BOLD)$(RED)"[NO]"$< &&	\
		$(ECHO) -n $(DEF)

.PHONY:         title all clean fclean re debug
