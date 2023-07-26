/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:31:06 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/22 20:08:57 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	get_exit_position(char **map, t_game *data)
{
	int i;
	int j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'E')
			{
				data->e_x = j * I_SIZE;
				data->e_y = i * I_SIZE;
			}
		}
	}
}

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


void initialize_exit(t_game *data)
{
	int			i;
	char		**path;

	get_exit_position(data->map, data);
	path = get_exit_path();
	i = 0;
	while (path[i][0] != '\0')
	{
		if (add_texture(new_texture(path[i]), &(data->exit)) == 1)
			return ; // free everything
		i++;
	}
}

void	exit_hook(void *param)
{
	t_game				*data;
	static mlx_image_t *t;
	char *d;
	char *dd;

	
	data = (t_game*) param;
	if (t)
		mlx_delete_image(data->mlx, t);
	dd = ft_itoa((double) 1 / data->mlx->delta_time);
	d = ft_strjoin("FPS:", dd);
	free(dd);
	t = mlx_put_string(data->mlx, d, 0, 0);
	mlx_set_instance_depth(t->instances, 249);
	data = (t_game*) param;
	data->time++;
	if (data->time > ITERATIONS)
	{
		if(data->exit_image != NULL)
			mlx_delete_image(data->mlx, data->exit_image);
		data->exit_image = mlx_texture_to_image(data->mlx, data->exit->texture);
		mlx_resize_image(data->exit_image, P_SIZE, P_SIZE);
		mlx_image_to_window(data->mlx, data->exit_image, data->e_x, data->e_y);
		mlx_set_instance_depth(data->exit_image->instances, 249);
		data->exit = data->exit->next;
	}
}
