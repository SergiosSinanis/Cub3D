/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <ssinanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:11:27 by ssinanis          #+#    #+#             */
/*   Updated: 2025/04/09 11:42:57 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>

# include "../minilibx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# include "../srcs/libft/libft.h"

# ifndef PI
#  define PI 3.141592653589793
# endif

# ifndef TILESIZE
#  define TILESIZE 32
# endif

# ifndef FOV
#  define FOV 66
# endif

# ifndef RESOLUTION
#  define RESOLUTION 4
# endif

# ifndef ROT_SPEED
#  define ROT_SPEED  0.2617993877991
# endif

# ifndef MOVE_SPEED
#  define MOVE_SPEED 5
# endif

# ifndef TEXTURE_SIZE
#  define TEXTURE_SIZE 64
# endif

# ifndef WINDOW_WIDTH
#  define WINDOW_WIDTH 1280
# endif

# ifndef WINDOW_HEIGHT
#  define WINDOW_HEIGHT 800
# endif

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_map
{
	char	**file_content;
	char	*north_tile;
	char	*south_tile;
	char	*west_tile;
	char	*east_tile;
	char	**map;
	char	*map_path;
	char	player_direction;
	int		floor_color[3];
	int		ceiling_color[3];
	int		map_height;
	int		map_width;
	int		player_x;
	int		player_y;
}	t_map;

typedef struct t_game
{
	t_img	img;
	void	*mlx_ptr;
	void	*window_ptr;
	void	*north_tile;
	void	*south_tile;
	void	*west_tile;
	void	*east_tile;
	int		map_height;
	int		map_width;
	int		x;
	int		y;
	t_map	map;
}	t_game;

// Parsing
void	ft_parsing_map(t_game *game, char *file);
void	ft_tilepaths_and_colours(t_map *map, char **file_content, t_game *game);
void	ft_parse_colour(char *line, int *colourcode, t_game *game);
void	ft_check_colours(char **rgb, int *colourcode, t_game *game);
void	ft_update_map_dimensions(t_map *map, char *line);
void	ft_process_tile(char **tile, char *path, char *error_msg, t_game *game);
void	ft_read_map(t_map *map, char **file_content, t_game *game);
void	ft_get_map_dimensions(t_map *map, char **file_content, t_game *game);
void	ft_init_map_copy(t_map *my_map, t_game *game);
void	ft_validate_player_counter(int player_counter, t_game *game);
void	ft_check_walls(t_map *my_map, t_game *game);
void	ft_check_chars(t_game *game, int x, int y);
void	ft_free_temp_map(char **temp_map, int height);
void	ft_validate_map(t_map *map, t_game *game);
void	ft_flood_fill(t_map *map, char **temp_map, int x, int y, t_game *game);
void	ft_init_game_tiles(t_game *my_game);
void	ft_line(char *trim, int *counter, int *flag, t_game *game);
char	**ft_read_entire_file(char *filename, t_game *game);
char	**ft_copy_map(t_map *map);
char	*ft_skip_six_lines(int fd, char **line);
int		ft_reach_map(char *line_trimmed, int counter, t_game *game);
int		ft_tilepath_lines(t_map *map, char *trim, int *counter, t_game *game);
int		ft_colour_lines(t_game *game, char *line_trimmed, int *counter);
int		ft_check_file(char *path);
int		ft_find_map_start(char **file_content);
int		ft_add_valid_line(char *line, int *p_counter, int idx, t_game *game);
int		ft_check_position_of_player(t_game *game, int x, int y);
int		ft_find_player(t_map *map, int *row, int *col);
int		ft_init_game(t_game *my_game);

// Utils
void	ft_error_print(char *message, t_game *game);
void	ft_cleanup_game(t_game *game);
void	ft_free_tab(char **tab);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_trim_spaces(char *str);
char	**ft_convert_file(char *file_path);
int		ft_strrncmp(const char *s1, const char *s2, size_t n);
int		ft_compare_end(size_t i, size_t b, const char *s1, const char *s2);

#endif
