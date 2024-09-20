/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:15:43 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/20 19:33:46 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d_bonus.h"

t_tile_type	search_tile(t_map_data *map_data, t_player *player, int i, int j)
{
	t_tile	dst;
	int		x;
	int		y;

	if (j / MINIMAP_L < 6)
		x = (int)player->pos_x - (5 - j / MINIMAP_L);
	else
		x = (int)player->pos_x + (j / MINIMAP_L - 5);
	if (i / MINIMAP_L < 5)
		y = (int)player->pos_y - (4 - i / MINIMAP_L);
	else
		y = (int)player->pos_y + (i / MINIMAP_L - 4);
	if ((x < 0 || x > map_data->width)
		|| (y < 0 || y > map_data->height))
		return (EMPTY);
	dst = map_data->map[y][x];
	if (dst.type == WALL)
		return (WALL);
	if (dst.type == DOOR)
		return (DOOR);
	if (dst.type == EMPTY)
		return (EMPTY);
	return (GROUND);
}

void	make_tile(t_cub3d *info, int y, int x)
{
	int	*screen;

	screen = (int *)info->screen.addr;
	if ((MINIMAP_L * 4 < y && y < MINIMAP_L * 5)
		&& (MINIMAP_L * 5 < x && x < MINIMAP_L * 6))
			screen[y * WINDOW_W + x] = M_PL;
	else if (search_tile(&info->map_data, &info->player, y, x) == GROUND)
		screen[y * WINDOW_W + x] = M_GR;
	else if (search_tile(&info->map_data, &info->player, y, x) == WALL)
		screen[y * WINDOW_W + x] = M_WA;
	else if (search_tile(&info->map_data, &info->player, y, x) == DOOR)
		screen[y * WINDOW_W + x] = M_DR;
	else if (search_tile(&info->map_data, &info->player, y, x) == EMPTY)
		screen[y * WINDOW_W + x] = M_EM;
}

void	make_line(t_cub3d *info, int y, int x)
{
	if (x % MINIMAP_L == 0 || y % MINIMAP_L == 0
		|| x == MINIMAP_W - 1 || y == MINIMAP_H - 1)
		((int *)info->screen.addr)[y * WINDOW_W + x] = M_L;
}

void	make_minimap(t_cub3d *info)
{
	int	y;
	int	x;

	y = 0;
	while (y < MINIMAP_H)
	{
		x = 0;
		while (x < MINIMAP_W)
		{
			make_tile(info, y, x);
			make_line(info, y, x);
			x++;
		}
		y++;
	}
}
