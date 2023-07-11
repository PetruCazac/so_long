/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:00:28 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/11 18:40:01 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "../libft/header/libft.h"
#include <errno.h>

typedef struct	m_list
{
	struct m_list	*next;
	struct m_list	*previous;
	struct m_list	*last;
	char			tile[2];
}				map_list;

typedef struct	element_list
{
	int				player[2];
	int				exit[2];
}				element;

typedef	struct	l_mapfilling
{
	struct l_mapfilling	*next;
	int					a[2];
}				mapfill;

int		check_all(int argc);
char	**parser(char *file);
void	purge(char **map);
int		add_node(mapfill **c, int i, int j);
void	find_path(char **map);
char 	**copymap(char **map);
void	free_mapfill(mapfill *t);
void	free_array(char **arr);

#endif
