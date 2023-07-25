/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_collectible.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:31:06 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/25 16:32:32 by pcazac           ###   ########.fr       */
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

// void	new_pos(int y, int x, t_game *data)
// {
// 	t_position	*temp;
// 	t_position	*temp2;

// 	temp = ft_calloc(1, sizeof(t_position));
// 	if (temp == NULL)
// 	{
// 		ft_printf("Malloc Error");
// 		exit(errno);
// 	}
// 	temp2 = data->c_pos;
// 	if (temp2 == NULL)
// 	{
// 		data->c_pos = temp;
// 		temp->p_x = x * I_SIZE;
// 		temp->p_y = y * I_SIZE;
// 		temp->next = NULL;
// 		return ;
// 	}
// 	if (temp2 != NULL)
// 	{
// 		while (temp2->next != NULL)
// 			temp2 = temp2->next;
// 		temp2->next = temp;
// 		temp->p_x = x * I_SIZE;
// 		temp->p_y = y * I_SIZE;
// 		temp->next = NULL;
// 	}
// }

void	get_cposition(t_game *data, char **map, char elem)
{
	int y;
	int x;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == elem)
			{
				add_back_image(new_cnode(y, x), data);
				data->c_count++;
			}
			x++;
		}
		y++;
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
		if (add_texture(new_texture(path[i]), &(data->collectible)) == 1)
			return ; // free everything
		i++;
	}
}

void	collectible_hook(void *param)
{
	t_game				*data;
	t_cimage			*temp;

	data = (t_game*) param;
	if (data->time > ITERATIONS)
	{
		temp = data->c_image;
		while (temp)
		{
			if(temp->image != NULL)
				mlx_delete_image(data->mlx, temp->image);
			temp = temp->next;
		}
		temp = data->c_image;
		while (temp)
		{
			temp->image = mlx_texture_to_image(data->mlx, data->collectible->texture);
			mlx_resize_image(temp->image, P_SIZE, P_SIZE);
			mlx_image_to_window(data->mlx, temp->image, temp->p_x, temp->p_y);
			mlx_set_instance_depth(temp->image->instances, 253);
			temp = temp->next;
		}
		data->time	= 0;
		data->collectible = data->collectible->next;
	}
}
