NAME = fractol
SRC = fractol.c mandelbrot.c
MLX_DIR = ./mlx
MLX = $(MLX_DIR)/libmlx.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(MLX_DIR)

all: $(NAME)

$(NAME): $(SRC)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(MLX) -lX11 -lXext -lXrandr -lXrender -lGL -lm -lbsd

clean:
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
