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

void initialize(gameplay *data)
{
	data->texture->walls = mlx_load_png("Textures/Tile_Textures/Grass1.png");
	data->texture->ground = mlx_load_png("Textures/Tile_Textures/Walls.png");
	// data->texture->collectible = mlx_load_png("Textures/Collectible/Player1.png");
	// data->texture->exit = mlx_load_png("Textures/Fire/fire1.png");
	
	data->image->walls = mlx_texture_to_image(data->mlx, data->texture->walls);
	data->image->ground = mlx_texture_to_image(data->mlx, data->texture->ground);
	// data->image->collectible = mlx_texture_to_image(data->mlx, data->texture->collectible);
	// data->image->exit = mlx_texture_to_image(data->mlx, data->texture->exit);

	mlx_resize_image(data->image->walls, 50, 50);
	mlx_resize_image(data->image->ground, 50, 50);
	// mlx_resize_image(data->image->collectible, 50, 50);
	// mlx_resize_image(data->image->exit, 50, 50);
}

void	put_image(gameplay *data)
{
	int i;
	int j;
	int	count[2];

	count[0] = 0;
	count[1] = 0;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
			{
				mlx_image_to_window(data->mlx, data->image->walls, count[0], count[1]);
				count[0] += 50;
			}
			else if (data->map[i][j] == '0')
			{
				mlx_image_to_window(data->mlx, data->image->ground, count[0], count[1]);
				count[0] += 50;
			}
			else if (data->map[i][j] == 'C')
			{
				mlx_image_to_window(data->mlx, data->image->ground, count[0], count[1]);
				// mlx_image_to_window(mlx, image->collectible, count[0], count[1]);
				count[0] += 50;
			}
			else if (data->map[i][j] == 'E')
			{
				mlx_image_to_window(data->mlx, data->image->ground, count[0], count[1]);
				// mlx_image_to_window(mlx, image->exit, count[0], count[1]);
				count[0] += 50;
			}
			if (data->map[i][j] == 'P')
			{
				mlx_image_to_window(data->mlx, data->image->ground, count[0], count[1]);
				data->player->pos_x = count[0];
				data->player->pos_y = count[1];
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

void initialize_player(gameplay *data, mlx_t *mlx)
{
	animation_l	*obj;
	animation_l	*temp;
	animation_l	*temp2;

	obj = data->player;
	temp = obj;
	temp->texture = mlx_load_png("Textures/Vampire/Vampire1.png");
	temp->image = mlx_texture_to_image(mlx, temp->texture);
	mlx_resize_image(temp->image, 50, 50);
	temp = malloc(1*sizeof(animation_l));
	obj->next = temp;
	temp->pos_x = obj->pos_x;
	temp->pos_y = obj->pos_y;
	temp->texture = mlx_load_png("Textures/Vampire/Vampire2.png");
	temp->image = mlx_texture_to_image(mlx, temp->texture);
	mlx_resize_image(temp->image, 50, 50);
	temp2 = malloc(1*sizeof(animation_l));
	temp->next = temp2;
	temp2->pos_x = temp->pos_x;
	temp2->pos_y = temp->pos_y;
	temp = temp->next;
	temp->texture = mlx_load_png("Textures/Vampire/Vampire3.png");
	temp->image = mlx_texture_to_image(mlx, temp->texture);
	mlx_resize_image(temp->image, 50, 50);
	temp2 = malloc(1*sizeof(animation_l));
	temp->next = temp2;
	temp2->pos_x = temp->pos_x;
	temp2->pos_y = temp->pos_y;
	temp = temp->next;
	temp->texture = mlx_load_png("Textures/Vampire/Vampire4.png");
	temp->image = mlx_texture_to_image(mlx, temp->texture);
	mlx_resize_image(temp->image, 50, 50);
	temp->next = obj;
}

// void image_to_window(mlx_t *mlx, mlx_image_t *image, int pos_x, int pos_y)
// {
// 	mlx_image_to_window(mlx, image, pos_x, pos_y);
// }