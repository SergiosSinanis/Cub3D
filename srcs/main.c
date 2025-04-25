/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <ssinanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:22:35 by ssinanis          #+#    #+#             */
/*   Updated: 2025/04/09 11:44:57 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

int	main(int argc, char **argv)
{
	t_game		my_game;
	t_raycast	*raycast;

	if (argc != 2)
		ft_error_print("Error, invalid number of arguments.", NULL);
	ft_memset(&my_game, 0, sizeof(t_game));
	ft_parsing_map(&my_game, argv[1]);
	ft_init_game(&my_game);
	raycast = init_raycast(&my_game);
	if (!raycast)
	{
		ft_free_game(raycast);
		return (1);
	}
	mlx_loop_hook(my_game.mlx_ptr, &ft_render_game, raycast);
	mlx_hook(my_game.window_ptr, KeyPress,
		KeyPressMask, &keypress_moves, raycast);
	mlx_hook(my_game.window_ptr, 17, 0, &ft_free_game, raycast);
	mlx_loop(my_game.mlx_ptr);
	return (0);
}
