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
BLACKY	=       "\e[9;30m"
FONT	=	"\e[7m"

INCDIR	=	include/
SRCDIR	=	src/
LIBDIR	=	lib/
TESTDIR	=	tests/
MYDIR	=	$(LIBDIR)my/
PRINTDIR=	$(LIBDIR)printf_lib/
PROJDIR	=	$(SRCDIR)

PROJLIST=	$(SRCDIR)main.c			\
		$(SRCDIR)base_to_hexa.c		\
		$(SRCDIR)code_to_hexa.c		\
		$(SRCDIR)types_to_hexa.c	\
		$(SRCDIR)values_to_hexa.c

SRC	=	$(PROJLIST)

OBJ	=	$(SRC:.c=.o)
POBJ	=	$(PROJLIST:.c=.o)

TUFLAG	=	--coverage -lcriterion
MULFLAG	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio
MATHFLAG=	-lm
PSUFLAG	=	-lcurses

LDFLAGS	=	-L $(LIBDIR) -lmy	\
		-L $(LIBDIR) -lprintf

CFLAGS	+=	-W -Wall -Werror	\
		-I $(INCDIR)

TEST	=	unit_tests

NAME	=	asm

all:		title cc_title $(NAME)

obj_title:	Ptitle $(POBJ)

title:
		@$(ECHO) $(BOLD)$(BLUE)"\n        ╼┪  ─╼━━━━━━━┷━━━━━━━╾─  ┢╾\n    ╼━━━┿╉"	\
		$(DEF)$(BOLD)BUILDING $(TEAL)'\t'$(NAME)'\t'$(BOLD)$(BLUE)			\
		"╊┿━━━╾\n        ╼┩  ─╼━━━━━━━┯━━━━━━━╾─  ┡╾\n"$(DEF)

clean_title:
		@$(ECHO) $(BOLD)$(BLUE)"\n        ╼┪  ─╼━━━━━━━┷━━━━━━━╾─  ┢╾\n    ╼━━━┿╉"	\
		$(DEF)$(BOLD)CLEANING $(TEAL)'\t'$(NAME)'\t'$(BOLD)$(BLUE)			\
		"╊┿━━━╾\n        ╼┩  ─╼━━━━━━━┯━━━━━━━╾─  ┡╾\n"$(DEF)

Ptitle:
		@$(ECHO) $(WHITE) && $(ECHO) -n $(PROJDIR) | tr a-z A-Z |	\
		sed 's/\//\./' | cut -zd'/' -f1 &&				\
		$(ECHO) -n $(WHITE)' '$(BLANCO)'/        \n'$(DEF)

cc_title:
		@$(ECHO) -n $(WHITE)'┧' && $(ECHO) -n ' '$(CC) |\
		tr a-z A-Z && $(ECHO) ' '$(BLANCO)/		\
		'                         '$(DEF)		\
		'\n'$(BOLD)$(WHITE)┃$(YELLOW)$(CFLAGS)
		@$(ECHO) $(WHITE)┃$(MAGENTA)$(LDFLAGS)$(DEF)
		@$(ECHO) -n $(WHITE)╵

$(NAME):	obj_title
		@make -C $(MYDIR) --no-print-directory
		@make -C $(PRINTDIR) --no-print-directory
		@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) && $(ECHO)			\
		$(BOLD)$(GREEN)"\n\n\t     ╽ ─╼━━━━━━━━━╾─ ╽\n\t ╼━━┿╉"$(DEF)			\
		$(BOLD)"BUILD SUCCESS "$(GREEN)"╊┿━━╾\n\t     ╿ ─╼━━━━━━━━━╾─ ╿\n"$(DEF) ||	\
		$(ECHO) $(BOLD)$(RED)"\n\n\t     ╽ ─╼━━━━━━━━╾─ ╽\n\t ╼━━┿╉"$(DEF)		\
		$(BOLD)"BUILD FAILED "$(RED)"╊┿━━╾\n\t     ╿ ─╼━━━━━━━━╾─ ╿"$(DEF)

clean:
		@$(RM) $(OBJ)
		@$(ECHO) '\t   '$(WHITE)"CLEANING "$(MYDIR)$(DEF)
		@$(ECHO) '\t   '$(WHITE)"CLEANING "$(PRINTDIR)$(DEF)
		@$(ECHO) '\t   '$(BOLD)$(WHITE)"CLEAN "$(BOLD)$(GREEN)"SUCCESS "✓$(DEF)

fclean:		clean_title clean
		@make -C $(MYDIR) fclean --no-print-directory
		@make -C $(PRINTDIR) fclean --no-print-directory
		@$(RM) $(TEST)
		@$(RM) $(NAME)
		@$(ECHO) '\t   '$(BOLD)$(WHITE)"FCLEAN "$(BOLD)$(GREEN)"SUCCESS "✓'\n'$(DEF)

debug:		CFLAGS += -g
debug:		re

tests_run:	fclean
		@make -C $(TESTDIR) tests_run --no-print-directory
		@./$(TEST)
		@$(ECHO)

re:		fclean all

%.o:		%.c
		@gcc -c -o $@ $^ $(CFLAGS) &&		\
		$(ECHO) -n $(BOLD)$(GREEN)"[OK]" ||	\
		$(ECHO) $(BOLD)$(RED)"[NO]"$< &&	\
		$(ECHO) -n $(DEF)

.PHONY:         title all clean fclean re debug
