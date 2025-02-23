# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minsepar <minsepar@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/25 21:11:30 by minsepar          #+#    #+#              #
#    Updated: 2025/02/23 20:24:04 by minsepar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = srcs

SRCS = ft_strlen.asm ft_strcpy.asm

OBJ_DIR = objs

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.asm=.o))

NAME = libasm.a

NAME_BONUS = libasm_bonus.a

ASM = NAME_BONUS

INCLUDES = includes

# ASM_FLAGS = -f elf64 -O0

ASM_FLAGS = -f elf64

CFLAGS = -Wall -Wextra -Werror -z noexecstack

CC = cc

ifeq ($(shell uname -m), arm64)
    CC += -ld_classic --target=x86_64-apple-darwin
endif

TEST_MAIN = tests/main.c

TEST_EXE = a.out

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.asm
	nasm $(ASM_FLAGS) $< -o $@
	
test: $(NAME)
	make re
	$(CC) $(CFLAGS) -I $(INCLUDES) $(TEST_MAIN) $(NAME) -o $(TEST_EXE)

clean:
	rm -f $(OBJS)
	rm -f $(OBJ_DIR)/*
	rm -f main.o

fclean:
	make clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	rm -f $(TEST_EXE)

re:
	make fclean
	make all

.PHONY: all clean fclean re 