/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:41:03 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/11 18:31:23 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

mapfill *new_node(int address[2])
{
	mapfill	*c;

	c = malloc(sizeof(mapfill *));
	if (c)
	{
		c->a[0] = address[0];
		c->a[1] = address[1];
		c->next = NULL;
	}
	return (c);
}

int	add_node(mapfill **c, int i, int j)
{
	mapfill *temp;
	int		address[2];

	address[0] = i;
	address[1] = j;
	if (*c != NULL)
	{
		temp = *c;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node(address);
		if (!temp->next)
		{
			free_mapfill(temp);
			c = NULL;
			return (EXIT_FAILURE);
		}
	}
	if (*c == NULL)
		*c = new_node(address);
	return (EXIT_SUCCESS);
}

void	free_mapfill(mapfill *t)
{
	mapfill	*temp;

	temp = t;
	while (temp)
	{
		temp = t->next;
		free(t);
	}
}
