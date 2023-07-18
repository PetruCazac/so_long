/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:00:28 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/18 17:59:13 by pcazac           ###   ########.fr       */
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

#define WIDTH 700
#define HEIGHT 600

typedef struct	element_list
{
	int				coordinate[2];
}				player;

typedef	struct	background_textures
{
	char	*walls;
	char	*ground;
	char	*exit;
	char	*collectible;
}				background_t;

typedef	struct texture_pointers
{
	mlx_texture_t	*t_walls;
	mlx_texture_t	*t_ground;
	mlx_texture_t	*t_exit;
	mlx_texture_t	*t_collectible;
}				texture_p;

typedef	struct image_pointers
{
	mlx_image_t	*i_walls;
	mlx_image_t	*i_ground;
	mlx_image_t	*i_exit;
	mlx_image_t	*i_collectible;
}				image_p;


int		check_all(int argc);
char	**parser(char *file);
void	purge(char **map);
void	find_path(char **map);
char 	**copymap(char **map);
void	free_array(char **arr);

#endif
