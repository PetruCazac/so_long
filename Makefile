# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 10:01:48 by pcazac            #+#    #+#              #
#    Updated: 2023/07/18 14:11:32 by pcazac           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT = libft/libft.a
MINILIBX = MLX42/build/libmlx42.a


LIB_PATH = -Llibft
LIBRARY = -lft

LIBMLX = ./MLX42
MLX_PATH = -L"/Users/$(USER)/.brew/opt/glfw/lib/"
MLX = -Iinclude -lglfw -framework Cocoa -framework OpenGL -framework IOKit

VPATH = src/ ; obj/ ; src_bonus/ ;

SRC = so_long.c init_check.c parser.c utils.c pathfinding.c
OBJ = $(SRC:%.c=$(OBJ_PATH)/%.o)
OBJ_PATH = obj

CC= cc
CFLAGS= -g -Wall -Wextra -Werror -Wunreachable-code -Ofast -DEBUG=1

all: libmlx $(NAME) 

# libmlx:
# 	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB_PATH) $(LIBRARY) $(MINILIBX) $(MLX) $(MLX_PATH)

$(LIBFT):
	make -C $(@D) fclean
	make -C $(@D) all

$(OBJ_PATH)/%.o : %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@/bin/rm -rf $(OBJ_PATH)
	$(MAKE) -C ./libft/ clean

fclean: clean
	@/bin/rm -f $(NAME) 
	$(MAKE) -C ./libft/ fclean
	
re: fclean all 

.PHONY: all, clean, fclean, re, memory, libmlx
