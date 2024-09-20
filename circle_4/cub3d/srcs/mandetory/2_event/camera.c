/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:03:42 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/20 19:32:47 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	rotate_left(int key, t_player *player, t_camera *camera)
{
	double	old_dir_x;
	double	old_plane_x;

	if (key == NONE || key != LEFT)
		return ;
	old_dir_x = player->dir_x;
	old_plane_x = camera->plane_x;
	player->dir_x = player->dir_x * cos(-ROT_SPD)
		- player->dir_y * sin(-ROT_SPD);
	player->dir_y = old_dir_x * sin(-ROT_SPD)
		+ player->dir_y * cos(-ROT_SPD);
	camera->plane_x = camera->plane_x * cos(-ROT_SPD)
		- camera->plane_y * sin(-ROT_SPD);
	camera->plane_y = old_plane_x * sin(-ROT_SPD)
		+ camera->plane_y * cos(-ROT_SPD);
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
		player->dir_x = player->dir_x * cos(ROT_SPD)
			- player->dir_y * sin(ROT_SPD);
		player->dir_y = old_dir_x * sin(ROT_SPD)
			+ player->dir_y * cos(ROT_SPD);
		camera->plane_x = camera->plane_x * cos(ROT_SPD)
			- camera->plane_y * sin(ROT_SPD);
		camera->plane_y = old_plane_x * sin(ROT_SPD)
			+ camera->plane_y * cos(ROT_SPD);
	}
}

void	rotate(int key, t_player *player, t_camera *camera)
{
	if (key == NONE)
		return ;
	rotate_left(key, player, camera);
	rotate_right(key, player, camera);
}
