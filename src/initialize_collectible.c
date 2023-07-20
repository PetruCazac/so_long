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

int	new_cimage(animation_l *node, animation_l *obj, gameplay *data)
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
		node->pos_x = data->c_pos->p_x;
		node->pos_y = data->c_pos->p_y;
		node->next = obj;
		obj->previous = node;
	}
	else
	{
		obj = node;
		node->previous = obj;
		node->next = obj;
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
	ft_printf("New node :i = %i, j = %i\n", y, x);
	temp = ft_calloc(1, sizeof(c_position_l));
	if (temp == NULL)
		exit(errno);
	if (temp2 == NULL)
	{
		temp2 = temp;
		temp->p_x = x * I_SIZE;
		temp->p_y = y * I_SIZE;
		return ;
	}
	while (temp2 != NULL)
		temp2 = temp2->next;
	temp2->next = temp;
	temp->p_x = x * I_SIZE;
	temp->p_y = y * I_SIZE;
	temp->next = NULL;
}

void	get_cposition(gameplay *data, char **map, char elem)
{
	int i;
	int j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		// ft_printf("map:%s\n", map[i]);
		// ft_printf("1i = %i\n", i);
		while (map[i][j] != '\0')
		{
			if (map[i][j] == elem)
			{
				// ft_printf("i = %i, j = %i\n", i, j);
				new_pos(i, j, data);
			}
			j++;
			// ft_printf("j = %i\n", j);
		}
		i++;
		// ft_printf("2i = %i\n", i);
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
	ft_printf("here");
	i = 0;
	temp = data->c_pos;
	temp2 = temp;
	while (temp2->next)
	{
		ft_printf("%i, %i\n", temp2->p_x, temp2->p_y);
		temp2 = temp2->next;
	}
	while (temp->next != NULL)
	{
		i = 0;
		while (path[i] && path[i][0] != '\0')
		{
			if (new_image(add_image(data, path[i]), data->collectible, data) == 1)
				return ; // free everything
			i++;
		}
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
