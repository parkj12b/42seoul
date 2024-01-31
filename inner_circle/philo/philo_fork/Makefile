CC = cc

CFLAGS = -Wall -Werror -Wextra -g 

NAME = philo

SRCS = main.c philo_action.c philo_init.c philo_routine1.c philo_routine2.c philo_util.c

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