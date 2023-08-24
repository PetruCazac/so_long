/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:20:06 by pcazac            #+#    #+#             */
/*   Updated: 2023/08/24 20:27:19 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	to_collect(t_cimage *temp, t_game *data)
{
	if (temp->image != NULL)
		mlx_delete_image(data->mlx, temp->image);
	temp->image = mlx_texture_to_image(data->mlx, data->collectible->texture);
	mlx_resize_image(temp->image, P_SIZE, P_SIZE);
	mlx_image_to_window(data->mlx, temp->image, temp->p_x, temp->p_y);
	mlx_set_instance_depth(temp->image->instances, 253);
}

void	collected(t_cimage *temp, t_game *data)
{
	if (temp->image != NULL)
		mlx_delete_image(data->mlx, temp->image);
	temp->image = mlx_texture_to_image(data->mlx, data->collected->texture);
	mlx_resize_image(temp->image, P_SIZE, P_SIZE);
	mlx_image_to_window(data->mlx, temp->image, temp->p_x, temp->p_y);
	mlx_set_instance_depth(temp->image->instances, 253);
}
