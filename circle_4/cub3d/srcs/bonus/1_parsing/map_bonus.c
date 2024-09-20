/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:45:54 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/20 19:33:21 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d_bonus.h"

void	is_map_size(t_map_data *map_data, int fd)
{
	char	*line;
	t_bool	end;
	int		i;

	end = FALSE;
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		i++;
		if (end && line[0] != '\n')
			ft_err_map("parsing :: there is data after end of map",
				map_data->start + i, NONE);
		else if (line[0] == '\n')
			end = TRUE;
		else
		{
			map_data->height++;
			if (map_data->width < (int)ft_strlen(line) - 1)
				map_data->width = (int)ft_strlen(line) - 1;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	make_map_array(t_map_data *map_data)
{
	int	i;
	int	j;

	map_data->map = (t_tile **)ft_calloc(sizeof(t_tile *),
			map_data->height + 2);
	if (!map_data->map)
		ft_err("parsing :: faild *ft_calloc - convert_to_map().");
	i = 0;
	while (i < map_data->height + 2)
	{
		map_data->map[i] = (t_tile *)ft_calloc(sizeof(t_tile),
				map_data->width + 2);
		if (!map_data->map[i])
			ft_err("parsing :: faild *ft_calloc - convert_to_map().");
		j = 0;
		while (j < map_data->width + 2)
		{
			map_data->map[i][j].type = EMPTY;
			map_data->map[i][j].status = FALSE;
			j++;
		}
		i++;
	}
}

void	fill_map_line(t_cub3d *info, t_tile **map, char *line, int row)
{
	int	cursor;
	int	i;

	cursor = 0;
	i = 1;
	while (line[cursor] != '\n')
	{
		if (line[cursor] == '0')
			map[row][i].type = GROUND;
		else if (line[cursor] == '1')
			map[row][i].type = WALL;
		else if (line[cursor] == 'D')
			map[row][i].type = DOOR;
		else if (line[cursor] == 'N' || line[cursor] == 'S'
			|| line[cursor] == 'W' || line[cursor] == 'E')
			set_start(info, row, i, line[cursor]);
		else if (line[cursor] != ' ')
			ft_err_map("parsing :: invalid map data", row, i);
		cursor++;
		i++;
	}
}

void	fill_map_array(t_cub3d *info, t_map_data *map_data, int fd)
{
	char	*line;
	int		cursor;
	int		i;

	cursor = 0;
	i = 1;
	while (cursor < map_data->height)
	{
		line = get_next_line(fd);
		fill_map_line(info, map_data->map, line, i);
		cursor++;
		i++;
		free(line);
	}
	close(fd);
}

void	convert_to_map(t_cub3d *info, t_map_data *map_data, char *file)
{
	(void)info;
	ft_printf("map data start line : %d\n", map_data->start);
	is_map_size(map_data, quick_open_file(file, map_data->start));
	make_map_array(map_data);
	fill_map_array(info, map_data, quick_open_file(file, map_data->start));
	is_valid_map(map_data, map_data->map);
}
