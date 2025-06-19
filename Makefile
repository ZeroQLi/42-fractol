# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zeroql <zeroql@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/02 18:11:16 by mtangalv          #+#    #+#              #
#    Updated: 2025/05/13 12:48:42 by zeroql           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFILES = src/fractol.c \
	utils/utils.c \
	utils/keys.c \
	utils/errs.c \
	src/mandel.c \
	src/julia.c \
	src/ship.c \

OBJECTS = $(CFILES:.c=.o)

LIBFT_PATH = libft
MLX_PATH = mlx
LIBFT_LIB = $(LIBFT_PATH)/libft.a
MLX_LIB = $(MLX_PATH)/libmlx.a
LIBFT_FLAGS = -L$(LIBFT_PATH) -lft
MLX_FLAGS = -L$(MLX_PATH) -lm -lmlx -framework OpenGL -framework AppKit
MLX_FLAGS = -L$(MLX_PATH) -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

all: subsystems $(NAME)

$(NAME): $(OBJECTS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)

subsystems: $(LIBFT_LIB) $(MLX_LIB)

$(LIBFT_LIB):
	@make -C $(LIBFT_PATH)

$(MLX_LIB):
	@make -C $(MLX_PATH)

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -I/usr/includes -c -o  $@ $<

clean:
	make clean -C $(LIBFT_PATH)/
	make clean -C $(MLX_PATH)/
	rm -rf $(OBJECTS)

fclean: clean
	make fclean -C $(LIBFT_PATH)/
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re subsystems
