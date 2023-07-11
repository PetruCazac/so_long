# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 10:01:48 by pcazac            #+#    #+#              #
#    Updated: 2023/07/11 14:39:16 by pcazac           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT = libft/libft.a

VPATH = src/ ; obj/ ; src_bonus/ ;
LIB_PATH = -Llibft
LIBRARY = -lft
OBJ_PATH = obj

SRC = so_long.c init_check.c parser.c utils.c pathfinding.c list_utils.c
OBJ = $(SRC:%.c=$(OBJ_PATH)/%.o)

CC= cc
CFLAGS= -g -Wall -Wextra -Werror

all: $(NAME) $(BONUS)

$(NAME): $(LIBFT) $(OBJ)
	@echo "----I am working here----"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB_PATH) $(LIBRARY)

$(LIBFT):
	@echo "---Calling the library---"
	make -C $(@D) fclean
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
