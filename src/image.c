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

void keypress(mlx_key_data_t keydata, void* param)
{
	gameplay	*data;

	data = (gameplay*) param;
	if (keydata.key == 87 && keydata.action == 2)
	{
		
	}
}

void	hook(void *param)
{
	gameplay	*data;

	data = (gameplay*) param;
	data->time ++;
	if (data->time > 6)
	{
		mlx_image_to_window(data->mlx, data->player->image, data->player->pos_x, data->player->pos_y);
		mlx_set_instance_depth(data->player->image->instances, 10);
		data->player = data->player->next;
		data->time = 0;
	}
	//next frame
}

void	init_image(mlx_t *mlx, char **map)
{
	gameplay	*data;
	
	data = malloc(1*sizeof(gameplay));
	data->texture = malloc(1*sizeof(texture_p));
	data->image = malloc(1*sizeof(image_p));
	data->player = malloc(1*sizeof(animation_l));
	data->map = map;
	data->mlx = mlx;
	initialize(data);
	put_image(data);
	initialize_player(data, mlx);
	// ft_printf("here1");
	mlx_key_hook(mlx, keypress, data);
	// mlx_key_hook(mlx,&hook,(void*)mlx));
	data->time = 0;
	if (!mlx_loop_hook(mlx, &hook, (void *) data))
	{
		perror("Not Working");
		exit(errno);
	}
	// ft_printf("here4");
	mlx_loop(mlx);
	return ;
}
