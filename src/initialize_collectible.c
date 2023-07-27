/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_collectible.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:31:06 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/27 10:44:24 by pcazac           ###   ########.fr       */
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

char	**get_collected_path(void)
{
	char **path;

	path = ft_calloc(4, sizeof(char *));
	path[0] = ft_strdup("Textures/Collectible/bat1.png");
	path[1] = ft_strdup("Textures/Collectible/bat2.png");
	path[2] = ft_strdup("Textures/Collectible/bat3.png");
	path[3] = "\0";
	return (path);
}

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
	char			**path2;

	get_cposition(data, data->map, 'C');
	path = get_collectible_path();
	path2 = get_collected_path();
	i = 0;
	while (path[i] != NULL && path[i][0] != '\0')
	{
		if (add_texture(new_texture(path[i]), &(data->collectible)) == 1)
			return ; // free everything
		i++;
	}
	i = 0; 
	while (path2[i] != NULL && path2[i][0] != '\0')
	{
		if (add_texture(new_texture(path2[i]), &(data->collected)) == 1)
			return ; // free everything
		i++;
	}
}

void	collectible_hook(void *param)
{
	t_game				*data;
	t_cimage			*temp;

	data = (t_game*) param;
	if (data->time > ITERATIONS )
	{
		temp = data->c_image;
		while (temp)
		{
			if (temp->touch == true)
			{
				if(temp->image != NULL)
					mlx_delete_image(data->mlx, temp->image);
				temp->image = mlx_texture_to_image(data->mlx, data->collectible->texture);
				mlx_resize_image(temp->image, P_SIZE, P_SIZE);
				mlx_image_to_window(data->mlx, temp->image, temp->p_x, temp->p_y);
				mlx_set_instance_depth(temp->image->instances, 253);
			}
			else if (temp->touch == false)
			{
				if(temp->image != NULL)
					mlx_delete_image(data->mlx, temp->image);
				temp->image = mlx_texture_to_image(data->mlx, data->collected->texture);
				mlx_resize_image(temp->image, P_SIZE, P_SIZE);
				mlx_image_to_window(data->mlx, temp->image, temp->p_x, temp->p_y);
				mlx_set_instance_depth(temp->image->instances, 253);
			}
			temp = temp->next;
			
		}
		data->time	= 0;
		data->collectible = data->collectible->next;
		data->collected = data->collected->next;
	}
}
