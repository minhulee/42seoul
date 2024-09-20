/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 07:53:02 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/20 19:33:52 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d_bonus.h"

void	put_xpm_to_img(int *src, int *dst, int size)
{
	int			x;
	int			y;
	double		tex_x;
	double		tex_y;
	int			color;

	y = -1;
	tex_y = 0;
	while (++y < size)
	{
		x = -1;
		tex_x = 0;
		while (++x < size)
		{
			color = src[(int)tex_y * TEXTURE_H + (int)tex_x];
			if ((color >> 24) == 0)
				dst[y * WINDOW_W + x] = color;
			tex_x += (double)TEXTURE_H / size;
		}
		tex_y += (double)TEXTURE_H / size;
	}
}

t_bool	detect_door(t_cub3d *info, t_player *player,
	t_map_data *map_data, t_tile **map)
{
	int	x;
	int	y;
	int	next_x;
	int	next_y;

	x = player->pos_x;
	y = player->pos_y;
	next_x = player->pos_x + player->dir_x * player->mov_spd * 5;
	next_y = player->pos_y + player->dir_y * player->mov_spd * 5;
	if ((next_x < 0 || next_x >= map_data->width)
		|| (next_y < 0 || next_y >= map_data->height))
		return (FALSE);
	if (map[y][x].type != DOOR && map[next_y][next_x].type == DOOR)
	{
		if (((next_y - 1 <= y && y <= next_y + 1) && next_x == x)
			|| ((next_x - 1 <= x && x <= next_x + 1) && next_y == y))
		{
			info->input.open_dst = &map[next_y][next_x];
			return (TRUE);
		}
	}
	else
		info->input.open_dst = NULL;
	return (FALSE);
}

void	update_pist(t_cub3d *info)
{
	if (info->player.left_pist.time != NONE)
	{
		info->player.left_pist.time++;
		if (info->player.left_pist.time > 2)
		{
			info->player.left_pist.time = 0;
			if (!info->player.left_pist.flag)
				info->player.left_pist.frame++;
			else
				info->player.left_pist.frame--;
			if (info->player.left_pist.frame == 3)
			{
				info->player.left_pist.frame = 2;
				info->player.left_pist.flag = TRUE;
			}
			else if (info->player.left_pist.frame == 0)
			{
				info->player.left_pist.flag = FALSE;
				info->player.left_pist.time = NONE;
			}
		}
	}
}

void	update_player(t_cub3d *info, t_input *input)
{
	move(info, input, &info->player, &info->map_data);
}

int	render(t_cub3d *info)
{
	int	*screen;

	screen = (int *)info->screen.addr;
	update_input(&info->input);
	update_camera(info);
	update_player(info, &info->input);
	update_pist(info);
	raycasting(info, &info->ray, &info->player, &info->camera);
	make_minimap(info);
	put_xpm_to_img(info->player.left_pist.texture[info->player.left_pist.frame],
		screen + PIST_H + LPIST_W, WINDOW_H / 2);
	put_xpm_to_img((int *)info->player.right_pist,
		screen + PIST_H + RPIST_W, WINDOW_H / 2);
	if (detect_door(info, &info->player, &info->map_data, info->map_data.map))
		put_xpm_to_img(info->player.button, screen + CENTER, WINDOW_H / 20);
	mlx_put_image_to_window(info->mlx, info->window,
		info->screen.img, 0, 0);
	return (0);
}
