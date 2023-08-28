/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:39:39 by pcazac            #+#    #+#             */
/*   Updated: 2023/08/28 11:22:54 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"
/// @brief It analyses the key that was pressed and redirects to the action
/// @param keydata The data of the key that was pressed
/// @param param The general linked list about the game
void	keypress(mlx_key_data_t keydata, void *param)
{
	t_game	*data;

	data = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == 1)
		free_data(data);
	if (!data->exited)
		return ;
	if (mlx_is_key_down(data->mlx, 87))
		track_up(data);
	if (mlx_is_key_down(data->mlx, 68))
		track_right(data);
	if (mlx_is_key_down(data->mlx, 83))
		track_down(data);
	if (mlx_is_key_down(data->mlx, 65))
		track_left(data);
	if (data->player_img != NULL)
		mlx_delete_image(data->mlx, data->player_img);
	mlx_loop_hook(data->mlx, &player_moving_hook, (void *) data);
}
