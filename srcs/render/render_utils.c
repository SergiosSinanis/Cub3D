/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <ssinanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:33:27 by ssinanis          #+#    #+#             */
/*   Updated: 2025/04/09 11:44:37 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"

int	ft_convert_rgb(int *rgb)
{
	int	r;
	int	g;
	int	b;
	int	color;

	r = rgb[0];
	g = rgb[1];
	b = rgb[2];
	color = (r << 16) | (g << 8) | b;
	return (color);
}

void	ft_put_pixel_to_img(t_img *img, int x, int y, int color)
{
	void	*pixel;

	if (x < 0 || y < 0)
		return ;
	pixel = img->addr + (y * img->line_length + x
			* (img->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

void	*ft_get_texture(t_raycast *raycast, t_ray *ray)
{
	if (ray->orientation == N)
		return (raycast->game->north_tile);
	else if (ray->orientation == S)
		return (raycast->game->south_tile);
	else if (ray->orientation == W)
		return (raycast->game->west_tile);
	else if (ray->orientation == E)
		return (raycast->game->east_tile);
	else
		return (NULL);
}

t_pos	ft_get_texture_pos(t_ray *ray)
{
	t_pos	texture;

	texture.y = 0;
	if (ray->orientation == N)
		texture.x = fmod(ray->hit.x, TILESIZE) / TILESIZE;
	else if (ray->orientation == S)
		texture.x = 1 - fmod(ray->hit.x, TILESIZE) / TILESIZE;
	else if (ray->orientation == W)
		texture.x = fmod(ray->hit.y, TILESIZE) / TILESIZE;
	else if (ray->orientation == E)
		texture.x = 1 - fmod(ray->hit.y, TILESIZE) / TILESIZE;
	texture.x = texture.x * TEXTURE_SIZE;
	return (texture);
}

int	ft_get_texture_color(void *texture_img, int texture_x, int texture_y)
{
	char	*texture_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		color;

	texture_addr = mlx_get_data_addr(texture_img,
			&bits_per_pixel, &line_length, &endian);
	color = *(int *)(texture_addr + (texture_y
				* line_length + texture_x * (bits_per_pixel / 8)));
	return (color);
}
