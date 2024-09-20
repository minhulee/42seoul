/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 07:37:49 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/20 19:33:40 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d_bonus.h"

void	move_w(int key, t_player *player, t_map_data *map_data)
{
	int	next_x;
	int	next_y;

	if (key == NONE || key != W)
		return ;
	next_x = (int)(player->pos_x + player->dir_x * player->mov_spd);
	next_y = (int)(player->pos_y + player->dir_y * player->mov_spd);
	if (is_moved_tile(next_x, (int)player->pos_y, map_data))
		player->pos_x += player->dir_x * player->mov_spd;
	if (is_moved_tile((int)player->pos_x, next_y, map_data))
		player->pos_y += player->dir_y * player->mov_spd;
}

void	move_s(int key, t_player *player, t_map_data *map_data)
{
	int	next_x;
	int	next_y;

	if (key == NONE || key != S)
		return ;
	next_x = (int)(player->pos_x - player->dir_x * player->mov_spd);
	next_y = (int)(player->pos_y - player->dir_y * player->mov_spd);
	if (is_moved_tile(next_x, (int)player->pos_y, map_data))
		player->pos_x -= player->dir_x * player->mov_spd;
	if (is_moved_tile((int)player->pos_x, next_y, map_data))
		player->pos_y -= player->dir_y * player->mov_spd;
}

void	move_a(int key, t_player *player, t_map_data *map_data)
{
	int	next_x;
	int	next_y;

	if (key == NONE || key != A)
		return ;
	next_x = (int)(player->pos_x + player->dir_y * player->mov_spd);
	next_y = (int)(player->pos_y - player->dir_x * player->mov_spd);
	if (is_moved_tile(next_x, (int)player->pos_y, map_data))
			player->pos_x += player->dir_y * player->mov_spd;
	if (is_moved_tile((int)player->pos_x, next_y, map_data))
		player->pos_y -= player->dir_x * player->mov_spd;
}

void	move_d(int key, t_player *player, t_map_data *map_data)
{
	int	next_x;
	int	next_y;

	if (key == NONE || key != D)
		return ;
	next_x = (int)(player->pos_x - player->dir_y * player->mov_spd);
	next_y = (int)(player->pos_y + player->dir_x * player->mov_spd);
	if (is_moved_tile(next_x, (int)player->pos_y, map_data))
			player->pos_x -= player->dir_y * player->mov_spd;
	if (is_moved_tile((int)player->pos_x, next_y, map_data))
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
	move_w(input->w_s, player, map_data);
	move_a(input->a_d, player, map_data);
	move_s(input->w_s, player, map_data);
	move_d(input->a_d, player, map_data);
}
