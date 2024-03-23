CC = cc

CFLAGS = -Wall -Werror -Wextra -g

NAME = philo

SRCS =	barrier.c init_free.c main.c philo_eat.c philo_utils.c \
		routine.c take_fork.c utils.c utils2.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

re: fclean all

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

.PHONY: all re clean fclean