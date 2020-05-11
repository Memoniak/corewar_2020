##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compile programs
##

ECHO=           /bin/echo -e
DEF=            "\e[m"
BLACK=          "\e[1;30m"
RED=            "\e[31m"
GREEN=          "\e[32m"
YELLOW=         "\e[33m"
BLUE=           "\e[34m"
MAGENTA=        "\e[35m"
TEAL=           "\e[1;36m"
WHITE=          "\e[1;37m"
BLINK=          "\e[5m"
BOLD=           "\e[1m"
BORDER=         "\e[9m"
BLANCO=         "\e[9;37m"
BLACKY=         "\e[9;30m"
FONT=           "\e[7m"

ASMDIR=		the_assembler/
VMDIR=		the_virtual_machine/

all:		build

build:
		@make -C $(ASMDIR) --no-print-directory
		@make -C $(VMDIR) --no-print-directory

asm:
		@make -C $(ASMDIR) --no-print-directory

core:
		@make -C $(VMDIR) --no-print-directory

clean:
		@make -C $(ASMDIR) clean --no-print-directory
		@make -C $(VMDIR) clean --no-print-directory

fclean:
		@make -C $(ASMDIR) fclean --no-print-directory
		@make -C $(VMDIR) fclean --no-print-directory

tests_run:
		@make -C $(ASMDIR) tests_run --no-print-directory
		@make -C $(VMDIR) tests_run --no-print-directory

re:		fclean all
