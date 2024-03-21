CC = cc

CCFLAGS = -Wall -Werror -Wextra -g -O0

NAME = philo


SRCS = 	error.c free.c init.c main.c philo_actions.c philo_actions2.c \
		philo_routine2.c philo_utils.c routine.c utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) -c $(CCFLAGS) $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) $(SRCS) -o $(NAME)

re: fclean all

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

.PHONY: all re clean fclean