CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS := $(wildcard ft_*.c)
SRCS := $(filter-out ft_lst%.c, $(SRCS))

BONUS_SRCS := $(wildcard ft_lst*.c)

OBJECTS := $(SRCS:.c=.o)

BONUS_OBJECTS := $(BONUS_SRCS:.c=.o)

NAME := libft.a

ifdef WITH_BONUS
	OBJ_FILES = $(OBJECTS) $(BONUS_OBJECTS)
else
	OBJ_FILES = $(OBJECTS)
endif

all : $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

clean:
	rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

bonus:
	make WITH_BONUS=1 all

.PHONY: all clean fclean re bonus
