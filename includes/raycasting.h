/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <ssinanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:27:29 by ssinanis          #+#    #+#             */
/*   Updated: 2025/04/09 11:43:10 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>

# include <X11/X.h>
# include <X11/keysym.h>
# include "../srcs/libft/libft.h"
# include "cub3d.h"

# define N 0
# define S 1
# define W 2
# define E 3

typedef struct s_pos
{
	double	x;
	double	y;
}			t_pos;

typedef struct s_ray
{
	double	r_angle;
	t_pos	vertical_hit;
	int		vertical_hit_flag;
	t_pos	horizontal_hit;
	int		horizontal_hit_flag;
	t_pos	hit;
	double	ray_length;
	int		orientation;
	double	wall_height;
	double	height_start;
}			t_ray;

typedef struct s_raycast
{
	t_pos	player_pos;
	double	player_angle;
	int		window_width;
	int		window_height;
	int		nb_of_rays;
	t_ray	*rays;
	t_game	*game;
}			t_raycast;

// Initialize
double		ft_get_player_first_angle(t_map map);
t_raycast	*init_raycast(t_game *game);
t_pos		ft_get_player_first_pos(t_map map);
t_ray		*init_rays(t_ray *rays, t_raycast *raycast);

// Raycasting
void		ft_h_hit(t_pos *next, t_pos *step, t_ray *ray, t_raycast *raycast);
void		ft_find_horizontal_hit(t_ray *ray, t_raycast *raycast);
void		ft_v_hit(t_pos *next, t_pos *step, t_ray *ray, t_raycast *raycast);
void		ft_find_vertical_hit(t_ray *ray, t_raycast *raycast);
void		ft_find_ray_hit(t_ray *ray, t_raycast *raycast);
int			ft_is_looking_down(double angle);
int			ft_is_looking_left(double angle);

// Player moves
int			keypress_moves(int key, t_raycast *raycast);
int			ft_rotate_player_pov(t_raycast *raycast, int direction);
int			ft_update_player_pos(t_raycast *raycast, int direction, int flag);

// Render
void		*ft_get_texture(t_raycast *raycast, t_ray *ray);
void		ft_find_wall_height(t_raycast *raycast, int idx);
void		ft_put_pixel_to_img(t_img *img, int x, int y, int color);
int			ft_convert_rgb(int *rgb);
int			ft_get_texture_color(void *texture_img, int t_x, int t_y);
int			ft_render_game(t_raycast *raycast);
t_pos		ft_get_texture_pos(t_ray *ray);

// Utils
void		ft_free_map_and_tiles(t_raycast *raycast);
double		ft_convert_to_radian(double deg_angle);
double		ft_normalize_angle(double angle);
double		ft_distance(t_pos A, t_pos B);
int			ft_is_in_wall(t_pos pos, char **map);
int			ft_free_game(t_raycast *raycast);

#endif
