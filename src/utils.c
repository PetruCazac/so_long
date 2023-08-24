/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:58:42 by pcazac            #+#    #+#             */
/*   Updated: 2023/08/24 10:06:27 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"
/// @brief Deletes the newline at the end of each line
/// @param map Game map, char array
void	purge(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '\n')
				map[i][j] = '\0';
			j++;
		}
		i++;
	}
}

/// @brief Copies the game map and returns the copy
/// @param map The game map which is a char array
/// @return Char array of the copied map
char	**copymap(char **map)
{
	int		i;
	char	**copy_map;

	i = 0;
	while (map[i])
		i++;
	copy_map = ft_calloc(i + 1, sizeof(char *));
	if (copy_map == NULL)
		return (NULL);
	i = -1;
	while (map[++i])
	{
		copy_map[i] = ft_strdup(map[i]);
		if (copy_map[i] == NULL)
		{
			free_array(copy_map);
			return (NULL);
		}
	}
	return (copy_map);
}

/// @brief Frees any char array
/// @param arr char array to be freed
void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

/// @brief Manges the map errors
/// @param map Game map, char array
/// @param str Error message to be displayed
void	errormngr(char **map, char *str)
{
	errno = 1;
	perror(str);
	free_array(map);
	exit(errno);
}

/// @brief Reads the map file and copies map into an array
/// @param fd  File descriptor of the map
/// @param count Int var that is 0
/// @return Returns the array of the map
char	**get_matrix(int fd, int count)
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
