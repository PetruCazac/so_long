/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:13:51 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/17 08:03:44 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	find_element(char **map, element **e)
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
				(*e)->player[0] = i;
				(*e)->player[1] = j;
			}
			if(map[i][j] == 'E')
			{
				(*e)->exit[0] = i;
				(*e)->exit[1] = j;
			}
		}
	}
}

void	filler(char **c, mapfill **t, int i, int j)
{
	c[i][j] = '2';
	if (add_node(t, i, j) == EXIT_FAILURE)
		free_mapfill(*t);
}

char	**fill_map(char **map, element *elements)
{
	mapfill	*t;
	char	**c;

	t = malloc(sizeof(mapfill *));
	t->a[0] = elements->player[0];
	t->a[1] = elements->player[1];
	c = copymap(map);
	while (t)
	{
		if (c[t->a[0] - 1][t->a[1]] != '1' && c[t->a[0] - 1][t->a[1]] != '2')
			filler(c, &t, t->a[0] - 1, t->a[1]);
		if (c[t->a[0] + 1][t->a[1]] != '1' && c[t->a[0] + 1][t->a[1]] != '2')
			filler(c, &t, t->a[0] + 1, t->a[1]);
		if (c[t->a[0]][t->a[1] - 1] != '1' && c[t->a[0]][t->a[1] - 1] != '2')
			filler(c, &t, t->a[0], t->a[1] - 1);
		if (c[t->a[0]][t->a[1] + 1] != '1' && c[t->a[0]][t->a[1] + 1] != '2')
			filler(c, &t, t->a[0], t->a[1] + 1);
		t = t->next;
	}
	free_mapfill(t);
	return(c);
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
				return (free(map), EXIT_FAILURE);
		}
	}
	return (free_array(map), EXIT_SUCCESS);
}

void	find_path(char **map)
{
	element		*elements;

	elements = malloc(sizeof(element));
	if (elements == NULL)
		{
			free_array(map);
			errno = 2;
			exit(errno);
		}
	find_element(map, &elements);
	if (check_map(fill_map(map, elements)) == EXIT_FAILURE)
	{
		free(elements);
		free_array(map);
		errno = 1;
		perror("NOT ALL ELEMENTS CAN BE REACHED");
		exit(errno);
	}
}
