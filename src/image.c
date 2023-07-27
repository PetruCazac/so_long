/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:02:13 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/27 13:40:01 by pcazac           ###   ########.fr       */
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
	mlx_loop_hook(mlx, &fps, (void *) data);
	mlx_loop_hook(mlx, &exit_a, (void *) data);
	mlx_loop_hook(mlx, &collect, (void *) data);
	mlx_loop_hook(mlx, &collectible_hook, (void *) data);
	mlx_loop_hook(mlx, &exit_hook, (void *) data);
	mlx_loop_hook(mlx, &player_static_hook, (void *) data);
	mlx_key_hook(mlx, keypress, data);
	mlx_loop(mlx);
	return ;
}
