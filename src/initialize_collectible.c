/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_collectible.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:31:06 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/21 17:26:23 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	add_ctexture(t_animation *node, t_game *data)
{
	t_animation	*temp;

	if (node == NULL)
		exit(errno);
		// All the memory has to be freed!!!
	if (data->collectible != NULL)
	{
		temp = data->collectible;
		while (temp->end)
			temp = temp->next;
		temp->next = node;
		node->previous = temp;
		node->next = data->collectible;
		data->collectible->previous = node;
	}
	else
	{
		data->collectible = node;
		node->previous = data->collectible;
		node->next = data->collectible;
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

void	new_pos(int y, int x, t_game *data)
{
	t_position	*temp;
	t_position	*temp2;

	temp = ft_calloc(1, sizeof(t_position));
	if (temp == NULL)
	{
		ft_printf("Malloc Error");
		exit(errno);
	}
	temp2 = data->c_pos;
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
		temp2->next = temp;
		temp->p_x = x * I_SIZE;
		temp->p_y = y * I_SIZE;
		temp->next = NULL;
	}
}

void	get_cposition(t_game *data, char **map, char elem)
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

void initialize_collectible(t_game *data)
{
	int				i;
	char			**path;

	get_cposition(data, data->map, 'C');
	path = get_collectible_path();
	i = 0;
	while (path[i] != NULL && path[i][0] != '\0')
	{
		if (add_ctexture(new_texture(path[i]), data) == 1)
			return ; // free everything
		i++;
	add_back_image(new_inode(). data);
	}
}

void	collectible_hook(void *param)
{
	t_game				*data;
	t_position			*temp;

	data = (t_game*) param;
	temp = data->c_pos;
	if (data->time > 4)
	{
		while (temp->next)
		{
			if(image_p != NULL)
				mlx_delete_image(data->mlx, image_p);
			image_p = mlx_texture_to_image(data->mlx, data->collectible->texture);
			mlx_resize_image(image_p, I_SIZE, I_SIZE);
			mlx_image_to_window(data->mlx, image_p, data->e_x, data->e_y);
			mlx_set_instance_depth(image_p->instances, 252);
			data->collectible = data->collectible->next;
			temp = temp->next;
		}
	}
}
