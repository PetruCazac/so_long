/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:13:51 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/10 18:23:58 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"
// Check if there is at least one possible path to get to the exit
collectible **find_collectibles(char **map)
{
	int			i;
	int			j;
	collectible	**list;
	int			address[2];

	i = -1;
	list = NULL;
	address[0] = 0;
	address[1] = 0;
	while (map[++i])
	{
		j = -1;
		while(map[i][++j])
		{
			if(map[i][j] == 'C')
			{
				address[0] = i;
				address[1] = j;
				add_node(list, address);
			}
		}
	}
	return (list);
}

void	find_element(char **map, element *elements)
{
	int	i;
	int	j;
	element	elements;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while(map[i][++j])
		{
			if(map[i][j] == 'P')
			{
				elements->player[0] = i;
				elements->player[1] = j;
			}
			if(map[i][j] == 'E')
			{
				elements->exit[0] = i;
				elements->exit[1] = j;
			}
		}
	}
}
void	fill_map(map)
{
	
}


void	find_path(char **map)
{
	int			i;
	element		*elements;
	collectible	**collectibles;

	find_element(map, elements);
	collectibles = find_collectibles(map);
	fill_map(map, elements, collectibles);
	i = 0;
	
}
