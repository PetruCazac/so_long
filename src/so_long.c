/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:10:40 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/18 18:05:02 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

// void	init_image(mlx_t *mlx)
// {
// 	image_p		*image;
// 	texture_p	*texture;
	
// 	texture = malloc(1*sizeof(texture_p));
// 	image = malloc(1*sizeof(image_p));
// 	texture->t_walls = mlx_load_png("Textures/Tile/Walls.png");
// 	texture->t_ground = mlx_load_png("Textures/Grass/Grass.png");
	
// 	image->i_walls = mlx_texture_to_image(mlx, texture->t_walls);
// 	image->i_ground = mlx_texture_to_image(mlx, texture->t_ground);
// 	mlx_image_to_window(mlx, image->i_walls, 100, 0);
// 	mlx_image_to_window(mlx, image->i_ground, 100, 0);
// 	return ;
// }

int	main(int argc, char *argv[])
{
	char 	**map;
	mlx_t	*mlx;
	image_p		*image;
	texture_p	*texture;
	
	check_all(argc);
	map = parser(argv[1]);
	find_path(map);
	mlx = mlx_init(WIDTH, HEIGHT, "GAME", 1);
	texture->t_walls = mlx_load_png("Textures/Tile/Walls.png");
	texture->t_ground = mlx_load_png("Textures/Grass/Grass.png");
	if (mlx == NULL)
		exit(EXIT_FAILURE);
	else
	{
		image->i_walls = mlx_texture_to_image(mlx, texture->t_walls);
		image->i_ground = mlx_texture_to_image(mlx, texture->t_ground);
		mlx_image_to_window(mlx, image->i_walls, 100, 0);
		mlx_image_to_window(mlx, image->i_ground, 100, 0);
		init_image(mlx);
		mlx_loop(mlx);
		mlx_close_window(mlx);
	}
	free_array(map);
	return (0);
}
