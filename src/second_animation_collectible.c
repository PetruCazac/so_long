/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_animation_collectible.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:51:27 by pcazac            #+#    #+#             */
/*   Updated: 2023/08/23 19:17:58 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

/// @brief Deletes the collectible image once touched by the player
/// @param data Game general data
/// @param y Player y position 
/// @param x Player x position
void	delete_collectible(t_game *data, int y, int x)
{
	t_cimage	*image;

	image = data->c_image;
	while (image)
	{
		if (image->touch && image->p_x == ((x / I_SIZE) * I_SIZE) && \
			image->p_y == ((y / I_SIZE) * I_SIZE))
		{
			if (image)
			{
				mlx_delete_image(data->mlx, image->image);
				image->touch = false;
				data->score++;
			}
		}
		image = image->next;
	}
}

/// @brief Detects if the player is on a collectible tile
/// @param param General game data
void	collect(void *param)
{
	t_game			*data;
	int				p[2];

	data = (t_game *) param;
	p[0] = data->p_x + (P_SIZE / 2);
	p[1] = data->p_y + (P_SIZE / 2);
	if (data->map[p[1] / I_SIZE][(p[0]) / I_SIZE] == 'C')
		delete_collectible(data, p[1], p[0]);
	else
		return ;
}
