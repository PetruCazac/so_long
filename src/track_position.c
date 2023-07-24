/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 21:27:59 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/24 15:53:27 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	track_up(t_game *data)
{
	int	p[4][2];

	p[0][0] = data->p_x;
	p[0][1] = data->p_y;
	p[1][0] = data->p_x;
	p[1][1] = data->p_y + 50;
	p[2][0] = data->p_x + 50;
	p[2][1] = data->p_y;
	p[3][0] = data->p_x + 50;
	p[3][1] = data->p_y + 50;
	if ( data->map[(p[0][1] - STEP) / 100][p[0][0] / 100] == '1')
		return ;
	else if (data->map[(p[2][1] - STEP) / 100][p[2][0] / 100] == '1')
		return ;
	else
		data->p_y -= STEP;
}

void	track_down(t_game *data)
{
	int	p[4][2];

	p[0][0] = data->p_x;
	p[0][1] = data->p_y;
	p[1][0] = data->p_x;
	p[1][1] = data->p_y + 50;
	p[2][0] = data->p_x + 50;
	p[2][1] = data->p_y;
	p[3][0] = data->p_x + 50;
	p[3][1] = data->p_y + 50;
	if ( data->map[(p[1][1] + STEP) / 100][p[1][0] / 100] == '1')
		return ;
	else if (data->map[(p[3][1] + STEP) / 100][p[3][0] / 100] == '1')
		return ;
	else
		data->p_y += STEP;
}

void	track_left(t_game *data)
{
	int	p[4][2];

	p[0][0] = data->p_x;
	p[0][1] = data->p_y;
	p[1][0] = data->p_x;
	p[1][1] = data->p_y + 50;
	p[2][0] = data->p_x + 50;
	p[2][1] = data->p_y;
	p[3][0] = data->p_x + 50;
	p[3][1] = data->p_y + 50;
	if ( data->map[p[0][1] / 100][(p[0][0] - STEP) / 100] == '1')
		return ;
	else if (data->map[p[1][1] / 100][(p[1][0] - STEP) / 100] == '1')
		return ;
	else
		data->p_x -= STEP;
}

void	track_right(t_game *data)
{
	int	p[4][2];

	p[0][0] = data->p_x;
	p[0][1] = data->p_y;
	p[1][0] = data->p_x;
	p[1][1] = data->p_y + 50;
	p[2][0] = data->p_x + 50;
	p[2][1] = data->p_y;
	p[3][0] = data->p_x + 50;
	p[3][1] = data->p_y + 50;
	if ( data->map[p[2][1] / 100][(p[2][0] + STEP)/ 100] == '1')
		return ;
	else if (data->map[p[3][1] / 100][(p[3][0] + STEP) / 100] == '1')
		return ;
	else
		data->p_x += STEP;
}
