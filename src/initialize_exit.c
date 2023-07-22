/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:31:06 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/21 18:52:22 by pcazac           ###   ########.fr       */
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
	static mlx_image_t	*image_p;

	data = (t_game*) param;
	data->time++;
	if (data->time > 5)
	{
		if(image_p != NULL)
			mlx_delete_image(data->mlx, image_p);
		image_p = mlx_texture_to_image(data->mlx, data->exit->texture);
		mlx_resize_image(image_p, I_SIZE, I_SIZE);
		mlx_image_to_window(data->mlx, image_p, data->e_x, data->e_y);
		mlx_set_instance_depth(image_p->instances, 249);
		data->exit = data->exit->next;
		// data->time = 0;
	}
	//next frame
}
