/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_animation_collectible.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:51:27 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/24 16:55:53 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	delete_collectible(t_game *data, int x, int y)
{
	t_animation	*temp;

	temp = data->collectible;
	while (temp)
	{
		if ()
	}
}
void put_new_collectible(t_game *data, int **p)
{
	
}

bool	check_collectible(t_game *data, int **p)
{
	if ( data->map[p[0][1] / 100][(p[0][0] - STEP) / 100] == 'C')
		return(true);
	else if ( data->map[p[0][1] / 100][(p[0][0] - STEP) / 100] == 'C')
		return(true);
	else if ( data->map[p[0][1] / 100][(p[0][0] - STEP) / 100] == 'C')
		return(true);
	else if ( data->map[p[0][1] / 100][(p[0][0] - STEP) / 100] == 'C')
		return(true);
	else
		return (false);
}

void	collect(void *param)
{
	t_game			*data;
	int				p[4][2];
	mlx_image_t		img;
	mlx_texture_t	img;

	data = (t_game*) param;

	p[0][0] = data->p_x;
	p[0][1] = data->p_y;
	p[1][0] = data->p_x;
	p[1][1] = data->p_y + 50;
	p[2][0] = data->p_x + 50;
	p[2][1] = data->p_y;
	p[3][0] = data->p_x + 50;
	p[3][1] = data->p_y + 50;
	
	if (check_collectible(data, p))
	{
		delete_collectible(data, x, y);
		put_new_collectible(data, p);
	}
}
