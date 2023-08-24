/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:00:05 by pcazac            #+#    #+#             */
/*   Updated: 2023/08/24 21:40:09 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

/// @brief  Checks that the map is rectangular
/// @param map The array of the game map
/// @return EXIT_SUCCESS if the map is rectangular
int	square(char **map)
{
	int	i;
	int	j;
	int	c;

	i = -1;
	j = 0;
	c = 0;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (i == 0)
			c = j;
		else if (i != 0)
		{
			if (c != j)
				errormngr(map, "MAP NOT RECTANGULAR!");
		}
	}
	return (EXIT_SUCCESS);
}

/// @brief Checks if the walls are closed and there is a possible path
/// @param map The array of the game map
void	all_walls_closed(char **map)
{
	int	j;
	int	c;

	j = 0;
	c = 0;
	while (map[c])
		c++;
	while (map[0][j] && map[c - 1][j])
	{
		if (map[0][j] != '1' || map[c - 1][j] != '1')
			errormngr(map, "WALLS NOT CLOSED!");
		j++;
	}
	c = 0;
	while (map[c])
	{
		if (map[c][0] != '1' || map[c][j - 1] != '1')
			errormngr(map, "WALLS NOT CLOSED!");
		c++;
	}
}

/// @brief Checks the count of the elements and exits on error
/// @param map Game map, char array
/// @param count Element count structure
void	element_error(char **map, t_special count)
{
	if (count.p != 1)
		errormngr(map, "MAP PLAYER ERROR");
	else if (count.c < 1)
		errormngr(map, "NOT ENOUGH COLLECTIBLES");
	else if (count.e != 1)
		errormngr(map, "MAP EXIT ERROR");
}

/// @brief Checks for the presence of the mandatory elements on the map
/// @param map The array of the game map
/// @return Void unless the map is not correct
void	mandatory_elements(char **map)
{
	int			i;
	int			j;
	t_special	count;

	i = -1;
	count = (t_special){.c = 0, .p = 0, .e = 0};
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				count.p++;
			else if (map[i][j] == 'C')
				count.c++;
			else if (map[i][j] == 'E')
				count.e++;
			else if (map[i][j] != '0' && map[i][j] != '1')
				errormngr(map, "WEIRD SYMBOL FOUND");
		}
	}
	element_error(map, count);
}

/// @brief Checks the correctness of the map
/// @param file Is the input name of the file
/// @return The array of strings that make the map
char	**parser(char *file)
{
	char	**matrix;
	int		fd;
	int		i;

	i = ft_strlen(file);
	if (i < 4)
		errormngr(NULL, "INVALID FILE");
	if (ft_strcmp(&(file[i - 4]), ".ber") != 0)
		errormngr(NULL, "WRONG FILE");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		errormngr(NULL, "OPEN ERROR");
	matrix = get_matrix(fd, 0);
	if (!matrix)
		errormngr(NULL, "Allocation error");
	if (!matrix[0])
		errormngr(matrix, "MAP EMPTY!");
	purge(matrix);
	square(matrix);
	all_walls_closed(matrix);
	mandatory_elements(matrix);
	return (matrix);
}
