/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:45:54 by minhulee          #+#    #+#             */
/*   Updated: 2024/08/26 17:19:58 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	is_map_size(t_map_data *map_data, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_err("parsing :: failed open file. (invalid path) : is_map_size() ");
	while (0 < map_data->start)
	{
		line = get_next_line(fd);
		map_data->start--;
	}
	while (line)
	{
		map_data->height++;
		if (map_data->width < (int)ft_strlen(line))
			map_data->width = (int)ft_strlen(line);
		line = get_next_line(fd);
	}
	ft_printf("%d | %d\n", map_data->height, map_data->width);
}

void	make_map_array(t_map_data *map_data)
{
	int	i;

	map_data->map = (t_tile_type **)ft_calloc(sizeof(t_tile_type *), map_data->height);
	if (!map_data->map)
		ft_err("parsing :: faild *ft_calloc - convert_to_map().");
	i = 0;
	while (i < map_data->height)
	{
		map_data->map[i] = (t_tile_type *)ft_calloc(sizeof(t_tile_type), map_data->width);
		if (!map_data->map[i])
			ft_err("parsing :: faild *ft_calloc - convert_to_map().");
		i++;
	}
}

void	convert_to_map(t_cub3d *info, t_map_data *map_data, char *file)
{
	(void)info;
	is_map_size(map_data, file);
	make_map_array(map_data);
}