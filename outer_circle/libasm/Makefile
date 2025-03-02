# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/25 21:11:30 by minsepar          #+#    #+#              #
#    Updated: 2025/03/02 22:44:21 by minsepar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS := $(shell uname -s)

SRC_DIR = srcs

SRC_BASE ?= $(SRC_DIR)

# SRCS = ft_strlen_movedq.asm ft_strcpy.asm

# SRCS = ft_strlen_xmm.asm ft_strcpy.asm

SRCS = 	ft_strlen.asm ft_strcpy.asm ft_strcmp.asm ft_write.asm ft_read.asm \
		ft_strdup.asm ft_isspace.asm \
		

BONUS_SRCS =	ft_atoi_base_bonus.asm ft_create_elem_bonus.asm \
				ft_list_push_front_bonus.asm ft_list_size_bonus.asm	\
				ft_list_sort_bonus.asm

C_SRCS =		ft_list_clear_bonus.c

OBJ_DIR = objs

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.asm=.o))

BONUS_OBJS = $(addprefix $(OBJ_DIR)/, $(BONUS_SRCS:.asm=.o))

C_OBJS = $(addprefix $(OBJ_DIR)/, $(C_SRCS:.c=.o))

OPT_SRC_DIR = optimized

NAME = libasm.a

INCLUDES = includes

CFLAGS = -Wall -Wextra -Werror -lc #-fsanitize=address

CC = cc

TEST_SRC = 	tests/utils.c  tests/test_ft_strcpy.c \
			tests/test_ft_strlen.c tests/test_ft_strcmp.c \
			tests/test_ft_write.c tests/test_ft_read.c \
			
TEST_BONUS_SRC =	tests/test_ft_atoi_base.c tests/test_ft_create_elem.c \
					tests/test_ft_list_push_front.c tests/test_ft_list_size.c \
					tests/test_ft_list_sort.c

TEST_EXE = a.out

GCC_SRC = gcc_optimized/main.c tests/utils.c

ifeq ($(OS),Linux)
    ASM_FLAGS = -f elf64 -D OS_LINUX
    CFLAGS += -z noexecstack
else ifeq ($(OS),Darwin)
    ASM_FLAGS = -f macho64 -D OS_MACOS
	CFLAGS += -Wa,--noexecstack
endif

ifeq ($(WITH_BONUS), 1)
	OBJECTS = $(OBJS) $(C_OBJS) $(BONUS_OBJS)
	TEST_SRCS = $(TEST_SRC) $(TEST_BONUS_SRC) tests/main_bonus.c 
else
	OBJECTS = $(OBJS)
	TEST_SRCS = $(TEST_SRC) tests/main.c 
endif

all: $(NAME)

which_os:
	echo $(OS)

which_cc:
	echo $(CC)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

$(OBJ_DIR)/%.o: $(SRC_BASE)/%.asm | $(OBJ_DIR)
	nasm -g $(ASM_FLAGS) $< -o $@

$(OBJ_DIR)/%.o: $(SRC_BASE)/%.c | $(OBJ_DIR)
	$(CC) -Wall -Wextra -Werror -I $(INCLUDES) -c $< -o $@
	
# Optimized target: force SRC_BASE and rebuild
opt: clean 
	$(MAKE) SRC_BASE=$(OPT_SRC_DIR) all

	
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

test: $(NAME)
	$(CC) -g $(CFLAGS) -I $(INCLUDES) $(TEST_SRCS) $(NAME) -o $(TEST_EXE)

gcc:
	$(CC) $(CFLAGS) -I $(INCLUDES) $(GCC_SRC) -o gcc.out

clean:
#	rm -f $(OBJS) $(C_OBJS) $(BONUS_OBJS)
	rm -f $(OBJ_DIR)/*
	rm -f main.o

fclean:
	$(MAKE) clean
	rm -f $(NAME)
	rm -f $(TEST_EXE)

re:
	$(MAKE) fclean
	$(MAKE) all

bonus:
	$(MAKE) WITH_BONUS=1 all

bonus_test:
	$(MAKE) WITH_BONUS=1 test

.PHONY: all clean fclean re bonus opt test bonus_test