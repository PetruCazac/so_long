/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:41:03 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/10 18:08:41 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

// map_list to_list(char **martix)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (matrix[i])
// 	{
// 		while(matrix[i][j])
// 		{
			
// 			matrix
// 			n
// 		}
// 	}
// }

collectible *new_node(int address[2])
{
	collectible	*c;

	c = malloc(sizeof(collectible));
	if (c)
	{
		c->tile[0] = address[0];
		c->tile[1] = address[1];
		c->next = NULL;
	}
	return (c);
}

void add_node(collectible **c, int address[2])
{
	collectible *temp;

	temp = *c;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node(address);
	
}
