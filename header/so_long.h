/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:00:28 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/24 16:58:43 by pcazac           ###   ########.fr       */
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
# include "../libft/header/libft.h"
#include <errno.h>
#include "../MLX42/include/MLX42/MLX42.h"

#define I_SIZE 100
#define P_SIZE 50
#define ITERATIONS 7
#define STEP 10

typedef struct	s_animation
{
	struct s_animation	*next;
	struct s_animation	*end;
	struct s_animation	*previous;
	mlx_texture_t		*texture;
}				t_animation;

typedef	struct	s_position
{
	struct s_position	*next;
	int					p_x;
	int					p_y;
}				t_position;

typedef	struct s_texture
{
	mlx_texture_t	*walls;
	mlx_texture_t	*ground;

}				t_texture;

typedef	struct s_image
{
	mlx_image_t	*walls;
	mlx_image_t	*ground;

}				t_image;

typedef	struct s_cimage
{
	struct s_cimage		*next;
	mlx_image_t			*image;
	int					p_x;
	int					p_y;
}				t_cimage;

typedef struct	s_element
{
	int			 	height;
	int				width;
	int				p_x;
	int				p_y;
	int				e_x;
	int				e_y;
	int				score;
	int				c_count;
	int				time;
	int				time_p;
	char			**map;
	mlx_t			*mlx;
	t_texture		texture;
	t_image			image;
	t_animation		*player;
	t_animation		*collectible;
	t_animation		*exit;
	// t_position		*c_pos;
	t_cimage		*c_image;
	mlx_image_t		*player_img;
}				t_game;


int			check_all(int argc);
char		**parser(char *file);
void		purge(char **map);
void		find_path(char **map);
char 		**copymap(char **map);
void		free_array(char **arr);
void		put_background(t_game *data);
t_animation	*new_texture(char *path);
int			add_texture(t_animation *node, t_animation **obj);
void		player_hook(void *param);
void		exit_hook(void *param);
void		collectible_hook(void *param);
void		init_image(mlx_t *mlx, char **map);
void		initialize_background(t_game *data);
void		initialize_player(t_game *data);
void		initialize_collectible(t_game *data);
void		initialize_exit(t_game *data);
t_game		*initialize_data(char **map, mlx_t *mlx);
void		player_static_hook(void *param);
void		player_moving_hook(void *param);
t_cimage	*new_cnode(int x, int y);
void		add_back_image(t_cimage *img, t_game *data);
void 		keypress(mlx_key_data_t keydata, void* param);
void		track_up(t_game *data);
void		track_down(t_game *data);
void		track_right(t_game *data);
void		track_left(t_game *data);
void		collect(void *data);

#endif
