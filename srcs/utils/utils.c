/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <ssinanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:15:03 by ssinanis          #+#    #+#             */
/*   Updated: 2025/04/03 14:20:54 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/raycasting.h"

void	ft_error_print(char *message, t_game *game)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	if (game)
		ft_cleanup_game(game);
	exit (1);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_cleanup_game(t_game *game)
{
	if (game->map.file_content)
		ft_free_tab(game->map.file_content);
	if (game->map.map)
		ft_free_tab(game->map.map);
	if (game->map.north_tile)
		free(game->map.north_tile);
	if (game->map.south_tile)
		free(game->map.south_tile);
	if (game->map.west_tile)
		free(game->map.west_tile);
	if (game->map.east_tile)
		free(game->map.east_tile);
}

void	ft_free_map_and_tiles(t_raycast *raycast)
{
	int	i;

	if (raycast->game->map.north_tile)
		free(raycast->game->map.north_tile);
	if (raycast->game->map.south_tile)
		free(raycast->game->map.south_tile);
	if (raycast->game->map.west_tile)
		free(raycast->game->map.west_tile);
	if (raycast->game->map.east_tile)
		free(raycast->game->map.east_tile);
	if (raycast->game->map.map)
	{
		i = 0;
		while (raycast->game->map.map[i] != NULL)
		{
			free(raycast->game->map.map[i]);
			i++;
		}
		free(raycast->game->map.map);
	}
}

int	ft_free_game(t_raycast *raycast)
{
	ft_free_map_and_tiles(raycast);
	if (raycast->game->north_tile)
		mlx_destroy_image(raycast->game->mlx_ptr, raycast->game->north_tile);
	if (raycast->game->south_tile)
		mlx_destroy_image(raycast->game->mlx_ptr, raycast->game->south_tile);
	if (raycast->game->west_tile)
		mlx_destroy_image(raycast->game->mlx_ptr, raycast->game->west_tile);
	if (raycast->game->east_tile)
		mlx_destroy_image(raycast->game->mlx_ptr, raycast->game->east_tile);
	if (raycast->game->img.img_ptr)
		mlx_destroy_image(raycast->game->mlx_ptr, raycast->game->img.img_ptr);
	if (raycast->game->window_ptr)
		mlx_destroy_window(raycast->game->mlx_ptr, raycast->game->window_ptr);
	if (raycast->game->mlx_ptr)
	{
		mlx_destroy_display(raycast->game->mlx_ptr);
		free(raycast->game->mlx_ptr);
	}
	if (raycast->rays)
		free(raycast->rays);
	free(raycast);
	exit(0);
	return (0);
}
