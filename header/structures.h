/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcazac <pcazac@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:00:28 by pcazac            #+#    #+#             */
/*   Updated: 2023/08/27 18:13:19 by pcazac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_animation
{
	struct s_animation	*next;
	struct s_animation	*end;
	struct s_animation	*previous;
	mlx_texture_t		*texture;
}				t_animation;

typedef struct s_pair
{
	int	y;
	int	x;
}				t_pair;

typedef struct s_special
{
	int	c;
	int	p;
	int	e;
}				t_special;

typedef struct s_position
{
	struct s_position	*next;
	int					p_x;
	int					p_y;
}				t_position;

typedef struct s_texture
{
	mlx_texture_t	*walls;
	mlx_texture_t	*ground;

}				t_texture;

typedef struct s_image
{
	mlx_image_t	*walls;
	mlx_image_t	*ground;

}				t_image;

typedef struct s_cimage
{
	struct s_cimage		*next;
	mlx_image_t			*image;
	bool				touch;
	int					p_x;
	int					p_y;
}				t_cimage;

typedef struct s_element
{
	int				height;
	int				width;
	int				p_x;
	int				p_y;
	int				e_x;
	int				e_y;
	int				score;
	int				c_count;
	int				moves;
	int				time;
	int				time_p;
	char			**map;
	char			**coll_tp;
	char			**colld_tp;
	char			**player_tp;
	char			**exit_tp;
	char			**exited_tp;
	bool			exit_touch;
	bool			exited;
	mlx_t			*mlx;
	mlx_image_t		*player_img;
	mlx_image_t		*exit_image;
	t_cimage		*c_image;
	t_texture		texture;
	t_image			image;
	t_animation		*player;
	t_animation		*collectible;
	t_animation		*collected;
	t_animation		*exit;
	t_animation		*exit_valid;
}				t_game;

#endif
