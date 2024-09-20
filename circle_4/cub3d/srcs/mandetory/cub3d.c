/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 10:50:05 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/20 19:34:05 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_struct_in_info(t_cub3d *info)
{
	ft_memset(&info->map_data, 0, sizeof(t_map_data));
	ft_memset(&info->input.move, 0, sizeof(t_bool) * 4);
	ft_memset(&info->input.rotate, 0, sizeof(t_bool) * 4);
	info->input.w_s = NONE;
	info->input.a_d = NONE;
	info->input.l_r = NONE;
	ft_memset(&info->ray, 0, sizeof(t_ray));
	ft_memset(&info->camera, 0, sizeof(t_camera));
	ft_memset(&info->player, 0, sizeof(t_player));
}

void	init_info(t_cub3d *info, t_img *screen)
{
	info->mlx = mlx_init();
	if (!info->mlx)
		ft_err("init :: mlx obj create failed..");
	info->window = mlx_new_window(info->mlx, WINDOW_W, WINDOW_H, "title");
	if (!info->window)
		ft_err("init :: window obj create failed..");
	screen->img = mlx_new_image(info->mlx, WINDOW_W, WINDOW_H);
	if (!screen->img)
		ft_err("init : img obj for screen create failed..");
	screen->addr = mlx_get_data_addr(screen->img,
			&screen->bpp, &screen->line_len, &screen->endian);
	init_struct_in_info(info);
}

int	main(int argc, char **argv)
{
	t_cub3d	info;

	atexit(check);
	if (argc != 2)
		ft_err("no argument or more than 2 arguments.");
	init_info(&info, &info.screen);
	parsing(&info, argv[1]);
	mlx_loop_hook(info.mlx, &render, &info);
	mlx_hook(info.window, X_EVENT_KEY_PRESS, 0, &press, &info);
	mlx_hook(info.window, X_EVENT_KEY_RELEASE, 0, &release, &info);
	mlx_hook(info.window, 17, 0, &exit_game, &info);
	mlx_loop(info.mlx);
}
