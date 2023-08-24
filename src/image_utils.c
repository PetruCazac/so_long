/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:24:52 by pcazac            #+#    #+#             */
/*   Updated: 2023/08/23 19:27:04 by pcazac           ###   ########.fr       */
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
