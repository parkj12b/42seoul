CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = process_map.c \
	debug.c \
	error.c \
	ft_free.c \
	ft_info.c \
	get_buff_list.c \
	get_firstline.c \
	get_from_file.c \
	solve.c \
	solve_func.c
TARGET = bsq

all : $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(SRC:.c=.o)

fclean: clean
	rm -f $(TARGET)

re:
	make fclean
	make all

dotest:
	@echo "100 100" > test_python
	@perl main.pl 100 100 5 | sed '1d' >> test_python
	@echo "100012" > test
	@cat test_python | sed '1d' | tr -d ' ' >> test
	@./bsq < test > diff_mine
	@python test.py < test_python > diff_python
	@diff diff_mine diff_python
