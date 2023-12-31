/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:31:06 by pcazac            #+#    #+#             */
/*   Updated: 2023/08/24 10:08:23 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

/// @brief Returns the player position
/// @param map Game map
/// @param data Data set that holds the game info
void	get_player_position(char **map, t_game *data)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
			{
				data->p_x = j * I_SIZE;
				data->p_y = i * I_SIZE;
			}
		}
	}
}

/// @brief Function loads the texture from the preset path
/// @return The array of the paths
char	**get_player_path(void)
{
	char	**path;

	path = ft_calloc(21, sizeof(char *));
	if (!path)
		return (NULL);
	path[0] = ft_strdup("Textures/Vampire/Vampire1.png");
	path[1] = ft_strdup("Textures/Vampire/Vampire1.png");
	path[2] = ft_strdup("Textures/Vampire/Vampire1.png");
	path[3] = ft_strdup("Textures/Vampire/Vampire1.png");
	path[4] = ft_strdup("Textures/Vampire/Vampire1.png");
	path[5] = ft_strdup("Textures/Vampire/Vampire2.png");
	path[6] = ft_strdup("Textures/Vampire/Vampire2.png");
	path[7] = ft_strdup("Textures/Vampire/Vampire2.png");
	path[8] = ft_strdup("Textures/Vampire/Vampire2.png");
	path[9] = ft_strdup("Textures/Vampire/Vampire2.png");
	path[10] = ft_strdup("Textures/Vampire/Vampire3.png");
	path[11] = ft_strdup("Textures/Vampire/Vampire3.png");
	path[12] = ft_strdup("Textures/Vampire/Vampire3.png");
	path[13] = ft_strdup("Textures/Vampire/Vampire3.png");
	path[14] = ft_strdup("Textures/Vampire/Vampire4.png");
	path[15] = ft_strdup("Textures/Vampire/Vampire4.png");
	path[16] = ft_strdup("Textures/Vampire/Vampire4.png");
	path[17] = ft_strdup("Textures/Vampire/Vampire4.png");
	path[18] = NULL;
	return (path);
}

/// @brief Initializes the player texture and position
/// @param data The pointer to the game data structure
void	initialize_player(t_game *data)
{
	int		i;
	char	**path;

	get_player_position(data->map, data);
	path = get_player_path();
	if (!path)
		free(data);
	i = 0;
	while (path[i])
	{
		if (add_texture(new_texture(path[i]), &(data->player)) == 1)
			return (free_array(path), free_data(data));
		i++;
	}
	free_array(path);
}

/// @brief Deletes the previous player image and puts the new image
/// @param param The pointer to the game data structure
void	player_static_hook(void *param)
{
	t_game				*data;
	static mlx_image_t	*image_p;

	data = (t_game *)param;
	data->time_p++;
	if (image_p != NULL)
		mlx_delete_image(data->mlx, image_p);
	data->player_img = image_p;
	image_p = mlx_texture_to_image(data->mlx, data->player->texture);
	mlx_resize_image(image_p, P_SIZE, P_SIZE);
	mlx_image_to_window(data->mlx, image_p, data->p_x, data->p_y);
	mlx_set_instance_depth(image_p->instances, 250);
	data->player = data->player->next;
}

/// @brief Deletes the previous player image and puts the new image
/// @param param The pointer to the game data structure
void	player_moving_hook(void *param)
{
	t_game				*data;
	static mlx_image_t	*image_p;

	data = (t_game *) param;
	if (image_p != NULL)
		mlx_delete_image(data->mlx, image_p);
	if (data->player_img != NULL)
		mlx_delete_image(data->mlx, data->player_img);
	image_p = mlx_texture_to_image(data->mlx, data->player->texture);
	mlx_resize_image(image_p, P_SIZE, P_SIZE);
	mlx_image_to_window(data->mlx, image_p, data->p_x, data->p_y);
	mlx_set_instance_depth(image_p->instances, 250);
}
