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

// void put_new_exit()
// {
// 	mlx_texture_t	texture;

// 	texture = mlx_load_png("Textures/exit/Player_Dead.jpg");
// 	image_p = mlx_texture_to_image(data->mlx, data->player->texture);

// }

void	delete_exit(t_game *data, int x, int y)
{
	mlx_image_t	*temp;

	ft_printf("delete exit: x = %i , y = %i\n", x, y);
	temp = data->exit_image;
	if (data->e_x == ((x / 100) * 100) && data->e_y == ((y / 100) * 100))
	{
		if (temp)
		{
			ft_printf("exit temp_x = %i , temp_y = %i\n", data->e_x, data->e_y);
			mlx_delete_image(data->mlx, temp);
			free(temp);
			data->exit_image = NULL;
			// put_new_collectibl(temp);
		}
	}
}

void	check_exit(t_game *data, int (*p)[2])
{
	if ( data->map[p[0][1] / 100][(p[0][0] - STEP) / 100] == 'E')
		delete_exit(data, p[0][1], p[0][0]);
	else if ( data->map[p[1][1] / 100][(p[1][0] - STEP) / 100] == 'E')
		delete_exit(data, p[1][1], p[1][0]);
	else if ( data->map[p[2][1] / 100][(p[2][0] - STEP) / 100] == 'E')
		delete_exit(data, p[2][1], p[2][0]);
	else if ( data->map[p[3][1] / 100][(p[3][0] - STEP) / 100] == 'E')
		delete_exit(data, p[3][1], p[3][0]);
	else
		return ;
}

void	exit(void *param)
{
	t_game			*data;
	int				p[4][2];

	data = (t_game*) param;
	p[0][0] = data->p_x;
	p[0][1] = data->p_y;
	p[1][0] = data->p_x;
	p[1][1] = data->p_y + 50;
	p[2][0] = data->p_x + 50;
	p[2][1] = data->p_y;
	p[3][0] = data->p_x + 50;
	p[3][1] = data->p_y + 50;
	check_exit(data, p);
}
