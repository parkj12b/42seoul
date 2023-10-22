NAME = rush-02

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = main.c

$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all : ${NAME}

clean : 
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all
