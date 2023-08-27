/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:41:03 by pcazac            #+#    #+#             */
/*   Updated: 2023/08/27 18:10:07 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

/// @brief Initializes integer values
/// @param data General data structure
/// @param map Game map, char array
void	initialize_ints(t_game *data, char **map)
{
	data->height = ft_strlen_arr(map);
	data->width = ft_strlen(map[0]);
	data->p_x = 0;
	data->p_y = 0;
	data->e_x = 0;
	data->e_y = 0;
	data->score = 0;
	data->c_count = 0;
	data->moves = 0;
	data->time = 0;
	data->time_p = 0;
	data->coll_tp = NULL;
	data->colld_tp = NULL;
	data->player_tp = NULL;
	data->exit_tp = NULL;
	data->exited_tp = NULL;
}

/// @brief Iniitalizes the -> structure
/// @param map Game map
/// @param mlx Pointer for the graphical interface
/// @return The data structure
t_game	*initialize_data(char **map, mlx_t *mlx)
{
	t_game	*data;

	data = ft_calloc(1, sizeof(t_game));
	if (data == NULL)
		errormngr(map, NULL);
	initialize_ints(data, map);
	data->player = NULL;
	data->collectible = NULL;
	data->collected = NULL;
	data->exit = NULL;
	data->exit_valid = NULL;
	data->map = map;
	data->mlx = mlx;
	data->texture = (t_texture){.walls = NULL, .ground = NULL};
	data->image = (t_image){.walls = NULL, .ground = NULL};
	data->c_image = NULL;
	data->player_img = NULL;
	data->exit_image = NULL;
	data->exit_touch = true;
	data->exited = true;
	return (data);
}

/// @brief Allocates and initializes a new node for the collectibles structure
/// @param y Position y of the collectble
/// @param x Position x of the collectible
/// @return The pointer to the newly created node
t_cimage	*new_cnode(int y, int x)
{
	t_cimage	*tmp;

	tmp = ft_calloc(1, sizeof(t_cimage));
	if (tmp)
	{
		tmp->image = NULL;
		tmp->next = NULL;
		tmp->p_x = x * I_SIZE;
		tmp->p_y = y * I_SIZE;
		tmp->touch = true;
	}
	return (tmp);
}
