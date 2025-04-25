/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <ssinanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:02:05 by ssinanis          #+#    #+#             */
/*   Updated: 2025/04/09 11:43:52 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_validate_map(t_map *map, t_game *game)
{
	char	**temp_map;
	int		i;
	int		b;
	int		player_position;

	temp_map = ft_copy_map(map);
	if (!temp_map)
		ft_error_print("Memory allocation failed.", game);
	player_position = ft_find_player(map, &i, &b);
	if (!player_position)
	{
		ft_free_tab(temp_map);
		ft_error_print("No player found.", game);
	}
	ft_flood_fill(map, temp_map, b, i, game);
	ft_free_tab(temp_map);
}

char	**ft_copy_map(t_map *map)
{
	char	**temp_map;
	int		i;

	temp_map = (char **)malloc(sizeof(char *) * (map->map_height + 1));
	if (!temp_map)
		return (NULL);
	i = 0;
	while (i < map->map_height)
	{
		temp_map[i] = (char *)malloc(sizeof(char) * (map->map_width + 1));
		if (!temp_map[i])
		{
			ft_free_temp_map(temp_map, i);
			return (NULL);
		}
		ft_memcpy(temp_map[i], map->map[i], map->map_width);
		temp_map[i][map->map_width] = '\0';
		i++;
	}
	temp_map[i] = NULL;
	return (temp_map);
}

int	ft_find_player(t_map *map, int *row, int *col)
{
	int	i;
	int	b;

	i = 0;
	while (i < map->map_height)
	{
		b = 0;
		while (b < map->map_width)
		{
			if (ft_strchr("NSWE", map->map[i][b]))
			{
				*row = i;
				*col = b;
				return (1);
			}
			b++;
		}
		i++;
	}
	return (0);
}

void	ft_flood_fill(t_map *map, char **temp_map, int x, int y, t_game *game)
{
	if (x < 0 || y < 0 || x >= map->map_width || y >= map->map_height)
	{
		ft_free_tab(temp_map);
		ft_error_print("Map is not surrounded by walls and/or invalid spaces found.", game);
		return ;
	}
	if (temp_map[y][x] == ' ' || temp_map[y][x] == '\0')
	{
		ft_free_tab(temp_map);
		ft_error_print("Map is not surrounded by walls and/or invalid spaces found.", game);
	}
	if (temp_map[y][x] == '1' || temp_map[y][x] == 'V')
		return ;
	temp_map[y][x] = 'V';
	ft_flood_fill(map, temp_map, x + 1, y, game);
	ft_flood_fill(map, temp_map, x - 1, y, game);
	ft_flood_fill(map, temp_map, x, y + 1, game);
	ft_flood_fill(map, temp_map, x, y - 1, game);
}
