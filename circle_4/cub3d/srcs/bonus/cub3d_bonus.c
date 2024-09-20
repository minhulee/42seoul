/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 10:50:05 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/20 19:37:04 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	init_map_input_ray_camera(t_cub3d *info)
{
	ft_memset(&info->map_data, 0, sizeof(t_map_data));
	ft_memset(&info->input.move, 0, sizeof(t_bool) * 4);
	ft_memset(&info->input.rotate, 0, sizeof(t_bool) * 4);
	info->input.w_s = NONE;
	info->input.a_d = NONE;
	info->input.l_r = NONE;
	info->input.run = NONE;
	info->input.open_dst = NULL;
	ft_memset(&info->ray, 0, sizeof(t_ray));
	ft_memset(&info->camera, 0, sizeof(t_camera));
	info->camera.tov = WINDOW_H / 10;
	info->camera.key = NONE;
}

void	init_info_player(t_cub3d *info, t_img *screen, t_player *player)
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
	ft_memset(&info->player, 0, sizeof(t_player));
	load_action(info, &player->button,
		"./textures/actions/open/open.xpm", 64);
	load_action(info, &player->right_pist,
		"./textures/actions/pist/right.xpm", 64);
	load_action(info, &player->left_pist.texture[0],
		"./textures/actions/pist/left.xpm", 64);
	load_action(info, &player->left_pist.texture[1],
		"./textures/actions/pist/left2.xpm", 64);
	load_action(info, &player->left_pist.texture[2],
		"./textures/actions/pist/left3.xpm", 64);
	player->left_pist.time = NONE;
	info->player.pos_x = NONE;
}

int	main(int argc, char **argv)
{
	t_cub3d	info;

	atexit(check);
	if (argc != 2)
		ft_err("no argument or more than 2 arguments.");
	init_info_player(&info, &info.screen, &info.player);
	init_map_input_ray_camera(&info);
	parsing(&info, argv[1]);
	mlx_loop_hook(info.mlx, &render, &info);
	mlx_hook(info.window, X_EVENT_KEY_PRESS, 0, &press, &info);
	mlx_hook(info.window, X_EVENT_KEY_RELEASE, 0, &release, &info);
	mlx_mouse_hook(info.window, &click, &info);
	mlx_mouse_move(info.window, WINDOW_W / 2, WINDOW_H / 2);
	mlx_mouse_hide();
	mlx_loop(info.mlx);
}
