/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:00:28 by pcazac            #+#    #+#             */
/*   Updated: 2023/08/27 18:22:24 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <errno.h>
# include "structures.h"
# include "../libft/header/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define I_SIZE 100
# define P_SIZE 100
# define ITERATIONS 5
# define STEP 20

// init_check.c
int			check_all(int argc);

// parser.c
char		**parser(char *file);

// utils.c
void		purge(char **map);
char		**copymap(char **map);
void		free_array(char **arr);
void		errormngr(char **map, char *str);
char		**get_matrix(int fd, int count);

// pathfinding.c
void		find_path(char **map);

// initialize_background.c
void		put_background(t_game *data);

// list_utils.c
t_game		*initialize_data(char **map, mlx_t *mlx);
t_cimage	*new_cnode(int x, int y);

// image_utils.c
t_animation	*new_texture(char *path);
int			add_texture(t_animation *node, t_animation **obj);
void		add_back_image(t_cimage *img, t_game *data);

// initialize_exit.c
void		exit_hook(void *param);

// exit_utils.c
void	simple_exit(t_game *data);
void	after_exit(t_game *data);

// initialize_collectible.c
void		collectible_hook(void *param);

// collectible_utils.c
void	to_collect(t_cimage *temp, t_game *data);
void	collected(t_cimage *temp, t_game *data);

// image.c
void		init_image(t_game *data);

// initialize_background.c
void		initialize_background(t_game *data);

// initialize_player.c
void		initialize_player(t_game *data);
void		player_static_hook(void *param);
void		player_moving_hook(void *param);

// initialize_collectible.c
void		initialize_collectible(t_game *data);

// initialize_exit.c
void		initialize_exit(t_game *data);

// movement.c
void		keypress(mlx_key_data_t keydata, void *param);

// track_position.c
void		track_up(t_game *data);
void		track_down(t_game *data);
void		track_left(t_game *data);
void		track_right(t_game *data);

// second_animation_collectible.c
void		collect(void *data);

// second_animation_exit.c
void		exit_a(void *param);

// show_info.c
void		fps(void *param);

// free_data.c
void		free_data(t_game *data);

#endif
