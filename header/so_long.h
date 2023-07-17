/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:00:28 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/17 17:43:49 by pcazac           ###   ########.fr       */
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
#include "../MLX42/include/MLX42/MLX42.h"

typedef struct	m_list
{
	struct m_list	*next;
	struct m_list	*previous;
	struct m_list	*last;
	char			tile[2];
}				map_list;

typedef struct	element_list
{
	int				coordinate[2];
}				player;

int		check_all(int argc);
char	**parser(char *file);
void	purge(char **map);
void	find_path(char **map);
char 	**copymap(char **map);
void	free_array(char **arr);

#endif
