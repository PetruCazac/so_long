/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_animation_collectible.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:51:27 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/27 14:37:25 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	delete_collectible(t_game *data, int y, int x)
{
	t_cimage	*temp;

	temp = data->c_image;
	while (temp)
	{
		if (temp->p_x == ((x / I_SIZE) * I_SIZE) && temp->p_y == ((y / I_SIZE) * I_SIZE) && temp->touch)
		{
			if (temp)
			{
				mlx_delete_image(data->mlx, temp->image);
				temp->touch = false;
				data->score++;
			}
		}
		temp = temp->next;
	}
}

void	collect(void *param)
{
	t_game			*data;
	int				p[2];

	data = (t_game*) param;
	// Find the middle and operate with it. 
	p[0] = data->p_x + (P_SIZE / 2);
	p[1] = data->p_y + (P_SIZE / 2);
	if ( data->map[p[1] / I_SIZE][(p[0]) / I_SIZE] == 'C')
		delete_collectible(data, p[1], p[0]);
	else
		return ;

}
