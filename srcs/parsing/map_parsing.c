/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <ssinanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:31:49 by ssinanis          #+#    #+#             */
/*   Updated: 2025/04/03 20:14:33 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_parsing_map(t_game *game, char *filename)
{
	if (!filename || ft_strlen(filename) < 5
		|| ft_strrncmp(filename, ".cub", 4))
	{
		ft_error_print("Map file extension error.", game);
	}
	game->map.map_path = filename;
	game->map.file_content = ft_convert_file(filename);
	ft_tilepaths_and_colours(&game->map, game->map.file_content, game);
	ft_read_map(&game->map, game->map.file_content, game);
	ft_free_tab(game->map.file_content);
}

void	ft_update_map_dimensions(t_map *map, char *line)
{
	size_t	line_len;

	line_len = ft_strlen(line);
	if (line_len > 0 && line[line_len - 1] == '\n')
		line_len--;
	if ((int)line_len > map->map_width)
		map->map_width = line_len;
}

void	ft_parse_colour(char *line, int *colourcode, t_game *game)
{
	char	**rgb;

	rgb = ft_split(line + 2, ',');
	if (!rgb)
	{
		free(line);
		ft_error_print("Malloc failure.", game);
	}
	free(line);
	ft_check_colours(rgb, colourcode, game);
	ft_free_tab(rgb);
}

void	ft_check_colours(char **rgb, int *colourcode, t_game *game)
{
	int	i;

	i = 0;
	while (rgb[i] && i < 3)
	{
		colourcode[i] = ft_atoi(rgb[i]);
		if (colourcode[i] < 0 || colourcode[i] > 255)
		{
			ft_free_tab(rgb);
			ft_error_print("Wrong colour values [0-255].", game);
		}
		i++;
	}
	if (i != 3 || rgb[i])
	{
		ft_free_tab(rgb);
		ft_error_print("Wrong colour format [RGB format].", game);
	}
}

void	ft_tilepaths_and_colours(t_map *map, char **file_content, t_game *game)
{
	int		six_config_lines_counter;
	int		flag;
	int		i;
	char	*line_trimmed;

	six_config_lines_counter = 0;
	flag = ((i = 0));
	map->north_tile = NULL;
	map->south_tile = NULL;
	map->west_tile = NULL;
	map->east_tile = NULL;
	while (file_content[i] && six_config_lines_counter < 6)
	{
		line_trimmed = ft_trim_spaces(file_content[i]);
		if (!line_trimmed || line_trimmed[0] == '\0')
		{
			free(line_trimmed);
			i++;
			continue ;
		}
		ft_line(line_trimmed, &six_config_lines_counter, &flag, game);
		if (flag)
			break ;
		i++;
	}
}
