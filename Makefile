.PHONY:	objdump

export DIR
OUT=	objdump
RM=	rm -f

all: my_objdump

my_objdump: objdump

objdump:
	make --no-print-directory DIR=.. -C src

clean:
	make --no-print-directory DIR=.. -C src clean ; \

fclean:
	make --no-print-directory DIR=.. -C src fclean ; \

re:
	make --no-print-directory DIR=.. -C src re ; \
