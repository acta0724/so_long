# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiwasa <kiwasa@student.42.jp>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/21 15:15:33 by kiwasa            #+#    #+#              #
#    Updated: 2025/03/30 02:30:45 by kiwasa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = so_long

# SRC_DIR = ./
# OBJ_DIR = ./obj/

# SRC_FILES = main.c init.c map.c map_check.c path_check.c render.c input.c game.c utils.c
# OBJ_FILES = $(SRC_FILES:.c=.o)

# SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
# OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

# CC = cc
# CFLAGS = -Wall -Wextra -Werror -I./minilibx-linux
# MLX_FLAGS = -lmlx -lX11 -lXext -lm


# LIBFT_DIR = ./libft/
# LIBFT = $(LIBFT_DIR)libft.a

# all: $(NAME)

# $(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS)
# 	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

# $(OBJ_DIR):
# 	mkdir -p $(OBJ_DIR)

# $(OBJ_DIR)%.o: $(SRC_DIR)%.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# $(LIBFT):
# 	make -C $(LIBFT_DIR)

# clean:
# 	rm -rf $(OBJ_DIR)
# 	make -C $(LIBFT_DIR) clean

# fclean: clean
# 	rm -f $(NAME)
# 	make -C $(LIBFT_DIR) fclean

# re: fclean all

# .PHONY: all clean fclean re

NAME = so_long

SRC_DIR = ./
OBJ_DIR = ./obj/

SRC_FILES = main.c init.c map.c map_check.c path_check.c render.c input.c game.c error_exit.c get_next_line.c utils.c free_game.c
OBJ_FILES = $(SRC_FILES:.c=.o)

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./minilibx-linux -I./libft -I./inc

MLX_DIR = ./minilibx-linux/
MLX = $(MLX_DIR)libmlx.a

LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a

all: $(NAME)

$(NAME): $(OBJ_DIR) $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(MLX) -L/usr/lib -lXext -lX11 -lm -lz

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re