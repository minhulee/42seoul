/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 07:37:49 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/12 14:24:38 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	move_w(t_cub3d *info, int key,
	t_player *player, t_map_data *map_data)
{
	if (key == NONE || key != W)
		return ;
	if (is_moved_tile(&info->input, (int)(player->pos_x + player->dir_x * player->mov_spd),
		(int)player->pos_y, map_data))
		player->pos_x += player->dir_x * player->mov_spd;
	if (is_moved_tile(&info->input, (int)player->pos_x,
			(int)(player->pos_y + player->dir_y * player->mov_spd), map_data))
		player->pos_y += player->dir_y * player->mov_spd;
}

void	move_s(t_cub3d *info, int key,
	t_player *player, t_map_data *map_data)
{
	if (key == NONE || key != S)
		return ;
	if (is_moved_tile(&info->input, (int)(player->pos_x - player->dir_x * player->mov_spd),
		(int)player->pos_y, map_data))
		player->pos_x -= player->dir_x * player->mov_spd;
	if (is_moved_tile(&info->input, (int)player->pos_x,
			(int)(player->pos_y - player->dir_y * player->mov_spd), map_data))
		player->pos_y -= player->dir_y * player->mov_spd;
}

void	move_a(t_cub3d *info, int key,
	t_player *player, t_map_data *map_data)
{
	if (key == NONE || key != A)
		return ;
	if (is_moved_tile(&info->input, (int)(player->pos_x + player->dir_y * player->mov_spd),
		(int)player->pos_y, map_data))
			player->pos_x += player->dir_y * player->mov_spd;
	if (is_moved_tile(&info->input, (int)player->pos_x,
			(int)(player->pos_y - player->dir_x * player->mov_spd), map_data))
		player->pos_y -= player->dir_x * player->mov_spd;
}

void	move_d(t_cub3d *info, int key,
	t_player *player, t_map_data *map_data)
{
	if (key == NONE || key != D)
		return ;
	if (is_moved_tile(&info->input, (int)(player->pos_x - player->dir_y * player->mov_spd),
		(int)player->pos_y, map_data))
			player->pos_x -= player->dir_y * player->mov_spd;
	if (is_moved_tile(&info->input, (int)player->pos_x,
			(int)(player->pos_y + player->dir_x * player->mov_spd), map_data))
		player->pos_y += player->dir_x * player->mov_spd;
}

void	move(t_cub3d *info, t_input *input,
	t_player *player, t_map_data *map_data)
{

	if (input->w_s == NONE && input->a_d == NONE)
		return ;
	if (input->w_s != NONE && input->a_d == NONE)
		info->player.mov_spd = 0.08;
	else
		info->player.mov_spd = 0.05;
	if (input->run == TRUE)
		info->player.mov_spd *= 20;
	move_w(info, input->w_s, player, map_data);
	move_a(info, input->a_d, player, map_data);
	move_s(info, input->w_s, player, map_data);
	move_d(info, input->a_d, player, map_data);
}
