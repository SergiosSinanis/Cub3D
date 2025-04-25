/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadgalle <nadgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:58:55 by nadgalle          #+#    #+#             */
/*   Updated: 2025/04/02 12:58:47 by nadgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"

t_ray	*init_rays(t_ray *rays, t_raycast *raycast)
{
	int		i;
	double	ray_angle;
	double	delta_angle;

	i = 0;
	delta_angle = ft_convert_to_radian(FOV) / raycast->nb_of_rays;
	ray_angle = raycast->player_angle - ft_convert_to_radian(FOV) / 2;
	while (i < raycast->nb_of_rays)
	{
		rays[i].r_angle = ft_normalize_angle(ray_angle + delta_angle * i);
		rays[i].vertical_hit.x = 0;
		rays[i].vertical_hit.y = 0;
		rays[i].vertical_hit_flag = 0;
		rays[i].horizontal_hit.x = 0;
		rays[i].horizontal_hit.y = 0;
		rays[i].horizontal_hit_flag = 0;
		rays[i].hit.x = 0;
		rays[i].hit.y = 0;
		rays[i].ray_length = 0;
		rays[i].orientation = -1;
		rays[i].wall_height = 0;
		rays[i].height_start = 0;
		i++;
	}
	return (rays);
}

t_raycast	*init_raycast(t_game *game)
{
	t_raycast	*raycast;

	raycast = malloc(sizeof(t_raycast));
	if (!raycast)
		return (NULL);
	raycast->player_pos = ft_get_player_first_pos(game->map);
	raycast->player_angle = ft_get_player_first_angle(game->map);
	raycast->window_width = WINDOW_WIDTH;
	raycast->window_height = WINDOW_HEIGHT;
	raycast->nb_of_rays = floor(raycast->window_width / RESOLUTION);
	raycast->rays = malloc(sizeof(t_ray) * raycast->nb_of_rays);
	if (!raycast->rays)
	{
		free(raycast);
		return (NULL);
	}
	raycast->rays = init_rays(raycast->rays, raycast);
	raycast->game = game;
	return (raycast);
}
