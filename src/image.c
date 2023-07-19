/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:02:13 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/19 18:00:08 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

// // void keypress(mlx_key_data_t keydata, void* param)
// // {
// // 	if (keydata.key == 87 && keydata.action == 2)
// // 	{
		
// // 	}
// // }


// void	hook(mlx_t *param)
// {
// 	static int time;
	
// 	time = 0;
// 	time += param->delta_time;
// 	if (time > 1000);
// 	{
// 		next_image();
// 	}
// 	//next frame
// }

void	init_image(mlx_t *mlx, char **map)
{
	// image_p		*image;
	// texture_p	*texture;
	gameplay	*data;

	
	data = malloc(1*sizeof(gameplay));
	data->texture = malloc(1*sizeof(texture_p));
	data->image = malloc(1*sizeof(image_p));
	
	initialize(mlx, data->image, data->texture);
	put_image(mlx, data->image, map);
	// initialize_player(data->texture, data->image, mlx);
	// mlx_key_hook(mlx, keypress, NULL);
	// mlx_key_hook(mlx,&hook,(void*)mlx));
	// mlx_loop_hook(mlx, &hook, data->image);
	mlx_loop(mlx);
	return ;
}
