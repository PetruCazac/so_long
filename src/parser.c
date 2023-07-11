/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:00:05 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/11 18:02:31 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

char **get_matrix(int fd, int count)
{
	int		i;
	char	*line;
	char	**matrix;

	i = 0;
	line = NULL;
	matrix = NULL;
	line = get_next_line(fd);
	count++;
	if (!line)
	{
		matrix = ft_calloc(((size_t) count) + 1, sizeof(char *));
		matrix[count] = line;
	}
	else if (line[0] != '\0')
	{
		matrix = get_matrix(fd, count);
		matrix[count - 1] = line;
	}
	return (matrix);
}

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
			exit(errno);
		}
		c++;
	}
}

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
		exit(errno);
	}
}

char **parser(char *file)
{
	char	**matrix;
	int		fd;
	// map_list map;

	fd = open(file, O_RDONLY);
	if (fd < 0) 
	{
		errno = 1;
		perror("OPEN ERROR");
		exit(errno);
	}
	matrix = get_matrix(fd, 0);
	purge(matrix);
	square(matrix);
	all_walls_closed(matrix);
	mandatory_elements(matrix);
	// map = to_list(matrix);
	
	return (matrix);
}
	