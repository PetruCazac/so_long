/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:31:06 by pcazac            #+#    #+#             */
/*   Updated: 2023/07/20 17:24:56 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	get_position(animation_l *obj, char ** map, char element)
{
	int i;
	int j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == element)
			{
				obj->pos_x = j * 50;
				obj->pos_y = i * 50;
			}
		}
	}
}

char	**get_player_path(void)
{
	char **path;

	path = ft_calloc(5, sizeof(char *));
	path[0] = ft_strdup("Textures/Vampire/Vampire1.png");
	path[1] = ft_strdup("Textures/Vampire/Vampire2.png");
	path[2] = ft_strdup("Textures/Vampire/Vampire3.png");
	path[3] = ft_strdup("Textures/Vampire/Vampire4.png");
	path[4] = "\0";
	return (path);
}


void initialize_player(gameplay *data)
{
	int			i;
	char		**path;

	get_position(data->player, data->map, 'P');
	path = get_player_path();
	data->player->texture = mlx_load_png(path[0]);
	data->player->image = mlx_texture_to_image(data->mlx, data->player->texture);
	mlx_resize_image(data->player->image, I_SIZE, I_SIZE);
	data->player->next = data->player;
	i = 0;
	while (path[i][0] != '\0')
	{
		if (new_image(add_image(data, path[i]), data->player) == 1)
			return ; // free everything
		i++;
	}
}

void	player_hook(void *param)
{
	gameplay	*data;
	static mlx_image_t *t;
	char *d;
	char *dd;
	data = (gameplay*) param;

	if (t)
		mlx_delete_image(data->mlx, t);
	dd = ft_itoa((double) 1 / data->mlx->delta_time);
	d = ft_strjoin("FPS:", dd);
	free(dd);
	t = mlx_put_string(data->mlx, d, 0, 0);
	data->time ++;
	if (data->time > 2)
	{
		data->player->image->enabled = 1;
		data->player->previous->image->enabled = 0;
		mlx_image_to_window(data->mlx, data->player->image, data->player->pos_x, data->player->pos_y);
		// mlx_set_instance_depth(data->player->image->instances, 10);
		data->player = data->player->next;
	}
	//next frame
}