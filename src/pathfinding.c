/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:13:51 by pcazac            #+#    #+#             */
/*   Updated: 2023/08/23 18:18:02 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

char	**fill_map(char **map, int y, int x);

/// @brief Finds the player position on the map
/// @param map Is the char array for the game map
/// @param player The player position
void	find_element(char **map, int (*player)[2])
{
	int		i;
	int		j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
			{
				(*player)[0] = i;
				(*player)[1] = j;
			}
		}
	}
}

/// @brief Fills a single cell of the map
/// @param map Copy of the game map, char array
/// @param y Y position of reference
/// @param x X position of reference
/// @param direction Structure for the direction of the next position
void	fill_cell(char **map, int y, int x, t_pair direction)
{
	map[y][x] = '1';
	fill_map(map, y + direction.y, x + direction.x);
}

/// @brief Is a flood fill recursive function
/// @param map The map char array to be analyzed
/// @param y Starting y position
/// @param x Starting x position
/// @return The filled map
char	**fill_map(char **map, int y, int x)
{
	if (map[y][x] != '1')
	{
		if (map[y + 1][x] != '1')
			fill_cell(map, y, x, (t_pair){1, 0});
		if (map[y - 1][x] != '1')
			fill_cell(map, y, x, (t_pair){-1, 0});
		if (map[y][x + 1] != '1')
			fill_cell(map, y, x, (t_pair){0, 1});
		if (map[y][x - 1] != '1')
			fill_cell(map, y, x, (t_pair){0, -1});
	}
	map[y][x] = '1';
	return (map);
}

/// @brief Checks for the presence of the characters after flood fill
/// @param map Is the game map as an char array
/// @return Frees the modified map and returns failure or success
int	check_map(char **map)
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

/// @brief The functions copies the map and analyses the possible paths
/// @param map Game map, char array
void	find_path(char **map)
{
	char		**map_copy;
	int			player[2];

	player[0] = 0;
	player[1] = 0;
	find_element(map, &player);
	map_copy = copymap(map);
	if (map_copy == NULL)
	{
		free_array(map);
		errno = 1;
		exit(errno);
		return ;
	}
	if (check_map(fill_map(map_copy, player[0], player[1])) == EXIT_FAILURE)
	{
		free_array(map);
		errno = 1;
		perror("NOT ALL ELEMENTS CAN BE REACHED");
		exit(errno);
		return ;
	}
}
