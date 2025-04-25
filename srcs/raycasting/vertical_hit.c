/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_hit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadgalle <nadgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:28:47 by nadgalle          #+#    #+#             */
/*   Updated: 2025/04/02 15:32:02 by nadgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"

void	ft_v_hit(t_pos *next_hit, t_pos *step, t_ray *ray, t_raycast *raycast)
{	
	next_hit->x = floor(raycast->player_pos.x / TILESIZE) * TILESIZE;
	if (ft_is_looking_left(ray->r_angle))
	{
		next_hit->x += -0.01;
		step->x = -TILESIZE;
	}
	else
	{
		next_hit->x += TILESIZE;
		step->x = TILESIZE;
	}
	next_hit->y = (next_hit->x - raycast->player_pos.x)
		* tan(ray->r_angle) + raycast->player_pos.y;
	step->y = step->x * tan(ray->r_angle);
}

void	ft_find_vertical_hit(t_ray *ray, t_raycast *raycast)
{
	t_pos	next_hit_pos;
	t_pos	step_to_next_hit;

	ft_v_hit(&next_hit_pos, &step_to_next_hit, ray, raycast);
	while (next_hit_pos.x >= 0 && next_hit_pos.x
		< raycast->game->map_width * TILESIZE
		&& next_hit_pos.y >= 0 && next_hit_pos.y
		< raycast->game->map_height * TILESIZE)
	{
		if (ft_is_in_wall(next_hit_pos, raycast->game->map.map))
		{
			ray->vertical_hit = next_hit_pos;
			ray->vertical_hit_flag = 1;
			break ;
		}
		next_hit_pos.x += step_to_next_hit.x;
		next_hit_pos.y += step_to_next_hit.y;
	}
}
