/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <ssinanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:33:13 by ssinanis          #+#    #+#             */
/*   Updated: 2025/04/09 11:44:48 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"

void	ft_draw_background(t_raycast *raycast)
{
	int	i;
	int	j;
	int	ceiling;
	int	floor;

	i = 0;
	ceiling = ft_convert_rgb(raycast->game->map.ceiling_color);
	floor = ft_convert_rgb(raycast->game->map.floor_color);
	while (i++ <= raycast->window_height / 2)
	{
		j = 0;
		while (j++ < raycast->window_width)
			ft_put_pixel_to_img(&raycast->game->img, j, i, ceiling);
	}
	while (i++ < raycast->window_height)
	{
		j = 0;
		while (j++ < raycast->window_width)
			ft_put_pixel_to_img(&raycast->game->img, j, i, floor);
	}
}

void	ft_find_wall_height(t_raycast *raycast, int idx)
{
	double	d_player_screen;
	double	ray_length_corrected;
	double	height;
	double	height_start;

	height = 0;
	height_start = 0;
	ft_find_ray_hit(&raycast->rays[idx], raycast);
	d_player_screen = (raycast->window_width / 2)
		/ tan(ft_convert_to_radian(FOV) / 2);
	ray_length_corrected = raycast->rays[idx].ray_length
		* cos(raycast->player_angle - raycast->rays[idx].r_angle);
	height = (TILESIZE / ray_length_corrected) * d_player_screen;
	height_start = (raycast->window_height / 2) - (height / 2);
	raycast->rays[idx].height_start = height_start;
	raycast->rays[idx].wall_height = height;
}

void	ft_draw_stripe(t_raycast *raycast, int idx, t_pos t_pos, double step_y)
{
	int		y;
	int		x;
	int		pixel_color;
	int		text_y;
	void	*texture;

	y = 0;
	texture = ft_get_texture(raycast, &raycast->rays[idx]);
	while (y < (int)round(raycast->rays[idx].wall_height))
	{
		text_y = (int)t_pos.y & (TEXTURE_SIZE - 1);
		if (((int)round(raycast->rays[idx].height_start) + y < 0)
			|| ((int)round(raycast->rays[idx].height_start) + y
				>= raycast->window_height))
			break ;
		pixel_color = ft_get_texture_color(texture, (int)t_pos.x, text_y);
		x = 0;
		while (x++ < RESOLUTION)
			ft_put_pixel_to_img(&raycast->game->img, idx * RESOLUTION + x,
				(int)round(raycast->rays[idx].height_start) + y, pixel_color);
		t_pos.y += step_y;
		y++;
	}
}

void	ft_draw_walls(t_raycast *raycast, int idx)
{
	t_pos		texture_pos;
	double		texture_step_y;

	ft_find_wall_height(raycast, idx);
	texture_pos = ft_get_texture_pos(&raycast->rays[idx]);
	texture_step_y = (double)(TEXTURE_SIZE / raycast->rays[idx].wall_height);
	if (raycast->rays[idx].wall_height > raycast->window_height)
	{
		texture_pos.y = (raycast->rays[idx].wall_height
				- raycast->window_height) / 2 * texture_step_y;
		raycast->rays[idx].wall_height = raycast->window_height;
		raycast->rays[idx].height_start = 0;
	}
	ft_draw_stripe(raycast, idx, texture_pos, texture_step_y);
}

int	ft_render_game(t_raycast *raycast)
{
	int	i;

	i = 0;
	ft_memset(raycast->game->img.addr, 0, raycast->window_width
		* raycast->window_height * (raycast->game->img.bits_per_pixel / 8));
	ft_draw_background(raycast);
	while (i < raycast->nb_of_rays)
	{
		ft_draw_walls(raycast, i);
		i++;
	}
	mlx_put_image_to_window(raycast->game->mlx_ptr, raycast->game->window_ptr,
		raycast->game->img.img_ptr, 0, 0);
	return (0);
}
