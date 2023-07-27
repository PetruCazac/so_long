/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_animation_exit.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:51:27 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/25 18:08:28 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void end_of_game(t_game *data)
{
	static mlx_image_t	*t;
	int					i[1];

	*i = 4;
	if (t)
		mlx_delete_image(data->mlx, t);
	t = mlx_put_string(data->mlx, "YOU WIN!", (data->width * I_SIZE) / 2 , (data->height * I_SIZE)/ 2);
	mlx_set_instance_depth(t->instances, 249);
	wait(i);
	// exit_strategy(data);
}

void	delete_exit(t_game *data, int y, int x)
{
	if (data->exit_image == NULL)
		return ;
	if (data->e_x == ((x / I_SIZE) * I_SIZE) && data->e_y == ((y / I_SIZE) * I_SIZE) && !data->exit_touch)
	{
		end_of_game(data);
		data->exited = false;
	}
}

void	check_exit(t_game *data, int (*p)[2])
{
	if ( data->map[p[0][1] / I_SIZE][(p[0][0]) / I_SIZE] == 'E')
		delete_exit(data, p[0][1], p[0][0]);
	else if ( data->map[p[1][1] / I_SIZE][(p[1][0]) / I_SIZE] == 'E')
		delete_exit(data, p[1][1], p[1][0]);
	else if ( data->map[p[2][1] / I_SIZE][(p[2][0]) / I_SIZE] == 'E')
		delete_exit(data, p[2][1], p[2][0]);
	else if ( data->map[p[3][1] / I_SIZE][(p[3][0]) / I_SIZE] == 'E')
		delete_exit(data, p[3][1], p[3][0]);
	else
		return ;
}

void	exit_a(void *param)
{
	t_game			*data;
	int				p[4][2];

	data = (t_game*) param;
	if (data->score == data->c_count && data->exit_touch)
	{
		mlx_delete_image(data->mlx, data->exit_image);
		data->exit_touch = false;
		return ;
	}
	p[0][0] = data->p_x;
	p[0][1] = data->p_y;
	p[1][0] = data->p_x;
	p[1][1] = data->p_y + P_SIZE;
	p[2][0] = data->p_x + P_SIZE;
	p[2][1] = data->p_y;
	p[3][0] = data->p_x + P_SIZE;
	p[3][1] = data->p_y + P_SIZE;
	check_exit(data, p);
}
