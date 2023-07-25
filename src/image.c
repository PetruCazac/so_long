/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:02:13 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/25 16:12:14 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	init_image(mlx_t *mlx, char **map)
{
	t_game	*data;
	
	data = initialize_data(map, mlx);
	initialize_background(data);
	put_background(data);
	initialize_player(data);
	initialize_exit(data);
	initialize_collectible(data);
	mlx_loop_hook(mlx, &collect, (void *) data);
	mlx_loop_hook(mlx, &collectible_hook, (void *) data);
	mlx_loop_hook(mlx, &exit_hook, (void *) data);
	mlx_loop_hook(mlx, &player_static_hook, (void *) data);
	mlx_key_hook(mlx, keypress, data);
	mlx_loop(mlx);
	return ;
}

void	keypress(mlx_key_data_t keydata, void* param)
{
	t_game		*data;

	data = (t_game*) param;
	if ((keydata.key == 87) && (keydata.action == 1 || keydata.action == 2))
			track_up(data);
	if ((keydata.key == 68) && (keydata.action == 1 || keydata.action == 2))
			track_right(data);
	if ((keydata.key == 83) && (keydata.action == 1 || keydata.action == 2))
			track_down(data);
	if ((keydata.key == 65) && (keydata.action == 1 || keydata.action == 2))
			track_left(data);
	if (keydata.key == 256 && keydata.action == 1)
	{
		mlx_close_window(data->mlx);
	}
	if (data->player_img != NULL)
		mlx_delete_image(data->mlx, data->player_img);
	mlx_loop_hook(data->mlx, &player_moving_hook, (void *) data);
}
