CC = gcc

CFLAGS = -Wall -Werror -Wextra
 
SRCS = main.c function.c function1.c function2.c

NAME = ft_tail

all: $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

