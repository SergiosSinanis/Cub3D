/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_hit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <ssinanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:28:49 by nadgalle          #+#    #+#             */
/*   Updated: 2025/04/09 11:45:08 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"

void	ft_h_hit(t_pos *next_hit, t_pos *step, t_ray *ray, t_raycast *raycast)
{
	next_hit->y = floor(raycast->player_pos.y / TILESIZE) * TILESIZE;
	if (ft_is_looking_down(ray->r_angle))
	{
		next_hit->y += TILESIZE;
		step->y = TILESIZE;
	}
	else
	{
		next_hit->y += -0.01;
		step->y = -TILESIZE;
	}
	next_hit->x = (next_hit->y - raycast->player_pos.y)
		/ tan(ray->r_angle) + raycast->player_pos.x;
	step->x = step->y / tan(ray->r_angle);
}

void	ft_find_horizontal_hit(t_ray *ray, t_raycast *raycast)
{
	t_pos	next_hit_pos;
	t_pos	step_to_next_hit;

	ft_h_hit(&next_hit_pos, &step_to_next_hit, ray, raycast);
	while (next_hit_pos.x >= 0 && next_hit_pos.x
		< raycast->game->map_width * TILESIZE
		&& next_hit_pos.y >= 0 && next_hit_pos.y
		< raycast->game->map_height * TILESIZE)
	{
		if (ft_is_in_wall(next_hit_pos, raycast->game->map.map) == 1)
		{
			ray->horizontal_hit = next_hit_pos;
			ray->horizontal_hit_flag = 1;
			break ;
		}
		next_hit_pos.x += step_to_next_hit.x;
		next_hit_pos.y += step_to_next_hit.y;
	}
}
