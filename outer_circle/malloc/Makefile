ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

SRC = bins.c dldllist.c dlfree.c dlmalloc.c globals.c utils.c calloc.c

SRCS = $(addprefix src/, $(SRC))

OBJS = $(SRCS:.c=.o)

NAME = libft_malloc_$(HOSTTYPE).so

CC = cc

CFLAGS = -Wall -Wextra -Werror -I./include -g -O0 #-fsanitize=address

SOFLAGS = -shared -fPIC



all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SOFLAGS) $(OBJS) -o $(NAME)

src/%.o : src/%.c
	$(CC) $(CFLAGS) $(SOFLAGS) -c $< -o $@

clean:
	rm -rf src/*.o

fclean:
	make clean
	rm $(NAME)
	rm a.out

re:

test: $(NAME)
	$(CC) -I./include -o ./a.out src/main.c

.PHONY: all clean fclean re