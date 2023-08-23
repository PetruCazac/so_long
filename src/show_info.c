/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:17:26 by pcazac            #+#    #+#             */
/*   Updated: 2023/08/23 18:54:15 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	fps(void *param)
{
	t_game				*data;
	static mlx_image_t	*t;
	static mlx_image_t	*t2;
	char				*d;
	char				*dd;

	data = (t_game *)param;
	if (t)
		mlx_delete_image(data->mlx, t);
	dd = ft_itoa((double) 1 / data->mlx->delta_time);
	d = ft_strjoin("FPS:", dd);
	free(dd);
	t = mlx_put_string(data->mlx, d, 10, 10);
	mlx_set_instance_depth(t->instances, 249);
	free(d);
	if (t2)
		mlx_delete_image(data->mlx, t2);
	dd = ft_itoa(data->score);
	d = ft_strjoin("SCORE ", dd);
	free(dd);
	t2 = mlx_put_string(data->mlx, d, 10, 30);
	mlx_set_instance_depth(t2->instances, 249);
	free(d);
}
