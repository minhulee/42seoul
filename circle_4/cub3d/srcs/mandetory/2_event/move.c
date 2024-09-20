/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 07:37:49 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/20 19:32:52 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	move_w(int key, t_player *player, t_tile_type **map)
{
	if (key == NONE || key != W)
		return ;
	if (is_moved_tile((int)(player->pos_x + player->dir_x * MOVE_SPD),
		(int)player->pos_y, map))
			player->pos_x += player->dir_x * MOVE_SPD;
	if (is_moved_tile((int)player->pos_x,
			(int)(player->pos_y + player->dir_y * MOVE_SPD), map))
		player->pos_y += player->dir_y * MOVE_SPD;
}

void	move_s(int key, t_player *player, t_tile_type **map)
{
	if (key == NONE || key != S)
		return ;
	if (is_moved_tile((int)(player->pos_x - player->dir_x * MOVE_SPD),
		(int)player->pos_y, map))
		player->pos_x -= player->dir_x * MOVE_SPD;
	if (is_moved_tile((int)player->pos_x,
			(int)(player->pos_y - player->dir_y * MOVE_SPD), map))
		player->pos_y -= player->dir_y * MOVE_SPD;
}

void	move_a(int key, t_player *player, t_tile_type **map)
{
	if (key == NONE || key != A)
		return ;
	if (is_moved_tile((int)(player->pos_x + player->dir_y * MOVE_SPD),
		(int)player->pos_y, map))
			player->pos_x += player->dir_y * MOVE_SPD;
	if (is_moved_tile((int)player->pos_x,
			(int)(player->pos_y - player->dir_x * MOVE_SPD), map))
		player->pos_y -= player->dir_x * MOVE_SPD;
}

void	move_d(int key, t_player *player, t_tile_type **map)
{
	if (key == NONE || key != D)
		return ;
	if (is_moved_tile((int)(player->pos_x - player->dir_y * MOVE_SPD),
		(int)player->pos_y, map))
			player->pos_x -= player->dir_y * MOVE_SPD;
	if (is_moved_tile((int)player->pos_x,
			(int)(player->pos_y + player->dir_x * MOVE_SPD), map))
		player->pos_y += player->dir_x * MOVE_SPD;
}

void	move(t_input *input, t_player *player, t_tile_type **map)
{
	if (input->w_s == NONE && input->a_d == NONE)
		return ;
	move_w(input->w_s, player, map);
	move_a(input->a_d, player, map);
	move_s(input->w_s, player, map);
	move_d(input->a_d, player, map);
}
