/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <ssinanis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:44:59 by ssinanis          #+#    #+#             */
/*   Updated: 2025/04/04 09:56:08 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static char	*ft_strjoin_free(char *buffer, char *buffer_tmp)
{
	char	*tmp;

	if (!buffer)
		return (buffer_tmp);
	if (!buffer_tmp)
		return (buffer);
	tmp = ft_strjoin(buffer, buffer_tmp);
	free(buffer);
	return (tmp);
}

char	**ft_convert_file(char *file_path)
{
	int		fd;
	int		rd;
	char	buffer[2];
	char	**map;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		ft_error_print("Error opening file", NULL);
		return (NULL);
	}
	rd = 1;
	line = ft_strdup("");
	while (rd > 0)
	{
		rd = read(fd, buffer, 1);
		buffer[rd] = '\0';
		line = ft_strjoin_free(line, buffer);
	}
	map = ft_split(line, '\n');
	free(line);
	return (map);
}

void	ft_line(char *trim, int *counter, int *flag, t_game *game)
{
	if (ft_tilepath_lines(&game->map, trim, counter, game)
		|| ft_colour_lines(game, trim, counter))
		return ;
	*flag = ft_reach_map(trim, *counter, game);
	if (!(*flag))
	{
		free(trim);
		ft_error_print("Invalid configuration line", game);
	}
}

int	ft_find_map_start(char **file_content)
{
	int	i;
	int	six_config_lines_counter;
	char	*line;

	i = 0;
	six_config_lines_counter = 0;
	while (file_content[i++])
	{
		line = ft_trim_spaces(file_content[i]);
		if (line && line[0] != '\0')
		{
			if (ft_strncmp(line, "NO ", 3) == 0
				|| ft_strncmp(line, "SO ", 3) == 0
				|| ft_strncmp(line, "WE ", 3) == 0
				|| ft_strncmp(line, "EA ", 3) == 0
				|| ft_strncmp(line, "F ", 2) == 0
				|| ft_strncmp(line, "C ", 2) == 0)
				six_config_lines_counter++;
			else if (line[0] == '1' || line[0] == '0')
			{
				free(line);
				return (i);
			}
		}
		free(line);
	}
	return (-1);
}
