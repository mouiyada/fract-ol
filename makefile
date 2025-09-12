# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyamada <kyamada@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/09 14:20:43 by kyamada           #+#    #+#              #
#    Updated: 2025/09/12 21:55:23 by kyamada          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
MLX_DIR = ./mlx
MLX = $(MLX_DIR)/libmlx.a
CFLAGS = -Wall -Wextra -Werror -O2 -I$(MLX_DIR)

SRC = fractol.c hook.c utils.c fractols.c
OBJS = $(SRC:.c=.o)
HEADER = fractol.h

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) -lX11 -lXext -lm -lXrandr -lXrender -lGL

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(MLX_DIR)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
