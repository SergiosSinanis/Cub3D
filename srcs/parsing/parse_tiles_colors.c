/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tiles_colors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <ssinanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:31:47 by ssinanis          #+#    #+#             */
/*   Updated: 2025/04/03 17:50:31 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_reach_map(char *line_trimmed, int six_config_lines_counter, t_game *game)
{
	if (line_trimmed[0] == '1' || line_trimmed[0] == '0')
	{
		if (six_config_lines_counter < 6)
		{
			free(line_trimmed);
			ft_error_print("Missing map info [colours and/or tiles].", game);
		}
		return (1);
	}
	return (0);
}

int	ft_tilepath_lines(t_map *map, char *trimmed, int *counter, t_game *game)
{
	if (ft_strncmp(trimmed, "NO ", 3) == 0 && !map->north_tile)
	{
		ft_process_tile(&map->north_tile, trimmed, "NO tile problem.", game);
		(*counter)++;
	}
	else if (ft_strncmp(trimmed, "SO ", 3) == 0 && !map->south_tile)
	{
		ft_process_tile(&map->south_tile, trimmed, " SO tile problem.", game);
		(*counter)++;
	}
	else if (ft_strncmp(trimmed, "WE ", 3) == 0 && !map->west_tile)
	{
		ft_process_tile(&map->west_tile, trimmed, "WE tile problem.", game);
		(*counter)++;
	}
	else if (ft_strncmp(trimmed, "EA ", 3) == 0 && !map->east_tile)
	{
		ft_process_tile(&map->east_tile, trimmed, "EA tile problem.", game);
		(*counter)++;
	}
	else
		return (0);
	return (1);
}

void	ft_process_tile(char **tile, char *path, char *error_msg, t_game *game)
{
	*tile = ft_trim_spaces(path + 3);
	free(path);
	if (!ft_check_file(*tile))
	{
		free(*tile);
		*tile = NULL;
		ft_error_print(error_msg, game);
	}
}

int	ft_check_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int	ft_colour_lines(t_game *game, char *line_trimmed, int *six_lines_counter)
{
	if (ft_strncmp(line_trimmed, "F ", 2) == 0)
	{
		ft_parse_colour(line_trimmed, game->map.floor_color, game);
		(*six_lines_counter)++;
		return (1);
	}
	else if (ft_strncmp(line_trimmed, "C ", 2) == 0)
	{
		ft_parse_colour(line_trimmed, game->map.ceiling_color, game);
		(*six_lines_counter)++;
		return (1);
	}
	return (0);
}
