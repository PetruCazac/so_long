/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:58:42 by pcazac            #+#    #+#             */
/*   Updated: 2023/08/21 07:24:45 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"
// Deletes all the newline elements from the array
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

char **copymap(char **map)
{
	int	i;
	char **copy_map;

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

void	free_array(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}
