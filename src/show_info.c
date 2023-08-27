/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:17:26 by pcazac            #+#    #+#             */
/*   Updated: 2023/08/27 18:25:13 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	put_moves(t_game *data)
{
	static mlx_image_t	*t;
	char				*d;
	char				*dd;

	if (t)
		mlx_delete_image(data->mlx, t);
	dd = ft_itoa(data->moves);
	d = ft_strjoin("Moves:", dd);
	free(dd);
	t = mlx_put_string(data->mlx, d, 10, 50);
	mlx_set_instance_depth(t->instances, 249);
	free(d);
}

void	put_score(t_game *data)
{
	static mlx_image_t	*t;
	char				*d;
	char				*dd;

	if (t)
			mlx_delete_image(data->mlx, t);
	dd = ft_itoa(data->score);
	d = ft_strjoin("SCORE ", dd);
	free(dd);
	t = mlx_put_string(data->mlx, d, 10, 30);
	mlx_set_instance_depth(t->instances, 249);
	free(d);
}

void	put_fps(t_game *data)
{
	static mlx_image_t	*t;
	char				*d;
	char				*dd;

	if (t)
		mlx_delete_image(data->mlx, t);
	dd = ft_itoa((double) 1 / data->mlx->delta_time);
	d = ft_strjoin("FPS:", dd);
	free(dd);
	t = mlx_put_string(data->mlx, d, 10, 10);
	mlx_set_instance_depth(t->instances, 249);
	free(d);
}

void	fps(void *param)
{
	t_game	*data;

	data = (t_game *)param;
	put_fps(data);
	put_score(data);
	put_moves(data);
}
