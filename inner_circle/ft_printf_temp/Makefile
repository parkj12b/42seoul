NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_utils.c ft_printf_utils2.c ft_printf_numlen.c \
ft_printf_format.c ft_printf_format_d.c ft_printf_format_x.c

BONUS_SRCS = $(SRCS:.c=_bonus.c)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra

CC = cc

%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

all: $(OBJS) 
	ar rucs $(NAME) $(OBJS)

bonus: $(BONUS_OBJS)
	ar rucs $(NAME) $(BONUS_OBJS)

re: fclean all

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

.PHONY: bonus re all clean fclean
