SRC_DIRECTORY = ./srcs

LIBRARY_DIRECTORY = .

LIBRARY_NAME = libft.a

LIBRARY_TARGET = $(addprefix $(LIBRARY_DIRECTORY)/,$(LIBRARY_NAME))

SRC_NAMES = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

SRC_TARGET = $(addprefix $(SRC_DIRECTORY)/,$(SRC_NAMES))

HEADER_DIRECTORY = ./includes

HEADER_FILE = ft.h

HEADER_TARGET = $(addprefix $(HEADER_DIRECTORY)/,$(HEADER_FILE))

CFLAGS = -Wall -Wextra -Werror

OBJECTS = $(SRC_NAMES:.c=.o)

MY_OBJECT_TARGET = $(addprefix $(SRC_DIRECTORY)/,$(OBJECTS))

CC = gcc

make: all

all: libft.a

libft.a: $(MY_OBJECT_TARGET)
	ar cr $(LIBRARY_TARGET) $(MY_OBJECT_TARGET)
clean:
	rm -f $(MY_OBJECT_TARGET)

fclean: clean
	rm -f $(LIBRARY_TARGET)

re: fclean all

$(MY_OBJECT_TARGET): %.o: %.c $(HEADER_TARGET)
	$(CC) -c -Iincludes $(CFLAGS) $< -o $@
