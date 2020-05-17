##
## EPITECH PROJECT, 2020
## makefile
## File description:
## compile programs
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
BLACKY  =       "\e[9;30m"
FONT    =       "\e[7m"

INCDIR  =       ../include/
SRCDIR  =       ./src/
LIBDIR  =       ../../lib/
MYDIR   =       $(LIBDIR)my_lib/
PRINTDIR=       $(LIBDIR)printf_lib/
PROJDIR =       $(SRCDIR)

PROJLIST=	../src/op.c

ASMLIST=	../src/check_params/check_command.c \
			../src/check_params/check_defines.c \
			../src/check_params/check_type_arg.c \
			../src/parsing/check_label_char.c

SRC     =	test_check_line.c		\
		$(PROJLIST)		\
		$(ASMLIST)

OBJ     =       $(SRC:.c=.o)
POBJ    =       $(PROJLIST:.c=.o)
AOBJ    =       $(ASMLIST:.c=.o)

TUFLAG  =       --coverage -lcriterion
MULFLAG =       -lcsfml-graphics -lcsfml-system -lcsfml-audio
MATHFLAG=       -lm
PSUFLAG =       -lcurses

LDFLAGS =       -L $(LIBDIR) -lmy       \
		-L $(LIBDIR) -lprintf

CFLAGS  +=      -W -Wall -Werror        \
		-I $(INCDIR)		\
		$(TUFLAG)

TEST    =       unit_tests

obj_title:      Ptitle $(POBJ) Atitle $(AOBJ)

title:
		@$(ECHO) $(BOLD)$(BLUE)"\n        ╼┪  ─╼━━━━━━┷━━━━━━╾─  ┢╾\n    ╼━━━┿╉"\
		$(DEF)$(BOLD)BUILDING $(TEAL)$(TEST)$(BOLD)$(BLUE)			\
		"╊┿━━━╾\n        ╼┩  ─╼━━━━━━┯━━━━━━╾─  ┡╾\n"$(DEF)

Ptitle:
		@$(ECHO) $(WHITE) && $(ECHO) -n $(PROJDIR) | tr a-z A-Z |       \
		sed 's/\//\./' | cut -zd'/' -f1 &&                              \
		$(ECHO) -n $(WHITE)' '$(BLANCO)'/        \n'$(DEF)
Atitle:
		@$(ECHO) $(WHITE) && $(ECHO) -n $(ASMDIR) | tr a-z A-Z |       \
		sed 's/\//\./' | cut -zd'/' -f1 &&                              \
		$(ECHO) -n $(WHITE)' '$(BLANCO)'/        \n'$(DEF)

cc_title:
		@$(ECHO) -n $(WHITE)'┧' && $(ECHO) -n ' '$(CC) |\
		tr a-z A-Z && $(ECHO) ' '$(BLANCO)/             \
		'                         '$(DEF)               \
		'\n'$(BOLD)$(WHITE)┃$(YELLOW)$(CFLAGS)
		@$(ECHO) $(WHITE)┃$(MAGENTA)$(LDFLAGS)$(DEF)
		@$(ECHO) -n $(WHITE)╵

tests_run:	title cc_title obj_title $(OBJ)
		@make -C $(MYDIR) -s
		@make -C $(PRINTDIR) -s
		@$(CC) -o $(TEST) $(OBJ) $(CFLAGS) $(LDFLAGS) && $(ECHO)                        \
		$(BOLD)$(GREEN)"\n\n\t     ╽ ─╼━━━━━━━━━╾─ ╽\n\t ╼━━┿╉"$(DEF)                   \
		$(BOLD)"BUILD SUCCESS "$(GREEN)"╊┿━━╾\n\t     ╿ ─╼━━━━━━━━━╾─ ╿\n"$(DEF) ||     \
		$(ECHO) $(BOLD)$(RED)"\n\n\t     ╽ ─╼━━━━━━━━╾─ ╽\n\t ╼━━┿╉"$(DEF)              \
		$(BOLD)"BUILD FAILED "$(RED)"╊┿━━╾\n\t     ╿ ─╼━━━━━━━━╾─ ╿"$(DEF)
		@mv $(TEST) ../

%.o:            %.c
		@gcc -c -o $@ $^ $(CFLAGS) &&           \
		$(ECHO) -n $(BOLD)$(GREEN)"[OK]" ||     \
		$(ECHO) $(BOLD)$(RED)"[NO]"$< &&        \
		$(ECHO) -n $(DEF)

.PHONY:         title
