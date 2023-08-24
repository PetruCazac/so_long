/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:31:06 by pcazac            #+#    #+#             */
/*   Updated: 2023/08/24 19:17:10 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

/// @brief 
/// @param map 
/// @param data 
void	get_exit_position(char **map, t_game *data)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'E')
			{
				data->e_x = j * I_SIZE;
				data->e_y = i * I_SIZE;
			}
		}
	}
}

/// @brief 
/// @param  
/// @return 
char	**get_exit_path(void)
{
	char	**path;

	path = ft_calloc(7, sizeof(char *));
	path[0] = ft_strdup("Textures/Fire/fire1.png");
	path[1] = ft_strdup("Textures/Fire/fire2.png");
	path[2] = ft_strdup("Textures/Fire/fire3.png");
	path[3] = ft_strdup("Textures/Fire/fire4.png");
	path[4] = ft_strdup("Textures/Fire/fire5.png");
	path[5] = ft_strdup("Textures/Fire/fire6.png");
	path[6] = NULL;
	return (path);
}

/// @brief 
/// @param  
/// @return 
char	**get_valid_exit_path(void)
{
	char	**path;

	path = ft_calloc(5, sizeof(char *));
	path[0] = ft_strdup("Textures/Fire/fire11.png");
	path[1] = ft_strdup("Textures/Fire/fire12.png");
	path[2] = ft_strdup("Textures/Fire/fire13.png");
	path[3] = ft_strdup("Textures/Fire/fire14.png");
	path[4] = NULL;
	return (path);
}

/// @brief 
/// @param data 
void	initialize_exit(t_game *data)
{
	int		i;
	char	**p;
	char	**p2;

	get_exit_position(data->map, data);
	p = get_exit_path();
	if (!p)
		free_data(data);
	p2 = get_valid_exit_path();
	if (!p2)
		free_data(data);
	i = -1;
	while (p[++i])
	{
		if (add_texture(new_texture(p[i]), &(data->exit)) == 1)
			return (free_array(p), free_array(p2), free_data(data));
	}
	free_array(p);
	i = -1;
	while (p2[++i])
	{
		if (add_texture(new_texture(p2[i]), &(data->exit_valid)) == 1)
			return (free_array(p2), free_data(data));
	}
	free_array(p2);
}

/// @brief 
/// @param param 
void	exit_hook(void *param)
{
	t_game	*data;

	data = (t_game *)param;
	data->time++;
	if (data->exit_touch == true)
	{
		if (data->time > ITERATIONS)
			simple_exit(data);
	}
	else if (data->exit_touch == false)
	{
		if (data->time > ITERATIONS)
			after_exit(data);
	}
}
