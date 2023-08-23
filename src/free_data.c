/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:23:38 by pcazac            #+#    #+#             */
/*   Updated: 2023/08/23 18:12:49 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../header/so_long.h"

void	free_background(t_game *data)
{
	if (data->texture.walls)
	{
		mlx_delete_texture(data->texture.walls);
		data->texture.walls = NULL;
	}
	if (data->texture.ground)
	{
		mlx_delete_texture(data->texture.ground);
		data->texture.ground = NULL;
	}
	if (data->image.walls)
	{
		mlx_delete_image(data->mlx, data->image.walls);
		data->image.walls = NULL;
	}
	if (data->image.ground)
	{
		mlx_delete_image(data->mlx, data->image.ground);
		data->image.ground = NULL;
	}
}

void	free_animation(t_animation *ptr)
{
	t_animation	*temp;
	t_animation	*temp2;

	temp = ptr;
	while(temp)
	{
		temp2 = temp;
		temp = temp->end;
		if (temp2->texture)
		{
			mlx_delete_texture(temp2->texture);
			temp2->texture = NULL;
		}
		free(temp2);
		temp2 = NULL;
	}
}

void	free_image(mlx_t *mlx, t_cimage *ptr)
{
	t_cimage	*temp;
	t_cimage	*temp2;

	temp = ptr;
	while(temp)
	{
		temp2 = temp;
		temp = temp->next;
		if (temp2->image)
		{
			mlx_delete_image(mlx, temp2->image);
			temp2->image = NULL;
		}
		free(temp2);
		temp2 = NULL;
	}
}


void	free_data(t_game *data)
{
	if (data->map)
	{
		free_array(data->map);
		data->map = NULL;
	}
	free_background(data);
	free_animation(data->player);
	free_animation(data->collectible);
	free_animation(data->collected);
	free_animation(data->exit);
	free_animation(data->exit_valid);
	free_image(data->mlx, data->c_image);
	if (data->player_img)
	{
		mlx_delete_image(data->mlx, data->player_img);
		data->player_img = NULL;
	}
	if (data->exit_image)
	{
		mlx_delete_image(data->mlx, data->exit_image);
		data->exit_image = NULL;
	}
	mlx_close_window(data->mlx);
	mlx_terminate(data->mlx);
	free(data);
	exit(0);
}
