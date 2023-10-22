CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = main.c function.c

NAME = ft_cat

all: $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

