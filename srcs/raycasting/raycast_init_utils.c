/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_init_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <ssinanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:49:30 by nadgalle          #+#    #+#             */
/*   Updated: 2025/04/09 11:45:26 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"

t_pos	ft_get_player_first_pos(t_map map)
{
	t_pos	player;

	player.x = map.player_x * TILESIZE + TILESIZE / 2;
	player.y = map.player_y * TILESIZE + TILESIZE / 2;
	return (player);
}

double	ft_get_player_first_angle(t_map map)
{
	double	angle_deg;
	double	angle;

	angle_deg = 0;
	if (ft_strncmp(&map.player_direction, "N", 1) == 0)
		angle_deg = 270;
	else if (ft_strncmp(&map.player_direction, "S", 1) == 0)
		angle_deg = 90;
	else if (ft_strncmp(&map.player_direction, "W", 1) == 0)
		angle_deg = 180;
	else if (ft_strncmp(&map.player_direction, "E", 1) == 0)
		angle_deg = 0;
	angle = ft_convert_to_radian(angle_deg);
	return (angle);
}
