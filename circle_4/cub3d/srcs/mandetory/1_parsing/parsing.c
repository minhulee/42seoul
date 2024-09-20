/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 10:56:40 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/20 19:32:38 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	is_valid_rgb(int color)
{
	if (!(0 <= color && color <= 255))
		ft_err("parsing :: invalid colors (exceed rgb value)");
	return (color);
}

void	convert_to_color(int *color, char *data)
{
	char	**split;
	char	*dst;
	int		i;

	dst = ft_strcut(data, 0, ft_strlen(data) - 1);
	free(data);
	printf("color : [%s]\n", dst);
	split = ft_split(dst, ',');
	free(dst);
	if (!split)
		ft_err("parsing :: failed split (*malloc).");
	i = 0;
	while (split[i])
		i++;
	if (i != 3)
		ft_err("parsing :: invalid floor or ceil colors (too many value)");
	*color = (1 << 24);
	i = 0;
	while (split[i])
	{
		is_valid_rgb(ft_isatoi(split[i]));
		*color |= (ft_isatoi(split[i]) << (16 - i * 8));
		i++;
	}
	free_split(split);
}

void	convert_to_w_f_c(t_cub3d *info, t_map_data *map_data, int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		map_data->start++;
		if (!map_data->walls[NO] && !ft_strncmp(line, "NO ", 3))
			load_xpm(info, &(map_data->walls[NO]), remove_space(line + 2), 64);
		else if (!map_data->walls[SO] && !ft_strncmp(line, "SO ", 3))
			load_xpm(info, &(map_data->walls[SO]), remove_space(line + 2), 64);
		else if (!map_data->walls[WE] && !ft_strncmp(line, "WE ", 3))
			load_xpm(info, &(map_data->walls[WE]), remove_space(line + 2), 64);
		else if (!map_data->walls[EA] && !ft_strncmp(line, "EA ", 3))
			load_xpm(info, &(map_data->walls[EA]), remove_space(line + 2), 64);
		else if (!map_data->floor && !ft_strncmp(line, "F ", 2))
			convert_to_color(&(map_data->floor), remove_space(line + 1));
		else if (!map_data->ceil && !ft_strncmp(line, "C ", 2))
			convert_to_color(&(map_data->ceil), remove_space(line + 1));
		else if (line[0] != '\n')
			break ;
		free(line);
	}
	free(line);
	close(fd);
}

void	parsing(t_cub3d *info, char *file)
{
	(void)info;
	is_valid_file_name(file);
	convert_to_w_f_c(info, &info->map_data, quick_open_file(file, 0));
	if (!((info->map_data.walls[NO] && info->map_data.walls[SO]
				&& info->map_data.walls[WE] && info->map_data.walls[EA]
				&& info->map_data.floor != 0
				&& info->map_data.ceil != 0)))
		ft_err("parsing :: invalid cub file (few options or to many).");
	convert_to_map(info, &info->map_data, file);
}
