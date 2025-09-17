NAME=	fractol

CC=		cc

SRCS=	fractol.c arrow_render.c arrow_render2.c fractol_init.c \
		fractol_init2.c fractol_utils.c input.c mlx_hooks.c mlx_hooks2.c

BONUS_SRCS=	fractol_bonus.c arrow_render_bonus.c arrow_render2_bonus.c \
			fractol_init_bonus.c fractol_init2_bonus.c fractol_utils_bonus.c \
			input_bonus.c mlx_hooks_bonus.c mlx_hooks2_bonus.c

OBJS=	$(SRCS:.c=.o)

BONUS_OBJS=	$(BONUS_SRCS:.c=.o)

LIBFT =		./libft/libftprintf.a

MLX =		./mlx/libmlx.a

MLX_LINUX =	./minilibx-linux/libmlx.a

CFLAGS =	-Wall -Wextra -Werror -O3 -fopenmp

NPROCS = $(shell nproc 2>/dev/null || sysctl -n hw.ncpu)

export OMP_NUM_THREADS ?= $(NPROCS)

all:		$(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(OBJS) -Ilibft -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit $(MLX) $(LIBFT) -fopenmp -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Iminilibx-linux -c $< -o $@

$(LIBFT):
	make -C ./libft all bonus

$(MLX):
	make -C ./mlx all

clean:
	make -C ./libft clean
	make -C ./mlx clean
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean: clean
	make -C ./libft fclean
	rm -rf $(NAME) bonus linux

re:
	make fclean
	make all

bonus: $(BONUS_OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -Imlx -Ilibft -Lmlx -lmlx -framework OpenGL -framework \
	AppKit $(MLX) $(LIBFT) -fopenmp -o $(NAME)
	touch bonus

linux: $(BONUS_OBJS) $(LIBFT) $(MLX_LINUX)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -Lminilibx-linux -lmlx_Linux -L/usr/lib \
	-Iminilibx_linux -lXext -lX11 -lm -lz -L/usr/lib/x86_64-linux-gnu -lgomp $(LIBFT) -o $(NAME)
	@echo "Running with OMP_NUM_THREADS = $(OMP_NUM_THREADS)"
	touch linux

.PHONY: clean fclean all re mlx