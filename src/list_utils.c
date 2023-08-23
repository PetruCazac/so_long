/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:41:03 by pcazac            #+#    #+#             */
/*   Updated: 2023/08/23 17:59:21 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

/// @brief Creates and loads a texture node
/// @param path Path to the texture image
/// @return The pointer to the new node
t_animation	*new_texture(char *path)
{
	t_animation	*temp;

	temp = ft_calloc(1, sizeof(t_animation));
	if (temp == NULL)
		return (NULL);
	temp->texture = mlx_load_png(path);
	return (temp);
}

/// @brief Adds a new node to the animation linked list
/// @param node Newly created node to be added
/// @param obj Linked list to receive the new node
/// @return EXIT_FAILURE if the new node was not allocated
int	add_texture(t_animation *node, t_animation **obj)
{
	t_animation	*temp;

	if (node == NULL)
		return (EXIT_FAILURE);
	if (*obj != NULL)
	{
		temp = *obj;
		while (temp->end)
			temp = temp->next;
		temp->next = node;
		node->previous = temp;
		node->next = *obj;
		(*obj)->previous = node;
		node->end = NULL;
		temp->end = node;
	}
	else
	{
		*obj = node;
		node->previous = *obj;
		node->next = *obj;
		node->end = NULL;
	}
	return (0);
}

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
	data->time = 0;
	data->time_p = 0;
}

/// @brief Iniitalizes the data structure
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
		tmp->image =  NULL;
		tmp->next = NULL;
		tmp->p_x = x * I_SIZE;
		tmp->p_y = y * I_SIZE;
		tmp->touch = true;
	}
	return (tmp);
}

/// @brief Adds a new node to the back of the image linked list
/// @param node The new node to be added
/// @param data The data structure that contains the linked list
void	add_back_image(t_cimage *node, t_game *data)
{
	t_cimage	*temp;

	if (data->c_image == NULL)
	{
		data->c_image = node;
		return ;
	}
	temp = data->c_image;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = node;
}
