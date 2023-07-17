# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 10:01:48 by pcazac            #+#    #+#              #
#    Updated: 2023/07/17 17:12:38 by pcazac           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT = libft/libft.a
MINILIBX = MLX42/build/libmlx42.a

VPATH = src/ ; obj/ ; src_bonus/ ;
LIB_PATH = -Llibft
LIBRARY = -lft
MLX_PATH = -L"/Users/$(USER)/.brew/opt/glfw/lib/"
MLX = -Iinclude -lglfw -framework Cocoa -framework OpenGL -framework IOKit
OBJ_PATH = obj

SRC = so_long.c init_check.c parser.c utils.c pathfinding.c
OBJ = $(SRC:%.c=$(OBJ_PATH)/%.o)

CC= cc
CFLAGS= -g -Wall -Wextra -Werror

all: $(NAME) 

$(NAME): $(LIBFT) $(OBJ)
	@echo "----I am working here----"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB_PATH) $(LIBRARY) $(MINILIBX) $(MLX) $(MLX_PATH)

$(LIBFT):
	@echo "---Calling the library---"
	make -C $(@D) fclean
	make -C $(@D) all

$(MINILIBX):
	@echo "---Calling the graphical library---"
	make -C $(@D) clean
	make -C $(@D) all

$(OBJ_PATH)/%.o : %.c
	@echo "---Santa's making objects---"
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "---Cleaning this mess---"
	@/bin/rm -rf $(OBJ_PATH)
	$(MAKE) -C ./libft/ clean

fclean: clean
	@echo "---Making a deep clean---"
	@/bin/rm -f $(NAME) 
	$(MAKE) -C ./libft/ fclean
	
re: fclean all 

.PHONY: all clean fclean re memory
