NAME = libftprintf.a

SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra

CC = cc

%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@
	
all: $(OBJS) 
	$(CC) $(FLAGS) $(SRCS) main.c 
	ar rcs $(NAME) $(OBJS)
	
bonus: all
	
test:
	$(CC) $(FLAGS) -g test.c
	./a.out

re: fclean all

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
