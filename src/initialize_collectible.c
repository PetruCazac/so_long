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
	temp = ft_calloc(1, sizeof(c_position_l));
	if (temp == NULL)
	{
		exit(errno);
	}
	if (temp2 == NULL)
		temp2 = temp;
	while (temp2->next != NULL)
		temp2 = temp2->next;
	temp2->next = temp;
	temp->p_x = x * 50;
	temp->p_y = y * 50;
	ft_printf("here\n");
	temp->next = NULL;
}

void	get_cposition(gameplay *data, char **map, char elem)
{
	int i;
	int j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == elem)
			{
				new_pos(i, j, data);
			}
		}
	}
}

void initialize_collectible(gameplay *data)
{
	int			i;
	char		**path;

	get_cposition(data, data->map, 'C');
	path = get_collectible_path();
	data->collectible->texture = mlx_load_png(path[0]);
	data->collectible->image = mlx_texture_to_image(data->mlx, data->collectible->texture);
	mlx_resize_image(data->collectible->image, I_SIZE, I_SIZE);
	data->collectible->next = data->collectible;
	i = 1;
	while (path[i][0] != '\0')
	{
		if (new_image(add_image(data, path[i]), data->collectible) == 1)
			return ; // free everything
		i++;
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
