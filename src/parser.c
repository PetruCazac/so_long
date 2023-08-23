/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:00:05 by pcazac            #+#    #+#             */
/*   Updated: 2023/08/21 21:23:46 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"
// Copies map into an array that will be processed later
char **get_matrix(int fd, int count)
{
	char	*line;
	char	**matrix;

	line = NULL;
	matrix = NULL;
	line = get_next_line(fd);
	count++;
	if (!line)
	{
		matrix = ft_calloc(((size_t) count) + 1, sizeof(char *));
		if (matrix == NULL)
			return (free(line), NULL);
		matrix[count] = line;
	}
	else if (line[0] != '\0')
	{
		matrix = get_matrix(fd, count);
		if (matrix == NULL)
			return (free(line), NULL);
		matrix[count - 1] = line;
	}
	return (matrix);
}
// Checks that the map is square
int	square(char **map)
{
	int	i;
	int j;
	int c;

	i = 0;
	j = 0;
	c = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (i == 0)
			c = j;
		else if (i != 0)
		{
			if (c != j)
			{
				errno = 1;
				perror("MAP NOT RECTANGULAR!");
				exit(1);
			}
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
// Checks if the walls are closed and there is a possible path
void	all_walls_closed(char **map)
{
	int j;
	int c;

	j = 0;
	c = 0;
	while (map[c])
		c++;
	while (map[0][j] && map[c - 1][j])
	{
		if (map[0][j] != '1' || map[c - 1][j] != '1')
		{
			errno = 1;
			perror("WALLS NOT CLOSED!");
			free_array(map);
			exit(errno);
		}
		j++;
	}
	c = 0;
	while (map[c])
	{
		if (map[c][0] != '1' || map[c][j - 1] != '1')
		{
			errno = 1;
			perror("WALLS NOT CLOSED!");
			free_array(map);
			exit(errno);
		}
		c++;
	}
}
// Checks for the presence of the mandatory elements
void	mandatory_elements(char **map)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				c++;
			j++;
		}
		i++;
	}
	if (c != 1)
	{
		errno = 1;
		perror("MAP PLAYER ERROR");
		free_array(map);
		exit(errno);
	}
	c = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	if (c < 1)
	{
		errno = 1;
		perror("NOT ENOUGH COLLECTIBLES");
		free_array(map);
		exit(errno);
	}
	c = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				c++;
			j++;
		}
		i++;
	}
	if (c != 1)
	{
		errno = 1;
		perror("MAP EXIT ERROR");
		free_array(map);
		exit(errno);
	}
}
// Checks the correctness of the map
char **parser(char *file)
{
	char	**matrix;
	int		fd;
	int		i;

	i = ft_strlen(file);
	if (i < 4)
	{
		errno = 1;
		perror("INVALID FILE");
		exit(errno);
	}
	if (ft_strcmp(&(file[i - 4]), ".ber") != 0)
	{
		errno = 1;
		perror("WRONG FILE");
		exit(errno);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0) 
	{
		errno = 1;
		perror("OPEN ERROR here");
		exit(errno);
	}
	matrix = get_matrix(fd, 0);
	if (!matrix)
	{
		errno = 1;
		perror("Allocation error");
		exit(errno);
	}
	purge(matrix);
	square(matrix);
	all_walls_closed(matrix);
	mandatory_elements(matrix);
	return (matrix);
}
