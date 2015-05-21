DIR=	.
NAME=	my_objdump
CC=	gcc
RM=	rm -f

CSRC=	../args.c\
	../elf_headers.c\
	../elf_sloop.c\
	../file.c\
	../main.c\
	../xfuncs.c\
	main.c\
	objdump_content.c\
	objdump_header.c

OFILES=	$(CSRC:.c=.o)

CFLAGS=	-I../include -Iinclude -g -Wall -Wextra
LDFLAGS=

all: $(DIR)/$(NAME)

$(DIR)/$(NAME): $(OFILES)
	$(CC) $(OFILES) $(LDFLAGS) -o $(DIR)/$(NAME)

clean:
	$(RM) $(OFILES)

fclean: clean
	$(RM) $(DIR)/$(NAME)

re: clean fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

