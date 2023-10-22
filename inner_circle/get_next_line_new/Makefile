all: 
	cc -g -fsanitize=address -Wall -Wextra -Werror get_next_line_utils.c get_next_line.c test.c
	
bonus:
	cp get_next_line.c get_next_line_bonus.c
	cp get_next_line_utils.c get_next_line_utils_bonus.c
	cp get_next_line.h get_next_line_bonus.h
	cc -g -fsanitize=address -Wall -Wextra -Werror get_next_line_utils_bonus.c get_next_line_bonus.c test.c

fclean:
	rm -f *.o
