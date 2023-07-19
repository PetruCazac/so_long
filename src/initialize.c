/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:11:32 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/19 17:57:15 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void initialize(mlx_t *mlx, image_p *image, texture_p *texture)
{
	texture->walls = mlx_load_png("Textures/Tile_Textures/Grass1.png");
	texture->ground = mlx_load_png("Textures/Tile_Textures/Walls.png");
	texture->collectible = mlx_load_png("Textures/Collectible/Player1.png");
	texture->exit = mlx_load_png("Textures/Fire/fire1.png");
	
	image->walls = mlx_texture_to_image(mlx, texture->walls);
	image->ground = mlx_texture_to_image(mlx, texture->ground);
	image->collectible = mlx_texture_to_image(mlx, texture->collectible);
	image->exit = mlx_texture_to_image(mlx, texture->exit);

	mlx_resize_image(image->walls, 50, 50);
	mlx_resize_image(image->ground, 50, 50);
	mlx_resize_image(image->collectible, 50, 50);
	mlx_resize_image(image->exit, 50, 50);
}

void	put_image(mlx_t *mlx, image_p *image, char **map)
{
	int i;
	int j;
	int	count[2];

	count[0] = 0;
	count[1] = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
			{
				mlx_image_to_window(mlx, image->walls, count[0], count[1]);
				count[0] += 50;
			}
			else if (map[i][j] == '0')
			{
				mlx_image_to_window(mlx, image->ground, count[0], count[1]);
				count[0] += 50;
			}
			else if (map[i][j] == 'C')
			{
				mlx_image_to_window(mlx, image->ground, count[0], count[1]);
				mlx_image_to_window(mlx, image->collectible, count[0], count[1]);
				count[0] += 50;
			}
			else if (map[i][j] == 'E')
			{
				mlx_image_to_window(mlx, image->ground, count[0], count[1]);
				mlx_image_to_window(mlx, image->exit, count[0], count[1]);
				count[0] += 50;
			}
			if (map[i][j] == 'P')
			{
				mlx_image_to_window(mlx, image->ground, count[0], count[1]);
				// mlx_image_to_window(mlx, image->player, count[0], count[1]);
				count[0] += 50;
			}
			j++;
		}
		count[0] = 0;
		count[1] += 50;
		i++;
	}
}

// void initialize_player(texture, image, mlx)
// {
	
// }
