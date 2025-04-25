/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <ssinanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:21:01 by ssinanis          #+#    #+#             */
/*   Updated: 2025/04/03 19:40:39 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_add_valid_line(char *line, int *player_counter, int idx, t_game *game)
{
	int		b;
	size_t	line_len;

	b = 0;
	line_len = ft_strlen(line);
	ft_strncpy(game->map.map[idx], line, line_len);
	while (game->map.map[idx][b])
	{
		if (ft_strchr("NSWE", game->map.map[idx][b]))
		{
			(*player_counter)++;
			game->map.player_x = b;
			game->map.player_y = idx;
			game->map.player_direction = game->map.map[idx][b];
		}
		else if (game->map.map[idx][b] != '0'
			&& game->map.map[idx][b] != '1'
			&& game->map.map[idx][b] != ' ')
			ft_error_print("Invalid characters in map.", game);
		b++;
	}
	return (1);
}

void	ft_validate_player_counter(int player_counter, t_game *game)
{
	if (player_counter != 1)
		ft_error_print("Invalid number of players!", game);
}

void	ft_check_walls(t_map *my_map, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < my_map->map_height)
	{
		x = 0;
		while (x < my_map->map_width && my_map->map[y][x])
		{
			ft_check_chars(game, x, y);
			x++;
		}
		y++;
	}
	ft_validate_map(my_map, game);
}

void	ft_check_chars(t_game *game, int x, int y)
{
	if (!ft_strchr("01NSWE ", game->map.map[y][x]))
		ft_error_print("Invalid characters in map.", game);
	if (ft_strchr("NSWE", game->map.map[y][x]))
		ft_check_position_of_player(game, x, y);
}

int	ft_check_position_of_player(t_game *game, int x, int y)
{
	if (y == 0 || y == game->map.map_height - 1
		|| x == 0 || x == game->map.map_width - 1
		|| x >= (int)ft_strlen(game->map.map[y]))
		ft_error_print("Player at the edge of map.", game);
	return (1);
}
