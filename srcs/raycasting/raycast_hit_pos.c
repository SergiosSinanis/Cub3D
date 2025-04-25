/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_hit_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadgalle <nadgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:20:08 by nadgalle          #+#    #+#             */
/*   Updated: 2025/04/02 15:28:43 by nadgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"

void	ray_len(double *h_d, double *v_d, t_ray *ray, t_raycast *raycast)
{
	ft_find_horizontal_hit(ray, raycast);
	ft_find_vertical_hit(ray, raycast);
	if (ray->horizontal_hit_flag == 1)
		*h_d = ft_distance(raycast->player_pos, ray->horizontal_hit);
	else
		*h_d = 1e30;
	if (ray->vertical_hit_flag == 1)
		*v_d = ft_distance(raycast->player_pos, ray->vertical_hit);
	else
		*v_d = 1e30;
}

void	ft_find_ray_hit(t_ray *ray, t_raycast *raycast)
{
	double	h_hit_distance;
	double	v_hit_distance;

	ray_len(&h_hit_distance, &v_hit_distance, ray, raycast);
	if (h_hit_distance < v_hit_distance)
	{
		ray->hit = ray->horizontal_hit;
		ray->ray_length = h_hit_distance;
		if (ft_is_looking_down(ray->r_angle))
			ray->orientation = N;
		else
			ray->orientation = S;
	}
	else
	{
		ray->hit = ray->vertical_hit;
		ray->ray_length = v_hit_distance;
		if (ft_is_looking_left(ray->r_angle))
			ray->orientation = E;
		else
			ray->orientation = W;
	}
}
