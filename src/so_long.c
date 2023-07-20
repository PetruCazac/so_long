/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:10:40 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/20 17:21:54 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"



int	main(int argc, char *argv[])
{
	char 	**map;
	mlx_t	*mlx;

	check_all(argc);
	map = parser(argv[1]);
	find_path(map);
	mlx = mlx_init(ft_strlen(map[0]), ft_strlen_arr(map), "GAME", 1);
	if (mlx == NULL)
		exit(EXIT_FAILURE);
	else
	{
		init_image(mlx, map);
		mlx_close_window(mlx);
	}
	free_array(map);
	// Free everything else
	return (0);
}
