/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_background.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:30:27 by pcazac            #+#    #+#             */
/*   Updated: 2023/08/24 18:25:00 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	initialize_background(t_game *data)
{
	data->texture.walls = mlx_load_png("Textures/Tile_Textures/Grass1.png");
	data->texture.ground = mlx_load_png("Textures/Tile_Textures/Walls.png");
	data->image.walls = mlx_texture_to_image(data->mlx, data->texture.walls);
	data->image.ground = mlx_texture_to_image(data->mlx, data->texture.ground);
	mlx_resize_image(data->image.walls, I_SIZE, I_SIZE);
	mlx_resize_image(data->image.ground, I_SIZE, I_SIZE);
}

void	put_background(t_game *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == '1')
				mlx_image_to_window(data->mlx, data->image.walls, \
									j * I_SIZE, i * I_SIZE);
			else if (data->map[i][j] == '0' || data->map[i][j] == 'C' || \
					data->map[i][j] == 'P' || data->map[i][j] == 'E')
				mlx_image_to_window(data->mlx, data->image.ground, \
									j * I_SIZE, i * I_SIZE);
		}
	}
}
