CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = process_map.c \
	ft_free.c \
	ft_info.c \
	ft_utils.c \
	get_firstline.c \
	get_from_file.c \
	solve.c \
	solve_func.c
TARGET = bsq

all : $(TARGET)

$(TARGET): $(SRC) ft_bsq.h
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(SRC:.c=.o)

fclean: clean
	rm -f $(TARGET)

re:
	make fclean
	make all