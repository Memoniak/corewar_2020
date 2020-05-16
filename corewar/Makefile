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
ERR_DIR=	$(SRC_DIR)error_handling/
VMDIR=		$(SRC_DIR)virtual_machine/
EXEC_DIR=	$(SRC_DIR)executions/
OPT_DIR=	$(SRC_DIR)operations/
TOOLS_DIR=	$(SRC_DIR)tools/
PROSS_DIR=	$(SRC_DIR)process/

PROJLIST=	$(SRC_DIR)main.c \
		$(SRC_DIR)op.c

VMLIST=

ERRLIST=	$(ERR_DIR)exit_msg.c \
		$(ERR_DIR)parse_args.c \
		$(ERR_DIR)check_values.c \

VMLIST=		$(VMDIR)run_vm.c	\
			$(VMDIR)print_mem.c

PARSLIST=	$(PARS_DIR)read_cor.c			\
		$(PARS_DIR)init_empty_champ.c		\
		$(PARS_DIR)get_champ_content.c		\
		$(PARS_DIR)get_bytes.c			\
		$(PARS_DIR)decrypt_champ_content.c	\
		$(PARS_DIR)pars_readed_champ.c		\
		$(PARS_DIR)get_mem_info.c

EXECLIST=

DESTLIST=

OPTLIST=	$(OPT_DIR)create_opt.c		\

TOOLSLIST=	$(TOOLS_DIR)tools.c

OPTLIST=		$(OPT_DIR)create_opt.c		\
			$(OPT_DIR)fork_op.c		\
			$(OPT_DIR)my_add.c		\
			$(OPT_DIR)my_aff.c		\
			$(OPT_DIR)my_and.c		\
			$(OPT_DIR)my_ld.c		\
			$(OPT_DIR)my_ldi.c		\
			$(OPT_DIR)my_live.c		\
			$(OPT_DIR)my_lld.c		\
			$(OPT_DIR)my_lldi.c		\
			$(OPT_DIR)my_or.c		\
			$(OPT_DIR)my_st.c		\
			$(OPT_DIR)my_sti.c		\
			$(OPT_DIR)my_sub.c		\
			$(OPT_DIR)my_zjmp.c     \
			$(OPT_DIR)my_xor.c     	\
			$(OPT_DIR)my_lfork.c	\


TOOLSLIST=	$(TOOLS_DIR)tools.c		\
			$(TOOLS_DIR)move_pc.c	\
			$(TOOLS_DIR)get_champ_process.c

PROSSLIST=	$(PROSS_DIR)add_process.c		\
		$(PROSS_DIR)exec_process.c		\
		$(PROSS_DIR)create_champ_process.c	\
		$(PROSS_DIR)remove_process.c		\
		$(PROSS_DIR)get_opcode.c

SRC=		$(PROJLIST)	\
		$(VMLIST)	\
		$(PARSLIST)     \
		$(EXECLIST)	\
		$(DESTLIST)	\
		$(OPTLIST)	\
		$(PROSSLIST)	\
		$(TOOLSLIST)	\
		$(ERRLIST)

OBJ=		$(SRC:.c=.o)
POBJ=		$(PROJLIST:.c=.o)
VMOBJ=		$(VMLIST:.c=.o)
PAOBJ=		$(PARSLIST:.c=.o)
EXOBJ=		$(EXECLIST:.c=.o)
DOBJ=		$(DESTLIST:.c=.o)
OPOBJ=		$(OPTLIST:.c=.o)
PROSSOBJ=	$(PROSSLIST:.c=.o)
TOOLSOBJ=	$(TOOLSLIST:.c=.o)
ERROBJ=		$(ERRLIST:.c=.o)


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
		Dtitle $(DOB) OPtitle $(OPOBJ) PROSStitle $(PROSSOBJ) TOOLStitle $(TOOLSOBJ) \
		ERRtitle $(ERROBJ)

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
PROSStitle:
		@$(ECHO) $(WHITE) && $(ECHO) -n $(PROSS_DIR) | tr a-z A-Z |     \
		sed 's/\//\./' | cut -zd'/' -f1 &&                              \
		$(ECHO) -n $(WHITE)' '$(BLANCO)'/                   \n'$(DEF)
TOOLStitle:
		@$(ECHO) $(WHITE) && $(ECHO) -n $(TOOLS_DIR) | tr a-z A-Z |     \
		sed 's/\//\./' | cut -zd'/' -f1 &&                              \
		$(ECHO) -n $(WHITE)' '$(BLANCO)'/                   \n'$(DEF)
ERRtitle:
		@$(ECHO) $(WHITE) && $(ECHO) -n $(ERR_DIR) | tr a-z A-Z |       \
		sed 's/\//\./' | cut -zd'/' -f1 &&                              \
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
		@make -C $(TESTDIR) tests_run -s
		@./$(TEST)
		@$(ECHO)

re:		fclean all

%.o:		%.c
		@gcc -c -o $@ $^ $(CFLAGS) &&		\
		$(ECHO) -n $(BOLD)$(GREEN)"[OK]" ||	\
		$(ECHO) $(BOLD)$(RED)"[NO]"$< &&	\
		$(ECHO) -n $(DEF)

.PHONY:         title all clean fclean re debug
