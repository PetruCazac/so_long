/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:02:13 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/20 17:57:59 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void keypress(mlx_key_data_t keydata, void* param)
{
	gameplay	*data;

	data = (gameplay*) param;
	if (keydata.key == 87 && keydata.action == 2)
		data->player->image->instances[0].y -= 10;
	if (keydata.key == 68 && keydata.action == 2)
		data->player->image->instances[0].x += 10;
	if (keydata.key == 83 && keydata.action == 2)
		data->player->image->instances[0].y += 10;
	if (keydata.key == 65 && keydata.action == 2)
		data->player->image->instances[0].x -= 10;
	
}

void	init_image(mlx_t *mlx, char **map)
{
	gameplay	*data;
	
	data = initialize_data(map, mlx);
	initialize_background(data);
	put_background(data);
	initialize_player(data);
		ft_printf("here1\n");
	initialize_collectible(data);
	initialize_exit(data);
	mlx_key_hook(mlx, keypress, data);
	mlx_loop_hook(mlx, &player_hook, (void *) data);
	mlx_loop_hook(mlx, &exit_hook, (void *) data);
	mlx_loop_hook(mlx, &collectible_hook, (void *) data);
	mlx_loop(mlx);
	return ;
}
