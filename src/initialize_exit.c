/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:31:06 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/20 16:13:44 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

char	**get_exit_path(void)
{
	char **path;

	path = ft_calloc(7, sizeof(char *));
	path[0] = ft_strdup("Textures/Fire/fire1.png");
	path[1] = ft_strdup("Textures/Fire/fire2.png");
	path[2] = ft_strdup("Textures/Fire/fire3.png");
	path[3] = ft_strdup("Textures/Fire/fire4.png");
	path[4] = ft_strdup("Textures/Fire/fire5.png");
	path[5] = ft_strdup("Textures/Fire/fire6.png");
	path[6] = "\0";
	return (path);
}


void initialize_exit(gameplay *data)
{
	int			i;
	char		**path;

	get_position(data->exit, data->map, 'E');
	path = get_exit_path();
	data->exit->texture = mlx_load_png(path[0]);
	data->exit->image = mlx_texture_to_image(data->mlx, data->exit->texture);
	mlx_resize_image(data->exit->image, I_SIZE, I_SIZE);
	data->exit->next = data->exit;
	i = 1;
	while (path[i][0] != '\0')
	{
		if (new_image(add_image(data, path[i]), data->exit) == 1)
			return ; // free everything
		i++;
	}
}

void	exit_hook(void *param)
{
	gameplay	*data;

	data = (gameplay*) param;
	if (data->time > 5)
	{
		data->exit->image->enabled = 1;
		data->exit->previous->image->enabled = 0;
		mlx_image_to_window(data->mlx, data->exit->image, data->exit->pos_x, data->exit->pos_y);
		// mlx_set_instance_depth(data->exit->image->instances, );
		data->exit = data->exit->next;
	}
	//next frame
}