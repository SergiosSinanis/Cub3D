/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <ssinanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:49:35 by nadgalle          #+#    #+#             */
/*   Updated: 2025/04/09 11:45:40 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycasting.h"

int	ft_is_looking_down(double angle)
{
	if (angle > 0 && angle < PI)
		return (1);
	else
		return (0);
}

int	ft_is_looking_left(double angle)
{
	if (angle > PI / 2 && angle < PI * 3 / 2)
		return (1);
	else
		return (0);
}

