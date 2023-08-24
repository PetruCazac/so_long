/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_collectible.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:31:06 by pcazac            #+#    #+#             */
/*   Updated: 2023/08/24 20:25:33 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

char	**get_collectible_path(void)
{
	char	**path;

	path = ft_calloc(9, sizeof(char *));
	if (!path)
		return (NULL);
	path[0] = ft_strdup("Textures/Collectible/Player1.png");
	path[1] = ft_strdup("Textures/Collectible/Player2.png");
	path[2] = ft_strdup("Textures/Collectible/Player3.png");
	path[3] = ft_strdup("Textures/Collectible/Player4.png");
	path[4] = ft_strdup("Textures/Collectible/Player5.png");
	path[5] = ft_strdup("Textures/Collectible/Player6.png");
	path[6] = ft_strdup("Textures/Collectible/Player7.png");
	path[7] = ft_strdup("Textures/Collectible/Player8.png");
	path[8] = NULL;
	return (path);
}

char	**get_collected_path(void)
{
	char	**path;

	path = ft_calloc(4, sizeof(char *));
	if (!path)
		return (NULL);
	path[0] = ft_strdup("Textures/Collectible/bat1.png");
	path[1] = ft_strdup("Textures/Collectible/bat2.png");
	path[2] = ft_strdup("Textures/Collectible/bat3.png");
	path[3] = NULL;
	return (path);
}

void	get_cposition(t_game *data, char **map, char elem)
{
	int	y;
	int	x;

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

void	initialize_collectible(t_game *data)
{
	int		i;
	char	**path;
	char	**path2;

	get_cposition(data, data->map, 'C');
	path = get_collectible_path();
	if (!path)
		free_data(data);
	path2 = get_collected_path();
	if (!path2)
		free_data(data);
	i = -1;
	while (path[++i] != NULL && path[i][0] != '\0')
	{
		if (add_texture(new_texture(path[i]), &(data->collectible)) == 1)
			return (free_array(path), free_array(path2), free_data(data));
	}
	free_array(path);
	i = -1;
	while (path2[++i] != NULL && path2[i][0] != '\0')
	{
		if (add_texture(new_texture(path2[i]), &(data->collected)) == 1)
			return (free_array(path2), free_data(data));
	}
	free_array(path2);
}

void	collectible_hook(void *param)
{
	t_game		*data;
	t_cimage	*temp;

	data = (t_game *)param;
	if (data->time > ITERATIONS)
	{
		temp = data->c_image;
		while (temp)
		{
			if (temp->touch == true)
				to_collect(temp, data);
			else if (temp->touch == false)
				collected(temp, data);
			temp = temp->next;
		}
		data->time = 0;
		data->collectible = data->collectible->next;
		data->collected = data->collected->next;
	}
}
