/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:02:13 by pcazac            #+#    #+#             */
/*   Updated: 2023/08/23 11:53:59 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	init_image(t_game *data)
{
	initialize_background(data);
	put_background(data);
	initialize_player(data);
	initialize_exit(data);
	initialize_collectible(data);
	mlx_loop_hook(data->mlx, &fps, (void *) data);
	mlx_loop_hook(data->mlx, &exit_a, (void *) data);
	mlx_loop_hook(data->mlx, &collect, (void *) data);
	mlx_loop_hook(data->mlx, &collectible_hook, (void *) data);
	mlx_loop_hook(data->mlx, &player_static_hook, (void *) data);
	mlx_key_hook(data->mlx, keypress, (void *) data);
	mlx_loop_hook(data->mlx, &exit_hook, (void *) data);
	mlx_loop(data->mlx);
	return ;
}
