NAME = ft_display_file

SRCS = main.c

CFLAGS = -Wall -Werror -Wextra

CC = gcc

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
