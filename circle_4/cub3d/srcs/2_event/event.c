/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 07:37:49 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/04 16:09:19 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_bool	is_available_tile(int x, int y, t_tile_type **map)
{
	if (map[y][x] == GROUND || map[y][x] == ST_N ||
		map[y][x] == ST_S || map[y][x] == ST_W || map[y][x] == ST_E)
		return (TRUE);
	return (FALSE);
}

void	move_forward_backward(t_cub3d *info, int key, t_player *player, t_tile_type **map)
{
	if (key == NONE)
		return ;
	if (key == W)
	{
		if (is_available_tile((int)(player->pos_x + player->dir_x * MOVE_SPD), (int)player->pos_y, map))
			player->pos_x += player->dir_x * MOVE_SPD;
		if (is_available_tile((int)player->pos_x, (int)(player->pos_y + player->dir_y * MOVE_SPD), map))
			player->pos_y += player->dir_y * MOVE_SPD;
	}
	if (key == S)
	{
		if (is_available_tile((int)(player->pos_x - player->dir_x * MOVE_SPD), (int)player->pos_y, map))
			player->pos_x -= player->dir_x * MOVE_SPD;
		if (is_available_tile((int)player->pos_x, (int)(player->pos_y - player->dir_y * MOVE_SPD), map))
			player->pos_y -= player->dir_y * MOVE_SPD;
	}
}

void	move_left_right(t_cub3d *info, int key, t_player *player, t_tile_type **map)
{
	if (key == NONE)
		return ;
	if (key == A)
	{
		if (is_available_tile((int)(player->pos_x + player->dir_y * MOVE_SPD), (int)player->pos_y, map))
			player->pos_x += player->dir_y * MOVE_SPD;
		if (is_available_tile((int)player->pos_x, (int)(player->pos_y - player->dir_x * MOVE_SPD), map))
			player->pos_y -= player->dir_x * MOVE_SPD;
	}
	if (key == D)
	{
		if (is_available_tile((int)(player->pos_x - player->dir_y * MOVE_SPD), (int)player->pos_y, map))
			player->pos_x -= player->dir_y * MOVE_SPD;
		if (is_available_tile((int)player->pos_x, (int)(player->pos_y + player->dir_x * MOVE_SPD), map))
			player->pos_y += player->dir_x * MOVE_SPD;
	}
}

void	rotate_left_right(t_cub3d *info, int key, t_player *player, t_camera *camera)
{
	double	old_dir_x;
	double	old_plane_x;

	if (key == NONE)
		return ;
	old_dir_x = player->dir_x;
	old_plane_x = camera->plane_x;
	if (key == LEFT)
	{
		player->dir_x = player->dir_x * cos(-ROT_SPD) - player->dir_y * sin(-ROT_SPD);
		player->dir_y = old_dir_x * sin(-ROT_SPD) + player->dir_y * cos(-ROT_SPD);
		camera->plane_x = camera->plane_x * cos(-ROT_SPD) - camera->plane_y * sin(-ROT_SPD);
		camera->plane_y = old_plane_x * sin(-ROT_SPD) + camera->plane_y * cos(-ROT_SPD);
	}
	if (key == RIGHT)
	{
		player->dir_x = player->dir_x * cos(ROT_SPD) - player->dir_y * sin(ROT_SPD);
		player->dir_y = old_dir_x * sin(ROT_SPD) + player->dir_y * cos(ROT_SPD);
		camera->plane_x = camera->plane_x * cos(ROT_SPD) - camera->plane_y * sin(ROT_SPD);
		camera->plane_y = old_plane_x * sin(ROT_SPD) + camera->plane_y * cos(ROT_SPD);
	}
}
