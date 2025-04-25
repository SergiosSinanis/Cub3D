/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <ssinanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:48:33 by ssinanis          #+#    #+#             */
/*   Updated: 2025/04/09 11:43:35 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"

int	keypress_moves(int key, t_raycast *raycast)
{
	if (key == XK_w)
		ft_update_player_pos(raycast, 1, 1);
	if (key == XK_s)
		ft_update_player_pos(raycast, -1, 1);
	if (key == XK_d)
		ft_update_player_pos(raycast, 1, 0);
	if (key == XK_a)
		ft_update_player_pos(raycast, -1, 0);
	if (key == XK_Left)
		ft_rotate_player_pov(raycast, -1);
	if (key == XK_Right)
		ft_rotate_player_pov(raycast, 1);
	if (key == XK_Escape)
		ft_free_game(raycast);
	return (0);
}

int	ft_rotate_player_pov(t_raycast *raycast, int direction)
{
	int		turn_direction;

	turn_direction = 0;
	turn_direction = direction;
	raycast->player_angle = ft_normalize_angle(raycast->player_angle
			+ turn_direction * ROT_SPEED);
	raycast->rays = init_rays(raycast->rays, raycast);
	return (0);
}

int	ft_update_player_pos(t_raycast *raycast, int direction, int move_flag)
{
	double	move_step;
	t_pos	next_pos;

	move_step = direction * MOVE_SPEED;
	if (move_flag == 1)
	{
		next_pos.x = raycast->player_pos.x
			+ move_step * cos(raycast->player_angle);
		next_pos.y = raycast->player_pos.y
			+ move_step * sin(raycast->player_angle);
	}
	else
	{
		next_pos.x = raycast->player_pos.x
			+ move_step * cos(raycast->player_angle + (PI / 2));
		next_pos.y = raycast->player_pos.y
			+ move_step * sin(raycast->player_angle + (PI / 2));
	}
	if (ft_is_in_wall(next_pos, raycast->game->map.map) == 1)
		return (1);
	raycast->player_pos.x = next_pos.x;
	raycast->player_pos.y = next_pos.y;
	raycast->rays = init_rays(raycast->rays, raycast);
	return (0);
}
