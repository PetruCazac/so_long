/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:41:03 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/22 21:09:38 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

t_animation	*new_texture(char *path)
{
	t_animation	*temp;

	temp = ft_calloc(1, sizeof(t_animation));
	if (temp == NULL)
		exit(errno); // Freeall!!!
	temp->texture = mlx_load_png(path);
	return (temp);
}

int	add_texture(t_animation *node, t_animation **obj)
{
	t_animation	*temp;

	if (node == NULL)
		exit(errno);
		// All the memory has to be freed!!!
	if (*obj != NULL)
	{
		temp = *obj;
		while (temp->end)
			temp = temp->next;
		temp->next = node;
		node->previous = temp;
		node->next = *obj;
		(*obj)->previous = node;
		node->end = NULL;
		temp->end = node;
	}
	else
	{
		*obj = node;
		node->previous = *obj;
		node->next = *obj;
		node->end = NULL;
	}
	return (0);
}

t_game	*initialize_data(char **map, mlx_t *mlx)
{
	t_game	*data;

	data = ft_calloc(1, sizeof(t_game));
	if (data == NULL)
		exit(errno); // Free everyhting!!!
	data->height = ft_strlen_arr(map);
	data->width = ft_strlen(map[0]);
	data->p_x = 0;
	data->p_y = 0;
	data->e_x = 0;
	data->e_y = 0;
	data->score = 0;
	data->c_count = 0;
	data->time = 0;
	data->time_p = 0;
	data->player = NULL;
	data->collectible = NULL;
	data->exit = NULL;
	data->c_pos = NULL;
	data->map = map;
	data->mlx = mlx;
	data->texture.walls = NULL;
	data->texture.ground = NULL;
	data->image.walls = NULL;
	data->image.ground = NULL;
	data->c_image = NULL;
	data->player_img = NULL;
	return (data);
}

t_cimage	*new_cnode()
{
	t_cimage	*tmp;

	tmp = malloc(sizeof(t_cimage));
	if (tmp)
	{
		tmp->image =  NULL;
		tmp->next = NULL;
	}
	return (tmp);
}

void add_back_image(t_cimage *node, t_game *data)
{
	t_cimage	*temp;

	if (data->c_image == NULL)
	{
		data->c_image = node;
		return ;
	}
	temp = data->c_image;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = node;
}
