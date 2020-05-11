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
DESTDIR=	$(SRC_DIR)destroy/
PARS_DIR=	$(SRC_DIR)parsing/
ERR_PARS_DIR=	$(PARS_DIR)error_handling/
PROJDIR=	$(SRC_DIR)
ASMDIR=		$(SRC_DIR)assembler/
PARAMS_DIR=	$(SRC_DIR)check_params/

PROJLIST=	$(PROJDIR)sim_main.c		\
		$(PROJDIR)op.c

ASMLIST=	$(ASMDIR)write_ina_file.c	\
		$(ASMDIR)get_indexes.c		\
		$(ASMDIR)get_label_value.c	\
		$(ASMDIR)types.c		\
		$(ASMDIR)tools.c		\
		$(ASMDIR)values.c		\
		$(ASMDIR)create_cor_file.c	\
		$(ASMDIR)write_header.c

PARSLIST=	$(SRC_DIR)main.c		\
		$(PARS_DIR)file_to_struct.c	\
		$(PARS_DIR)check_file.c		\
		$(PARS_DIR)get_func_param.c	\
		$(PARS_DIR)init_cmd_struct.c	\
		$(PARS_DIR)count_commands.c	\
		$(PARS_DIR)command_loop.c	\
		$(PARS_DIR)check_label_char.c	\
		$(PARS_DIR)remove_command.c		\
		$(PARS_DIR)get_champ_name.c		\
		$(PARS_DIR)get_champ_comment.c	\
		$(PARS_DIR)get_func_name.c		\
		$(PARS_DIR)full_cmd_len.c		\
		$(ERR_PARS_DIR)file_errors.c	\
		$(DESTDIR)destroy_cmd.c			\
		$(DESTDIR)destroy_func.c		\
		$(DESTDIR)destroy_all.c

PARAMSLIST=	$(PARAMS_DIR)check_command.c \
		$(PARAMS_DIR)check_defines.c		\
		$(PARAMS_DIR)check_type_arg.c

SRC=		$(PROJLIST)	\
		$(ASMLIST)	\
		$(PARSLIST)     \
		$(PARAMSLIST)

OBJ=		$(SRC:.c=.o)
POBJ=		$(PROJLIST:.c=.o)
AOBJ=		$(ASMLIST:.c=.o)
ROBJ=		$(PARSLIST:.c=.o)
PAROBJ=		$(PARAMSLIST:.c=.o)

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

NAME=		asm

all:		title cc_title $(NAME)

obj_title:	Ptitle $(POBJ) Atitle $(AOBJ) Rtitle $(ROBJ) Partitle $(PAROBJ)

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
Atitle:
		@$(ECHO) $(WHITE) && $(ECHO) -n $(ASMDIR) | tr a-z A-Z |	\
		sed 's/\//\./' | cut -zd'/' -f1 &&				\
		$(ECHO) -n $(WHITE)' '$(BLANCO)'/         \n'$(DEF)
Rtitle:
		@$(ECHO) $(WHITE) && $(ECHO) -n $(PARS_DIR) | tr a-z A-Z |	\
		sed 's/\//\./' | cut -zd'/' -f1 &&				\
		$(ECHO) -n $(WHITE)' '$(BLANCO)'/                   \n'$(DEF)
Partitle:
		@$(ECHO) $(WHITE) && $(ECHO) -n $(PARAMS_DIR) | tr a-z A-Z |	\
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
		@cp $(NAME) ../

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
		@$(RM) ../$(NAME)
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
