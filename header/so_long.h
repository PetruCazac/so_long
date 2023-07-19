/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:00:28 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/19 17:58:40 by pcazac           ###   ########.fr       */
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
	int					height;
	int					width;
	int					position_x;
	int					position_y;
	int					score;
	int					collectibles;
	mlx_t				*mlx;
	struct image_l		*player;
	struct image_l		*collectible;
	struct image_l		*exit;
	struct texture_pointers	*texture;
	struct image_pointers	*image;
}				gameplay;

typedef	struct	background_textures
{
	char	*walls;
	char	*ground;
	char	*exit;
	char	*collectible;
}				background_t;

typedef	struct texture_pointers
{
	mlx_texture_t	*walls;
	mlx_texture_t	*ground;
	mlx_texture_t	*exit;
	mlx_texture_t	*collectible;
}				texture_p;

typedef	struct image_pointers
{
	mlx_image_t	*walls;
	mlx_image_t	*ground;
	mlx_image_t	*exit;
	mlx_image_t	*collectible;
	mlx_image_t	*player;
}				image_p;

typedef struct	texture_list
{
	struct texture_list	*next;
	mlx_texture_t		*texture;
}				texture_l;

typedef struct	image_list
{
	struct image_list	*next;
	mlx_image_t			*image;
}				image_l;

int		check_all(int argc);
char	**parser(char *file);
void	purge(char **map);
void	find_path(char **map);
char 	**copymap(char **map);
void	free_array(char **arr);
void	init_image(mlx_t *mlx, char **map);
void	initialize(mlx_t *mlx, image_p *image, texture_p *texture);
void	put_image(mlx_t *mlx, image_p *image, char **map);

#endif
