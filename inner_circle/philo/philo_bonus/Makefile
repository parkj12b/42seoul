CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = philo_bonus

SRCS = main_bonus.c philo_action_bonus.c philo_init_bonus.c philo_routine_bonus.c \
		philo_utils_bonus.c philo_utils2_bonus.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:
	make clean
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re