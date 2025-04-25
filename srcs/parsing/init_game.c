/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <ssinanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:22:54 by ssinanis          #+#    #+#             */
/*   Updated: 2025/04/09 11:44:00 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_init_game(t_game *my_game)
{
	my_game->map_width = my_game->map.map_width;
	my_game->map_height = my_game->map.map_height;
	my_game->x = my_game->map.player_x;
	my_game->y = my_game->map.player_y;
	my_game->mlx_ptr = mlx_init();
	if (!my_game->mlx_ptr)
		ft_error_print("Error: MLX initialization failed.", my_game);
	my_game->window_ptr = mlx_new_window(my_game->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "CUB3D");
	my_game->img.img_ptr = mlx_new_image(my_game->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	my_game->img.addr = mlx_get_data_addr(my_game->img.img_ptr,
			&my_game->img.bits_per_pixel,
			&my_game->img.line_length, &my_game->img.endian);
	ft_init_game_tiles(my_game);
	return (my_game->north_tile && my_game->south_tile
		&& my_game->west_tile && my_game->east_tile);
}

void	ft_init_game_tiles(t_game *my_game)
{
	int	i;
	int	b;

	i = 0;
	b = 0;
	my_game->north_tile = mlx_xpm_file_to_image(my_game->mlx_ptr,
			my_game->map.north_tile, &i, &b);
	my_game->south_tile = mlx_xpm_file_to_image(my_game->mlx_ptr,
			my_game->map.south_tile, &i, &b);
	my_game->west_tile = mlx_xpm_file_to_image(my_game->mlx_ptr,
			my_game->map.west_tile, &i, &b);
	my_game->east_tile = mlx_xpm_file_to_image(my_game->mlx_ptr,
			my_game->map.east_tile, &i, &b);
	if (!my_game->north_tile || !my_game->south_tile
		|| !my_game->west_tile || !my_game->east_tile)
		ft_error_print("Failed to charge tile.", my_game);
}
