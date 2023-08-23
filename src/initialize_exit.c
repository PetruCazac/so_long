/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:31:06 by pcazac            #+#    #+#             */
/*   Updated: 2023/08/23 19:21:12 by pcazac           ###   ########.fr       */
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
	path[6] = "\0";
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
	path[4] = "\0";
	return (path);
}

/// @brief 
/// @param data 
void	initialize_exit(t_game *data)
{
	int		i;
	char	**path;
	char	**path2;

	get_exit_position(data->map, data);
	path = get_exit_path();
	path2 = get_valid_exit_path();
	i = 0;
	while (path[i][0] != '\0')
	{
		if (add_texture(new_texture(path[i]), &(data->exit)) == 1)
			return ;
		i++;
	}
	i = 0;
	while (path2[i][0] != '\0')
	{
		if (add_texture(new_texture(path2[i]), &(data->exit_valid)) == 1)
			return ;
		i++;
	}
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
		{
			if (data->exit_image != NULL)
				mlx_delete_image(data->mlx, data->exit_image);
			data->exit_image = mlx_texture_to_image(data->mlx, data->exit->texture);
			mlx_resize_image(data->exit_image, P_SIZE, P_SIZE);
			mlx_image_to_window(data->mlx, data->exit_image, data->e_x, data->e_y);
			mlx_set_instance_depth(data->exit_image->instances, 249);
			data->exit = data->exit->next;
		}
	}
	else if (data->exit_touch == false)
	{
		if (data->time > ITERATIONS)
		{
			if (data->exit_image != NULL)
				mlx_delete_image(data->mlx, data->exit_image);
			data->exit_image = mlx_texture_to_image(data->mlx, data->exit_valid->texture);
			mlx_resize_image(data->exit_image, P_SIZE, P_SIZE);
			mlx_image_to_window(data->mlx, data->exit_image, data->e_x, data->e_y);
			mlx_set_instance_depth(data->exit_image->instances, 249);
			data->exit_valid = data->exit_valid->next;
		}
	}
}
