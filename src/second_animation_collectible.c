/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_animation_collectible.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:51:27 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/25 18:08:28 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

// void put_new_collectible()
// {
// 	mlx_texture_t	texture;

// 	texture = mlx_load_png("Textures/Collectible/Player_Dead.jpg");
// 	image_p = mlx_texture_to_image(data->mlx, data->player->texture);

// }

void	delete_node(t_cimage *list, t_game *data)
{
	t_cimage	*temp;

	temp = data->c_image;
	if (temp == list)
	{
		if (list->next)
		{
			data->c_image = list->next;
			list->p_x = 0;
			list->p_y = 0;
			free(list);
			return ;
		}
		if (list->next == NULL)
		{
			data->c_image = NULL;
			list->p_x = 0;
			list->p_y = 0;
			free(list);
			return ;
		}
	}
	ft_printf("delete_node\n");
	while (list == temp->next)
		temp = temp->next;
	temp->next = list->next;
	free(list);
	return ;
}

void	delete_collectible(t_game *data, int x, int y)
{
	t_cimage	*temp;

	ft_printf("delete : x = %i , y = %i\n", x, y);
	temp = data->c_image;
	while (temp)
	{
		if (temp->p_x == ((x / 100) * 100) && temp->p_y == ((y / 100) * 100))
		{
			if (temp)
			{
				ft_printf("temp_x = %i , temp_y = %i\n", temp->p_x, temp->p_y);
				mlx_delete_image(data->mlx, temp->image);
				delete_node(temp, data);
				// put_new_collectibl(temp);
			}
		}
		temp = temp->next;
	}
}

void	check_collectible(t_game *data, int (*p)[2])
{
	if ( data->map[p[0][1] / 100][(p[0][0] - STEP) / 100] == 'C')
		delete_collectible(data, p[0][1], p[0][0]);
	else if ( data->map[p[1][1] / 100][(p[1][0] - STEP) / 100] == 'C')
		delete_collectible(data, p[1][1], p[1][0]);
	else if ( data->map[p[2][1] / 100][(p[2][0] - STEP) / 100] == 'C')
		delete_collectible(data, p[2][1], p[2][0]);
	else if ( data->map[p[3][1] / 100][(p[3][0] - STEP) / 100] == 'C')
		delete_collectible(data, p[3][1], p[3][0]);
	else
		return ;
}

void	collect(void *param)
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
	check_collectible(data, p);
}
