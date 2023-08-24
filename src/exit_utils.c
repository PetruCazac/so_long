/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:30:30 by pcazac            #+#    #+#             */
/*   Updated: 2023/08/24 19:18:46 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

/// @brief 
/// @param data 
void	simple_exit(t_game *data)
{
	if (data->exit_image != NULL)
		mlx_delete_image(data->mlx, data->exit_image);
	data->exit_image = mlx_texture_to_image(data->mlx, data->exit->texture);
	mlx_resize_image(data->exit_image, P_SIZE, P_SIZE);
	mlx_image_to_window(data->mlx, data->exit_image, data->e_x, data->e_y);
	mlx_set_instance_depth(data->exit_image->instances, 249);
	data->exit = data->exit->next;
}

/// @brief 
/// @param data 
void	after_exit(t_game *data)
{
	if (data->exit_image != NULL)
		mlx_delete_image(data->mlx, data->exit_image);
	data->exit_image = mlx_texture_to_image(data->mlx, \
											data->exit_valid->texture);
	mlx_resize_image(data->exit_image, P_SIZE, P_SIZE);
	mlx_image_to_window(data->mlx, data->exit_image, data->e_x, data->e_y);
	mlx_set_instance_depth(data->exit_image->instances, 249);
	data->exit_valid = data->exit_valid->next;
}
