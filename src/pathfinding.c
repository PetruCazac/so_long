/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:13:51 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/17 10:41:33 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	find_element(char **map, int (*player)[2])
{
	int		i;
	int		j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while(map[i][++j])
		{
			if(map[i][j] == 'P')
			{
				(*player)[0] = i;
				(*player)[1] = j;
			}
		}
	}
}

char	**fill_map(char **map, int *source)
{
	int	i;
	int	j;
	int	next[2];
	
	i = source[0];
	j = source[1];
	if (map[source[0]][source[1]] != '1')
	{
		if ( map[source[0] + 1][source[1]] != '1')
		{
			next[0] = source[0] + 1;
			next[1] = source[1];
			map[source[0]][source[1]] = '1';
			fill_map(map, next);
		}
		if (map[source[0] - 1][source[1]] !='1')
		{
			next[0] = source[0] - 1;
			next[1] = source[1];
			map[source[0]][source[1]] = '1';
			fill_map(map, next);
		}
		if (map[source[0]][source[1] + 1] !='1')
		{
			next[0] = source[0];
			next[1] = source[1] + 1;
			map[source[0]][source[1]] = '1';
			fill_map(map, next);
		}
		if (map[source[0]][source[1] - 1] !='1')
		{
			next[0] = source[0];
			next[1] = source[1] - 1;
			map[source[0]][source[1]] = '1';
			fill_map(map, next);
		}
	}
	map[source[0]][source[1]] = '1';
	return (map);
}

int	check_map(char** map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (free_array(map), EXIT_FAILURE);
		}
	}
	return (free_array(map), EXIT_SUCCESS);
}

void	find_path(char **map)
{
	char		**map_copy;
	int			player[2];

	find_element(map, &player);
	map_copy = copymap(map);
	if (map_copy == NULL)
	{
		free_array(map);
		errno = 1;
		exit(errno);
		return ;
	}
	if (check_map(fill_map(map_copy, player)) == EXIT_FAILURE)
	{
		free_array(map);
		errno = 1;
		perror("NOT ALL ELEMENTS CAN BE REACHED");
		exit(errno);
		return ;
	}
}
