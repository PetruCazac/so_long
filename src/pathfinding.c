/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:13:51 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/10 18:07:43 by pcazac           ###   ########.fr       */
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

	i = 0;
	j = 0;
	address[0] = 0;
	address[1] = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] == 'C')
			{
				address[0] = i;
				address[1] = j;
				add_node(list, address);
			}
			j++;
		}
		i++;
	}
	return (list);
}

void	find_element(char **map, element *elements)
{
	int	i;
	int	j;
	element	elements;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
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
			j++;
		}
		i++;
	}
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
