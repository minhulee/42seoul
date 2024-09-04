/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 07:53:02 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/04 16:02:58 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_buff_to_screen(t_cub3d *info, t_img *screen)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WINDOW_H)
	{
		j = -1;
		while (++j < WINDOW_W)
			((int *)screen->addr)[i * WINDOW_W + j] = info->buff[i][j];
	}
	ft_memset(info->buff, 0, sizeof(info->buff));
}

int	render(t_cub3d *info)
{
	update_input(info, &info->input);
	update_player(info, &info->input);
	int i = 0;
	while (i < WINDOW_H)
	{
		int j = 0;
		while (j < WINDOW_W)
		{
			int color;
			if (i < WINDOW_H / 2)
				color = 1 << 24 | (info->map_data.ceil[0] << 16) | (info->map_data.ceil[1] << 8) | (info->map_data.ceil[2]);
			else
				color = 1 << 24 | (info->map_data.floor[0] << 16) | (info->map_data.floor[1] << 8) | (info->map_data.floor[2]);
			info->buff[i][j] = color;
			j++;
		}
		i++;
	}
	raycasting(info, &info->ray, &info->player, &info->camera);
	put_buff_to_screen(info, &info->screen);
	mlx_put_image_to_window(info->mlx, info->window,
		info->screen.img, 0, 0);
	return (0);
}
