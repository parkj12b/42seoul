# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/25 21:11:30 by minsepar          #+#    #+#              #
#    Updated: 2025/02/25 22:51:48 by minsepar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS := $(shell uname -s)

SRC_DIR = srcs

SRC_BASE ?= $(SRC_DIR)

# SRCS = ft_strlen_movedq.asm ft_strcpy.asm

# SRCS = ft_strlen_xmm.asm ft_strcpy.asm

SRCS = ft_strlen.asm ft_strcpy.asm

OBJ_DIR = objs

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.asm=.o))

OPT_SRC_DIR = optimized

NAME = libasm.a

NAME_BONUS = libasm_bonus.a

INCLUDES = includes

# ASM_FLAGS = -f elf64 -O0

which_os:
	echo $(OS)

CFLAGS = -Wall -Wextra -Werror

CC = cc

which_cc:
	echo $(CC)

TEST_SRC = tests/main.c tests/utils.c  tests/test_ft_strcpy.c tests/test_ft_strlen.c

TEST_EXE = a.out

GCC_SRC = gcc_optimized/main.c tests/utils.c

ifeq ($(OS),Linux)
    ASM_FLAGS = -f elf64 -D OS_LINUX
    CFLAGS += -z noexecstack
else ifeq ($(OS),Darwin)
    ASM_FLAGS = -f macho64 -D OS_MACOS
	CFLAGS += -Wa,--noexecstack
endif

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_BASE)/%.asm | $(OBJ_DIR)
	nasm $(ASM_FLAGS) $< -o $@
	
# Optimized target: force SRC_BASE and rebuild
opt: clean 
	$(MAKE) SRC_BASE=$(OPT_SRC_DIR) all

	
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

test: $(NAME)
	$(CC) $(CFLAGS) -I $(INCLUDES) $(TEST_SRC) $(NAME) -o $(TEST_EXE)

gcc:
	$(CC) $(CFLAGS) -I $(INCLUDES) $(GCC_SRC) -o gcc.out

clean:
	rm -f $(OBJS)
	rm -f $(OBJ_DIR)/*
	rm -f main.o

fclean:
	$(MAKE) clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	rm -f $(TEST_EXE)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re opt