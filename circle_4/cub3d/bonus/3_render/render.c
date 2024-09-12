/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 07:53:02 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/12 17:07:34 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	put_xpm_to_img(int *src, int*dst, int rate)
{
	int			size;
	double		step;
	int			x;
	int			y;
	double		tex_x;
	double		tex_y;
	int			color;

	size = WINDOW_H / rate;
	step = (double)TEXTURE_H / size;
	y = 0;
	tex_y = 0;
	while (y < size)
	{
		x = 0;
		tex_x = 0;
		while (x < size)
		{
			color = src[(int)tex_y * TEXTURE_H + (int)tex_x];
			if ((color >> 24) == 0)
				dst[y * WINDOW_W + x] = color;
			tex_x += step;
			x++;
		}
		tex_y += step;
		y++;
	}
}

t_bool	detect_door(t_cub3d *info, t_player *player, t_map_data *map_data, t_tile **map)
{
	int	cur_x;
	int	cur_y;
	int	next_x;
	int	next_y;

	cur_x = player->pos_x;
	cur_y = player->pos_y;
	next_x = player->pos_x + player->dir_x * player->mov_spd * 5;
	next_y = player->pos_y + player->dir_y * player->mov_spd * 5;
	if ((next_x < 0 || next_x >= map_data->width)
		|| (next_y < 0 || next_y >= map_data->height))
		return (FALSE);
	if (map[cur_y][cur_x].type != DOOR && map[next_y][next_x].type == DOOR)
	{
		if (((next_y - 1 <= cur_y && cur_y <= next_y + 1) && next_x == cur_x)
			|| ((next_x - 1 <= cur_x && cur_x <= next_x + 1) && next_y == cur_y))
		{
			info->input.open_dst = &map[next_y][next_x];
			return (TRUE);
		}
	}
	else
		info->input.open_dst = NULL;
	return (FALSE);
}

int	render(t_cub3d *info)
{
	if (info->player.left_pist.time != NONE)
	{
		info->player.left_pist.time++;
		if (info->player.left_pist.time > 1)
		{
			info->player.left_pist.time = 0;
			
			if (!info->player.left_pist.flag)
				info->player.left_pist.frame++;
			else
				info->player.left_pist.frame--;
			
			if (info->player.left_pist.frame == 3)
			{
				info->player.left_pist.frame = 2;
				info->player.left_pist.flag = !info->player.left_pist.flag;
			}
			else if (info->player.left_pist.frame == 0)
			{
				info->player.left_pist.time = NONE;
				info->player.left_pist.flag = !info->player.left_pist.flag;
			}
		}
	}
	update_input(info, &info->input);
	update_camera(info);
	update_player(info, &info->input);
	ft_memset(info->screen.addr, 0, (sizeof(int) * (WINDOW_H * WINDOW_W)));
	raycasting(info, &info->ray, &info->player, &info->camera);
	make_minimap(info);
	put_xpm_to_img((int *)info->player.left_pist.texture[info->player.left_pist.frame].addr, ((int *)info->screen.addr)
		+ (WINDOW_H / 2 * WINDOW_W) + WINDOW_W / 6, 2);
	put_xpm_to_img((int *)info->player.right_pist.addr, ((int *)info->screen.addr)
		+ (WINDOW_H / 2 * WINDOW_W) + (WINDOW_W / 4 + WINDOW_H / 2), 2);
	if (detect_door(info, &info->player, &info->map_data, info->map_data.map))
		put_xpm_to_img((int *)info->button.addr, ((int *)info->screen.addr)
			+ (WINDOW_H / 2 * WINDOW_W) + WINDOW_W / 2, 20);
	mlx_put_image_to_window(info->mlx, info->window,
		info->screen.img, 0, 0);
	return (0);
}
