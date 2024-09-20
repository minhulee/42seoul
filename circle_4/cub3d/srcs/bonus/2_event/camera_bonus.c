/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:03:42 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/20 19:33:31 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d_bonus.h"

void	rotate_left(int key, t_player *player, t_camera *camera)
{
	double	old_dir_x;
	double	old_plane_x;

	if (key == NONE || key != LEFT)
		return ;
	old_dir_x = player->dir_x;
	old_plane_x = camera->plane_x;
	player->dir_x = player->dir_x * cos(-camera->x_spd)
		- player->dir_y * sin(-camera->x_spd);
	player->dir_y = old_dir_x * sin(-camera->x_spd)
		+ player->dir_y * cos(-camera->x_spd);
	camera->plane_x = camera->plane_x * cos(-camera->x_spd)
		- camera->plane_y * sin(-camera->x_spd);
	camera->plane_y = old_plane_x * sin(-camera->x_spd)
		+ camera->plane_y * cos(-camera->x_spd);
}

void	rotate_right(int key, t_player *player, t_camera *camera)
{
	double	old_dir_x;
	double	old_plane_x;

	if (key == NONE || key != RIGHT)
		return ;
	old_dir_x = player->dir_x;
	old_plane_x = camera->plane_x;
	if (key == RIGHT)
	{
		player->dir_x = player->dir_x * cos(camera->x_spd)
			- player->dir_y * sin(camera->x_spd);
		player->dir_y = old_dir_x * sin(camera->x_spd)
			+ player->dir_y * cos(camera->x_spd);
		camera->plane_x = camera->plane_x * cos(camera->x_spd)
			- camera->plane_y * sin(camera->x_spd);
		camera->plane_y = old_plane_x * sin(camera->x_spd)
			+ camera->plane_y * cos(camera->x_spd);
	}
}

void	rotate(int key, t_player *player, t_camera *camera)
{
	if (key == NONE)
		return ;
	rotate_left(key, player, camera);
	rotate_right(key, player, camera);
}

void	vertical_rotate(t_camera *camera, int dist_y)
{
	camera->tov -= dist_y / 1.5;
	if (camera->tov >= WINDOW_H)
		camera->tov = WINDOW_H;
	if (camera->tov <= -WINDOW_H)
		camera->tov = -WINDOW_H;
}

void	update_camera(t_cub3d *info)
{
	int	x;
	int	y;
	int	dist_x;
	int	dist_y;

	mlx_mouse_get_pos(info->window, &x, &y);
	dist_x = (double)(x - WINDOW_W / 2);
	dist_y = (double)(y - WINDOW_H / 2);
	info->camera.x_spd = fabs(dist_x * ROT_SPD);
	mlx_mouse_move(info->window, WINDOW_W / 2, WINDOW_H / 2);
	if (dist_x > 0)
		rotate(RIGHT, &info->player, &info->camera);
	else if (dist_x < 0)
		rotate(LEFT, &info->player, &info->camera);
	if (dist_y < -10 || 10 < dist_y)
		vertical_rotate(&info->camera, dist_y);
}
