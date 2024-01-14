NAME=fractol

CC=clang

SRCS=fractol.c arrow_render.c arrow_render2.c fractol_init.c fractol_init2.c fractol_utils.c input.c mlx_hooks.c mlx_hooks2.c

BONUS_SRCS=fractol_bonus.c arrow_render_bonus.c arrow_render2_bonus.c fractol_init_bonus.c fractol_init2_bonus.c fractol_utils_bonus.c input_bonus.c mlx_hooks_bonus.c mlx_hooks2_bonus.c

OBJS= $(SRCS:.c=.o)

BONUS_OBJS= $(BONUS_SRCS:.c=.o)

LIBFT = ./libft/libftprintf.a

MLX = ./mlx/libmlx.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(MLX) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

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
	rm -rf $(NAME) bonus

re:
	make fclean
	make all

bonus: $(BONUS_OBJS) $(LIBFT) $(MLX)
	touch bonus
	$(CC) $(BONUS_OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(MLX) $(LIBFT) -o $(NAME)

.PHONY: clean fclean all re mlx