/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadgalle <nadgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:07:03 by nadgalle          #+#    #+#             */
/*   Updated: 2025/04/02 15:32:38 by nadgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"

double	ft_convert_to_radian(double deg_angle)
{
	double	angle;

	angle = deg_angle * (PI / 180);
	return (angle);
}

double	ft_normalize_angle(double angle)
{
	angle = fmod(angle, 2 * PI);
	if (angle < 0)
		angle += 2 * PI;
	return (angle);
}

double	ft_distance(t_pos A, t_pos B)
{
	double	distance;

	distance = sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
	return (distance);
}

int	ft_is_in_wall(t_pos pos, char **map)
{
	if (map[(int)pos.y / TILESIZE][(int)pos.x / TILESIZE] == '1')
	{
		return (1);
	}
	return (0);
}
