/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_collectible.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:31:06 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/20 17:17:50 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	new_cimage(animation_l *node, gameplay *data)
{
	animation_l	*temp;

	if (node == NULL)
		exit(errno);
		// All the memory has to be freed!!!
	if (data->collectible != NULL)
	{
		temp = data->collectible;
		while (temp->next != data->collectible && temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = node;
		node->previous = temp;
		node->next = data->collectible;
		node->pos_x = data->c_pos->p_x;
		node->pos_y = data->c_pos->p_y;
		data->collectible->previous = node;
	}
	else
	{
		data->collectible = node;
		node->previous = data->collectible;
		node->next = data->collectible;
		node->pos_x = data->c_pos->p_x;
		node->pos_y = data->c_pos->p_y;
	}
	return (0);
}

char	**get_collectible_path(void)
{
	char **path;

	path = ft_calloc(9, sizeof(char *));
	path[0] = ft_strdup("Textures/Collectible/Player1.png");
	path[1] = ft_strdup("Textures/Collectible/Player2.png");
	path[2] = ft_strdup("Textures/Collectible/Player3.png");
	path[3] = ft_strdup("Textures/Collectible/Player4.png");
	path[4] = ft_strdup("Textures/Collectible/Player5.png");
	path[5] = ft_strdup("Textures/Collectible/Player6.png");
	path[6] = ft_strdup("Textures/Collectible/Player7.png");
	path[7] = ft_strdup("Textures/Collectible/Player8.png");
	path[8] = "\0";
	return (path);
}

void	new_pos(int y, int x, gameplay *data)
{
	c_position_l	*temp;
	c_position_l	*temp2;

	temp2 = data->c_pos;
	ft_printf("pointer %p\n", data->c_pos);
	ft_printf("New node :i = %i, j = %i\n", y, x);
	temp = ft_calloc(1, sizeof(c_position_l));
	if (temp == NULL)
	{
		ft_printf("Malloc Error");
		exit(errno);
	}
	if (temp2 == NULL)
	{
		data->c_pos = temp;
		temp->p_x = x * I_SIZE;
		temp->p_y = y * I_SIZE;
		temp->next = NULL;
		return ;
	}
	if (temp2 != NULL)
	{
		while (temp2->next != NULL)
			temp2 = temp2->next;
		ft_printf("here2\n");
		temp2->next = temp;
		temp->p_x = x * I_SIZE;
		temp->p_y = y * I_SIZE;
		temp->next = NULL;
	}
	temp = data->c_pos;
	while (temp->next)
	{
		ft_printf("Struct: %i, %i\n", temp->p_x, temp->p_y);
		temp = temp->next;
	}
}

void	get_cposition(gameplay *data, char **map, char elem)
{
	int i;
	int j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == elem)
			{
				new_pos(i, j, data);
			}
			j++;
		}
		i++;
	}
}

void initialize_collectible(gameplay *data)
{
	int				i;
	char			**path;
	c_position_l	*temp;
	c_position_l	*temp2;

	get_cposition(data, data->map, 'C');
	path = get_collectible_path();
	ft_printf("here3\n");
	i = 0;
	temp = data->c_pos;
	temp2 = temp;
	while (temp2->next != NULL)
	{
		ft_printf("%i, %i\n", temp2->p_x, temp2->p_y);
		temp2 = temp2->next;
	}
	while (temp->next != NULL)
	{
		i = 0;
		while (path[i] != NULL && path[i][0] != '\0')
		{
			if (new_cimage(add_image(data, path[i]), data) == 1)
				return ; // free everything
			i++;
		}
		ft_printf("here4\n");
		temp = temp->next;
	}
}

void	collectible_hook(void *param)
{
	gameplay		*data;
	c_position_l	*temp;
	data = (gameplay*) param;
	temp = data->c_pos;
	if (data->time > 5)
	{
		while (data->c_pos)
		{
			data->collectible->image->enabled = 1;
			data->collectible->previous->image->enabled = 0;
			mlx_image_to_window(data->mlx, data->collectible->image, data->c_pos->p_x, data->c_pos->p_y);
			mlx_set_instance_depth(data->collectible->image->instances, 255);
			temp = temp->next;
		}
		data->collectible = data->collectible->next;
		data->time = 0;
	}
	//next frame
}
