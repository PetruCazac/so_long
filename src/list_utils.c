/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:41:03 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/20 18:05:59 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

animation_l	*add_image(gameplay *data, char *path)
{
	animation_l	*temp;

	temp = ft_calloc(1, sizeof(animation_l));
	if (temp == NULL)
		exit(errno); // Freeall!!!
	temp->texture = mlx_load_png(path);
	temp->image = mlx_texture_to_image(data->mlx, temp->texture);
	mlx_resize_image(temp->image, I_SIZE, I_SIZE);
	return (temp);
}

int	new_image(animation_l *node, animation_l *obj, gameplay *data)
{
	animation_l	*temp;

	if (node == NULL)
		exit(errno);
		// All the memory has to be freed!!!
	if (obj != NULL)
	{	temp = obj;
		while (temp->next != obj)
			temp = temp->next;
		temp->next = node;
		node->previous = temp;
		node->pos_x = data->position_x;
		node->pos_y = data->position_y;
		node->next = obj;
		obj->previous = node;
	}
	else
	{
		obj = node;
		node->previous = obj;
		node->next = obj;
		node->pos_x = data->position_x;
		node->pos_y = data->position_y;
	}
	return (0);
}

gameplay	*initialize_data(char **map, mlx_t *mlx)
{
	gameplay	*data;

	data = ft_calloc(1, sizeof(gameplay));
	if (data == NULL)
		exit(errno); // Free everyhting!!!
	data->height = ft_strlen_arr(map);
	data->width = ft_strlen(map[0]);
	data->position_x = 0;
	data->position_y = 0;
	data->score = 0;
	data->collectibles = 0;
	data->time = 0;
	data->player = NULL;
	data->collectible = NULL;
	data->exit = NULL;
	data->texture = ft_calloc(1, sizeof(texture_p));
	data->image = ft_calloc(1, sizeof(image_p));
	data->map = map;
	data->mlx = mlx;
	data->c_pos = NULL;
	return (data);
}
