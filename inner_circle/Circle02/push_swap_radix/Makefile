CC = cc

CCFLAGS = -Wall -Werror -Wextra

NAME = push_swap

BONUS_NAME = checker

SRCS = 	main.c push_swap_preprocess.c push_swap_preprocess2.c push_swap_preprocess3.c \
		push_swap_sort.c push_swap_sort2.c push_swap_stack.c push_swap_stack2.c \
		push_swap_stack3.c push_swap_utils.c push_swap_utils2.c

OBJS = $(SRCS:%)

LIBFT = ./libft/libftprintf.a

BONUS_SRCS =	checker_bonus.c checker_preprocess_bonus.c checker_preprocess2_bonus.c checker_stack_bonus.c checker_stack2_bonus.c \
				checker_stack3_bonus.c checker_utils_bonus.c

all: $(NAME)

$(LIBFT): 
	make -C ./libft all bonus

$(NAME): $(LIBFT)
	$(CC) $(CCFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

$(BONUS_NAME): $(LIBFT)
	$(CC) $(CCFLAGS) $(BONUS_SRCS) $(LIBFT) -o $(BONUS_NAME)

bonus: $(BONUS_NAME)

re: fclean all

clean:
	make -C libft clean
	rm -rf *.o

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)
	rm -rf $(BONUS_NAME)

.PHONY: all re clean fclean bonus libft