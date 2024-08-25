/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 10:56:40 by minhulee          #+#    #+#             */
/*   Updated: 2024/08/25 18:22:37 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	convert_to_color(int (*dst)[3], char *data)
{
	char	**split;

	split = ft_split(data, ',');
	if (!split)
		ft_err("parsing :: invalid colors");
}

void	convert_to_w_f_c(t_cub3d *info, t_map_data *map_data, int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!map_data->walls[NO] && ft_strncmp(line, "NO ", 3))
			map_data->walls[NO] = load_xpm(info, remove_spaces(line + 2), 64);
		else if (!map_data->walls[SO] && ft_strncmp(line, "SO ", 3))
			map_data->walls[SO] = load_xpm(info, remove_spaces(line + 2), 64);
		else if (!map_data->walls[WE] && ft_strncmp(line, "WE ", 3))
			map_data->walls[WE] = load_xpm(info, remove_spaces(line + 2), 64);
		else if (!map_data->walls[EA] && ft_strncmp(line, "EA ", 3))
			map_data->walls[EA] = load_xpm(info, remove_spaces(line + 2), 64);
		else if (map_data->floor[0] < 0 && ft_strncmp(line, "F ", 2))
			convert_to_color(&(map_data->floor), remove_spaces(line + 1));
		else if (map_data->ceil[0] < 0 && ft_strncmp(line, "C ", 2))
			convert_to_color(&(map_data->ceil), remove_spaces(line + 1));
		else if (map_data->walls[NO] && map_data->walls[SO]
			&& map_data->walls[WE] && map_data->walls[EA])
				break ;
		free(line);
	}
}

void	convert_to_cub(t_map_data *map_data, int fd)
{

}

void	parsing(t_cub3d *info, char *file)
{
	int	fd;

	(void)info;
	if (!is_valid_file_name(file))
		ft_err("parsing :: invalid file name.");
	fd = open(file, O_RDONLY);
	if (!fd)
		ft_err("parsing :: failed open file.");
}
