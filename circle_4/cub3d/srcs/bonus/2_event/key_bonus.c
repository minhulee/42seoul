/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 07:25:12 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/20 19:37:45 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d_bonus.h"

t_bool	is_moved_tile(int x, int y, t_map_data *map_data)
{
	t_tile	dst;

	dst = map_data->map[y][x];
	if (dst.type == DOOR && dst.status == TRUE)
		return (TRUE);
	if (dst.type == GROUND || dst.type == ST_N
		|| dst.type == ST_S || dst.type == ST_W || dst.type == ST_E)
		return (TRUE);
	return (FALSE);
}

void	update_input(t_input *input)
{
	if (input->w_s == NONE)
	{
		if (input->move[0])
			input->w_s = W;
		else if (input->move[2])
			input->w_s = S;
	}
	if (input->a_d == NONE)
	{
		if (input->move[1])
			input->a_d = A;
		else if (input->move[3])
			input->a_d = D;
	}
	if (input->l_r == NONE)
	{
		if (input->rotate[0])
			input->l_r = LEFT;
		else if (input->rotate[1])
			input->l_r = RIGHT;
	}
}

int	press(int key, t_cub3d *info)
{
	if (key == ESC)
		exit_game(info);
	if (info->input.open_dst && key == F)
		info->input.open_dst->status = !info->input.open_dst->status;
	if (key == W)
		info->input.move[0] = TRUE;
	if (key == A)
		info->input.move[1] = TRUE;
	if (key == S)
		info->input.move[2] = TRUE;
	if (key == D)
		info->input.move[3] = TRUE;
	if (key == SHIFT)
		info->input.run = TRUE;
	if (key == W || key == S)
		info->input.w_s = key;
	if (key == A || key == D)
		info->input.a_d = key;
	return (0);
}

int	release(int key, t_cub3d *info)
{
	if (key == W)
		info->input.move[0] = FALSE;
	if (key == A)
		info->input.move[1] = FALSE;
	if (key == S)
		info->input.move[2] = FALSE;
	if (key == D)
		info->input.move[3] = FALSE;
	if (key == SHIFT)
		info->input.run = FALSE;
	if (key == info->input.w_s)
		info->input.w_s = NONE;
	if (key == info->input.a_d)
		info->input.a_d = NONE;
	return (0);
}
