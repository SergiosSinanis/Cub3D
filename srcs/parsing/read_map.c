/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <ssinanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:22:39 by ssinanis          #+#    #+#             */
/*   Updated: 2025/04/09 11:44:21 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_read_map(t_map *map, char **file_content, t_game *game)
{
	int	player_counter;
	int	map_start;
	int	i;
	int	map_row;

	player_counter = 0;
	ft_get_map_dimensions(map, file_content, game);
	ft_init_map_copy(map, game);
	map_start = ft_find_map_start(file_content);
	if (map_start == -1)
		ft_error_print("Map section not found.", game);
	map_row = 0;
	i = map_start;
	while (file_content[i] && map_row < map->map_height)
	{
		if (file_content[i][0] != '\0')
		{
			ft_add_valid_line(file_content[i], &player_counter, map_row, game);
			map_row++;
		}
		i++;
	}
	ft_validate_player_counter(player_counter, game);
	ft_check_walls(map, game);
}

void	ft_get_map_dimensions(t_map *map, char **file_content, t_game *game)
{
	int	i;
	int	map_start;

	map->map_height = 0;
	map->map_width = 0;
	map_start = ft_find_map_start(file_content);
	if (map_start == -1)
		ft_error_print("Map section not found.", game);
	i = map_start;
	while (file_content[i])
	{
		if (file_content[i][0] != '\0' && file_content[i][0] != '\n')
		{
			ft_update_map_dimensions(map, file_content[i]);
			map->map_height++;
		}
		i++;
	}
	if (map->map_height < 3 || map->map_width < 3)
		ft_error_print("Map is smaller than expected.", game);
}

void	ft_init_map_copy(t_map *my_map, t_game *game)
{
	int	i;

	my_map->map = (char **)malloc(sizeof(char *) * (my_map->map_height + 1));
	if (!my_map->map)
		ft_error_print("Memory allocation failed.", game);
	i = 0;
	while (i < my_map->map_height)
	{
		my_map->map[i] = (char *)malloc(sizeof(char)
				* (my_map->map_width + 1));
		if (!my_map->map[i])
			ft_error_print("Memory allocation failed.", game);
		ft_memset(my_map->map[i], ' ', my_map->map_width);
		my_map->map[i][my_map->map_width] = '\0';
		i++;
	}
	my_map->map[i] = NULL;
}

void	ft_free_temp_map(char **temp_map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(temp_map[i]);
		i++;
	}
	free(temp_map);
}
