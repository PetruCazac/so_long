/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:00:28 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/20 17:16:28 by pcazac           ###   ########.fr       */
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

typedef struct	animation_list
{
	struct animation_list	*next;
	struct animation_list	*previous;
	mlx_texture_t			*texture;
	mlx_image_t				*image;
	int						pos_x;
	int						pos_y;
}				animation_l;

typedef struct	element_list
{
	int						height;
	int						width;
	int						position_x;
	int						position_y;
	int						score;
	int						c_count;
	int						time;
	char					**map;
	mlx_t					*mlx;
	struct texture_pointers	*texture;
	struct image_pointers	*image;
	struct animation_list	*player;
	struct animation_list	*collectible;
	struct animation_list	*exit;
	struct collectible_list	*c_pos;
}				gameplay;

typedef	struct	collectible_list
{
	struct collectible_list *next;
	int						p_x;
	int						p_y;
}				c_position_l;

typedef	struct texture_pointers
{
	mlx_texture_t	*walls;
	mlx_texture_t	*ground;

}				texture_p;

typedef	struct image_pointers
{
	mlx_image_t	*walls;
	mlx_image_t	*ground;

}				image_p;

int			check_all(int argc);
char		**parser(char *file);
void		purge(char **map);
void		find_path(char **map);
char 		**copymap(char **map);
void		free_array(char **arr);
void		init_image(mlx_t *mlx, char **map);
void		initialize_background(gameplay *data);
void		put_background(gameplay *data);
void		initialize_player(gameplay *data);
animation_l	*add_image(gameplay *data, char *path);
int			new_image(animation_l *node, animation_l *obj, gameplay *data);
void		get_position(char **map, char element, gameplay *data);
void		player_hook(void *param);
void		exit_hook(void *param);
void		collectible_hook(void *param);
void		initialize_collectible(gameplay *data);
void		initialize_exit(gameplay *data);
gameplay	*initialize_data(char **map, mlx_t *mlx);

#endif
