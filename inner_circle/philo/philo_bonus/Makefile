CC =	cc

CFLAGS = -Wall -Wextra -Werror -g -pg

NAME =	philo_bonus

SRCS =	fork_philo_bonus.c init_free_bonus.c itoa_bonus.c main_bonus.c \
		philo_eat_bonus.c philo_util_bonus.c routine_bonus.c utils_bonus.c \
		utils_bonus2.c waiter_bonus.c str_parser_bonus.c

OBJS =	$(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

test: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) test.c

re: fclean all

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

.PHONY: all re clean fclean