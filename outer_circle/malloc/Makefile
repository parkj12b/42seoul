ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

SRC = bins.c dldllist.c dlfree.c dlmalloc.c utils.c calloc.c realloc.c

SRCS = $(addprefix src/, $(SRC))

OBJS = $(SRCS:.c=.o)

NAME = libft_malloc_$(HOSTTYPE).so

CC = cc

CFLAGS = -Wall -Wextra -Werror -lcriterion -I./include -g -O0 #-fsanitize=address

SOFLAGS = -shared -fPIC

TEST_SRC = tests/dldllist_test.c tests/test_main.c tests/init_test.c

TEST_OBJS = $(TEST_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SOFLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(SOFLAGS) -c $< -o $@
	

clean:
	rm -rf src/*.o

fclean:
	make clean
	rm $(NAME)
	rm a.out
	rm tests/*.o

test: $(TEST_OBJS)
	$(CC) -g -I./include -I./tests -o ./a.out $(TEST_OBJS) ./$(NAME)

re: fclean all

.PHONY: all clean fclean re