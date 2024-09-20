/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:56:54 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/20 19:44:45 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static void	setup_camera(t_tile_type type, t_camera *camera)
{
	if (type == ST_N)
	{
		camera->plane_x = 0.66;
		camera->plane_y = 0;
	}
	else if (type == ST_S)
	{
		camera->plane_x = -0.66;
		camera->plane_y = 0;
	}
	else if (type == ST_E)
	{
		camera->plane_x = 0;
		camera->plane_y = 0.66;
	}
	else if (type == ST_W)
	{
		camera->plane_x = 0;
		camera->plane_y = -0.66;
	}
}

static void	setup_player(t_tile_type type, t_player *player)
{
	if (type == ST_N)
	{
		player->dir_x = 0;
		player->dir_y = -1;
	}
	else if (type == ST_S)
	{
		player->dir_x = 0;
		player->dir_y = 1;
	}
	else if (type == ST_E)
	{
		player->dir_x = 1;
		player->dir_y = 0;
	}
	else if (type == ST_W)
	{
		player->dir_x = -1;
		player->dir_y = 0;
	}
}

void	set_start(t_cub3d *info, int h, int w, t_tile_type type)
{
	info->map_data.map[h][w] = type;
	info->player.pos_x = w;
	info->player.pos_y = h;
	setup_camera(type, &info->camera);
	setup_player(type, &info->player);
}

int	quick_open_file(char *file, int line)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_err("parsing :: failed open file. (invalid path)");
	while (1 < line)
	{
		free(get_next_line(fd));
		line--;
	}
	return (fd);
}

char	*remove_space(char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		if (src[i] != ' ')
			break ;
		i++;
	}
	return (ft_strcut(src, i, ft_strlen(src)));
}
