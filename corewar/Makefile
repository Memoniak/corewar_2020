##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compile programs
##

ECHO=		/bin/echo -e
DEF=		"\e[m"
BLACK=		"\e[1;30m"
RED=		"\e[31m"
GREEN=		"\e[32m"
YELLOW=		"\e[33m"
BLUE=		"\e[34m"
MAGENTA=	"\e[35m"
TEAL=		"\e[1;36m"
WHITE=		"\e[1;37m"
BLINK=		"\e[5m"
BOLD=		"\e[1m"
BORDER=		"\e[9m"
BLANCO=		"\e[9;37m"
BLACKY=		"\e[9;30m"
FONT=		"\e[7m"

INCDIR=		include/
SRC_DIR=	src/
LIBDIR=		../lib/
TESTDIR=	tests/
MYDIR=		$(LIBDIR)my_lib/
PRINTDIR=	$(LIBDIR)printf_lib/
ARRDIR=		$(LIBDIR)arr/
FILEDIR=	$(LIBDIR)file/
PROJDIR=	$(SRC_DIR)
DESTDIR=	$(SRC_DIR)destroy/
PARS_DIR=	$(SRC_DIR)parsing/
ERR_PARS_DIR=	$(PARS_DIR)error_handling/
VMDIR=		$(SRC_DIR)virtual_machine/
EXEC_DIR=	$(SRC_DIR)executions/
OPT_DIR=	$(SRC_DIR)operations/

PROJLIST=
VMLIST=

PARSLIST=	$(PARS_DIR)init_empty_champ.c \
		$(ERR_PARS_DIR)check_values.c \
		$(ERR_PARS_DIR)main.c

EXECLIST=

DESTLIST=

OPTLIST=

SRC=		$(PROJLIST)	\
		$(VMLIST)	\
		$(PARSLIST)     \
		$(EXECLIST)	\
		$(DESTLIST)	\
		$(OPTLIST)

OBJ=		$(SRC:.c=.o)
POBJ=		$(PROJLIST:.c=.o)
VMOBJ=		$(VMLIST:.c=.o)
PAOBJ=		$(PARSLIST:.c=.o)
EXOBJ=		$(EXECLIST:.c=.o)
DOBJ=		$(DESTLIST:.c=.o)
OPOBJ=		$(OPTLIST:.c=.o)

TUFLAG=		--coverage -lcriterion
MULFLAG=	-lcsfml-graphics -lcsfml-system -lcsfml-audio
MATHFLAG=	-lm
PSUFLAG=	-lcurses

LIB_DIR=	$(PRINTDIR) $(ARRDIR) $(FILEDIR) $(MYDIR)
LIB_LIST=	my printf arr file
LIBRARIES=	$(LIB_LIST:%=-l%)

LDFLAGS=	-L $(LIBDIR) $(LIBRARIES)
CFLAGS+=	-W -Wall	\
		-I $(INCDIR)	\
		$(LDFLAGS)

TEST=		unit_tests

NAME=		corewar

all:		title cc_title $(NAME)

obj_title:	Ptitle $(POBJ) VMtitle $(VMOBJ) PAtitle $(PAOBJ) EXtitle $(EXECOBJ)	\
		Dtitle $(DOB) OPtitle $(OPOBJ)

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
		$(ECHO) -n $(WHITE)' '$(BLANCO)'/  \n'$(DEF)
VMtitle:
		@$(ECHO) $(WHITE) && $(ECHO) -n $(VMDIR) | tr a-z A-Z |	\
		sed 's/\//\./' | cut -zd'/' -f1 &&				\
		$(ECHO) -n $(WHITE)' '$(BLANCO)'/         \n'$(DEF)
PAtitle:
		@$(ECHO) $(WHITE) && $(ECHO) -n $(PARS_DIR) | tr a-z A-Z |	\
		sed 's/\//\./' | cut -zd'/' -f1 &&				\
		$(ECHO) -n $(WHITE)' '$(BLANCO)'/                   \n'$(DEF)
EXtitle:
		@$(ECHO) $(WHITE) && $(ECHO) -n $(EXEC_DIR) | tr a-z A-Z |	\
		sed 's/\//\./' | cut -zd'/' -f1 &&				\
		$(ECHO) -n $(WHITE)' '$(BLANCO)'/                   \n'$(DEF)
Dtitle:
		@$(ECHO) $(WHITE) && $(ECHO) -n $(DESTDIR) | tr a-z A-Z |	\
		sed 's/\//\./' | cut -zd'/' -f1 &&				\
		$(ECHO) -n $(WHITE)' '$(BLANCO)'/                   \n'$(DEF)
OPtitle:
		@$(ECHO) $(WHITE) && $(ECHO) -n $(OPT_DIR) | tr a-z A-Z |	\
		sed 's/\//\./' | cut -zd'/' -f1 &&				\
		$(ECHO) -n $(WHITE)' '$(BLANCO)'/                   \n'$(DEF)

cc_title:
		@$(ECHO) -n $(WHITE)'┧' && $(ECHO) -n ' '$(CC) |\
		tr a-z A-Z && $(ECHO) ' '$(BLANCO)/		\
		'                         '$(DEF)		\
		'\n'$(BOLD)$(WHITE)┃$(YELLOW)$(CFLAGS)
		@$(ECHO) $(WHITE)┃$(MAGENTA)$(LDFLAGS)$(DEF)
		@$(ECHO) -n $(WHITE)╵

lib_maker:
		@$(ECHO)
		@for p in $(LIB_DIR) ; do	\
			make -C $$p -s ;	\
		done

$(NAME):	obj_title lib_maker
		@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) && $(ECHO)					\
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
		@for p in $(LIB_DIR); do	\
			make -C $$p fclean -s;	\
		done
		@$(RM) $(TEST)
		@$(RM) $(NAME)
		@$(ECHO) '\t   '$(BOLD)$(WHITE)"FCLEAN "$(BOLD)$(GREEN)"SUCCESS "✓'\n'$(DEF)

debug:		CFLAGS += -g
debug:		re

tests_run:	fclean lib_maker
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
