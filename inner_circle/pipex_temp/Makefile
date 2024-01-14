CC = cc

CFLAGS = -Werror -Wextra -Wall

PARSER_SRCS = parser_utils.c parser.c parser_str_list.c

PARSER_OBJS = $(PARSER_SRCS:.c=.o)

PARSER_BONUS_SRCS = parser_bonus.c parser_utils_bonus.c parser_str_list_bonus.c

PARSER_BONUS_OBJS = $(PARSER_BONUS_SRCS:.c=.o)

SRCS = pipex.c safe_wrapped.c error.c pipex_utils.c pipex_preprocess.c pipex_init.c

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = 	error_bonus.c pipex_bonus.c pipex_init_bonus.c pipex_preprocess_bonus.c \
				pipex_utils_bonus.c safe_wrapped_bonus.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

NAME = pipex

LIBFT = ./libft/libftprintf.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(PARSER_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(PARSER_OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C ./libft all bonus

clean:
	make -C ./libft clean
	rm -rf *.o

fclean: clean
	make -C ./libft fclean
	rm -rf $(NAME)
	rm -rf bonus

re: fclean all

bonus: $(LIBFT) $(BONUS_OBJS) $(PARSER_BONUS_OBJS)
	touch bonus
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(PARSER_BONUS_OBJS) $(LIBFT) -o $(NAME)

.PHONY: all clean fclean re