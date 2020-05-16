##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compile programs
##

ECHO=           /bin/echo -e
DEF=            "\e[m"
BLACK=          "\e[30m"
RED=            "\e[31m"
GREEN=          "\e[32m"
YELLOW=         "\e[33m"
BLUE=           "\e[34m"
MAGENTA=        "\e[35m"
TEAL=           "\e[36m"
WHITE=          "\e[37m"
BOLD=           "\e[1m"
BLINK=          "\e[5m"
FONT=           "\e[7m"
BORDER=         "\e[9m"

ASMDIR=		asm/
VMDIR=		corewar/

all:		asm core

asm:
		@make -C $(ASMDIR) -s

core:
		@make -C $(VMDIR) -s

clean:
		@make -C $(ASMDIR) clean -s
		@make -C $(VMDIR) clean -s

fclean:
		@make -C $(ASMDIR) fclean -s
		@make -C $(VMDIR) fclean -s

debug:
		@make -C $(ASMDIR) debug -s
		@make -C $(VMDIR) debug -s

tests_run:
		@make -C $(ASMDIR) tests_run -s
		@make -C $(VMDIR) tests_run -s

re:		fclean all

.PHONY:		asm core clean fclean debug tests_run re all
