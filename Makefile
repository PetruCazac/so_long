# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcazac <pcazac@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 10:01:48 by pcazac            #+#    #+#              #
#    Updated: 2023/08/24 20:26:43 by pcazac           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT = libft/libft.a
LIBMLX = ./MLX42

LIB_PATH = -Llibft
LIBRARY = -lft

LIBMLX_PATH = $(LIBMLX)/build


OS := $(shell uname)
ifeq ($(OS), Darwin)
	MINILIBX = MLX42/build/libmlx42.a
	MLX_PATH = -L"/Users/$(USER)/.brew/opt/glfw/lib/"
	MLX = -Iinclude -lglfw -framework Cocoa -framework OpenGL -framework IOKit -DDEBUG=1
else ifeq ($(OS), Linux)
	MINILIBX = MLX42/build/libmlx42.a
	MLX_PATH = -L"MLX42/build/"
	MLX = -Iinclude -ldl -lglfw -pthread -lm -DDEBUG=1
else 
	$(shell echo "OS not supported");
endif

VPATH = src/ ; obj/ ; src_bonus/ ;

SRC = so_long.c init_check.c parser.c utils.c pathfinding.c image.c \
	list_utils.c initialize_player.c initialize_collectible.c \
	initialize_exit.c initialize_background.c track_position.c \
	second_animation_collectible.c second_animation_exit.c \
	show_info.c movement.c free_data.c image_utils.c exit_utils.c \
	collectible_utils.c

OBJ = $(SRC:%.c=$(OBJ_PATH)/%.o)
OBJ_PATH = obj

CC= cc
CFLAGS= -g -Wall -Wextra -Werror -Wunreachable-code -Ofast

# -fsanitize=address
all: $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(OBJ) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB_PATH) $(LIBRARY) $(MINILIBX) $(MLX) $(MLX_PATH)

$(LIBMLX): $(LIBMLX_PATH)/libmlx42.a

$(LIBMLX_PATH)/libmlx42.a:
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(LIBFT):
	make -C $(@D) all

$(OBJ_PATH)/%.o : %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	/bin/rm -rf $(OBJ_PATH)
	$(MAKE) -C ./libft/ clean
	# make -C $(LIBMLX)/build clean

fclean: clean
	/bin/rm -f $(NAME)
	$(MAKE) -C ./libft/ fclean
	# make -C $(LIBMLX)/build clean

re: fclean all

.PHONY: all, clean, fclean, re
