/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:10:40 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/10 15:14:33 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	main(int argc, char *argv[])
{
	char **map;
	
	check_all(argc);
	map = parser(argv[1]);
	find_path(map);
	return (0);
}
