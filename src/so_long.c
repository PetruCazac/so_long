/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:10:40 by pcazac            #+#    #+#             */
/*   Updated: 2023/08/28 12:02:41 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"
// void	at_exit(void)
// {
// 	system("leaks so_long");
// }
// atexit(at_exit);

int	main(int argc, char *argv[])
{
	char	**map;
	mlx_t	*mlx;
	t_game	*data;

	check_all(argc);
	map = parser(argv[1]);
	find_path(map);
	mlx = mlx_init(ft_strlen(map[0]) * I_SIZE, \
					ft_strlen_arr(map) * I_SIZE, "GAME", 0);
	if (mlx == NULL)
		exit(EXIT_FAILURE);
	data = initialize_data(map, mlx);
	init_image(data);
	free_data(data);
	return (0);
}
