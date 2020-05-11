##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compile programs
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

SRC	=	$(SRCDIR)my_getlen.c		\
		$(SRCDIR)my_getnbr.c		\
		$(SRCDIR)my_getword.c		\
		$(SRCDIR)my_remalloc.c		\
		$(SRCDIR)my_revstr.c		\
		$(SRCDIR)my_strcat.c		\
		$(SRCDIR)my_strcmp.c		\
		$(SRCDIR)my_strncmp.c		\
		$(SRCDIR)my_strdup.c		\
		$(SRCDIR)my_strcpy.c		\
		$(SRCDIR)int_to_str.c		\
		$(SRCDIR)get_file_content.c	\
		$(SRCDIR)str_to_word_array.c	\
		$(SRCDIR)custom_strlen.c \
		$(SRCDIR)is_num.c

OBJ	=	$(SRC:.c=.o)

ARRC	=	ar rc

CFLAGS	+=	-Wall -W -Werror	\
		-I $(INCDIR)

NAME	=	libmy.a

all:		title $(NAME)

title:
		@$(ECHO) -n '\n'$(WHITE) && $(ECHO) -n $(NAME) | cut -zd'.' -f1 |	\
		tr a-z A-Z | sed 's/LIB*/LIB./' &&					\
		$(ECHO) -n ' '$(BLANCO)'/                                                \n'$(DEF)

$(NAME):	$(OBJ)
		@$(ARRC) $(NAME) $(OBJ)  ||					\
		$(ECHO) $(BOLD)$(RED)"\n\n\t     ╽ ─╼━━━━━━━━╾─ ╽\n\t╼━━━┿╉"	\
		$(DEF)$(BOLD)"BUILD FAILED "$(RED)"╊┿━━━╾\n\t     ╿ ─╼━━━━━━━━╾─ ╿"$(DEF)
		@mv $(NAME) ../

clean:
		@$(RM) $(OBJ)

fclean:		clean
		@$(RM) ../$(NAME)

debug:		CFLAGS += -g
debug:		re

re:		fclean all

%.o:		%.c
		@gcc -c -o $@ $^ $(CFLAGS) &&		\
		$(ECHO) -n $(BOLD)$(GREEN)"[OK]" ||	\
		$(ECHO) $(BOLD)$(RED)"[NO]"$< &&	\
		$(ECHO) -n $(DEF)

.PHONY:         title all clean fclean re debug
