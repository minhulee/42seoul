/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 07:25:12 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/20 19:32:49 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	update_player(t_cub3d *info, t_input *input)
{
	move(input, &info->player, info->map_data.map);
	rotate(input->l_r, &info->player, &info->camera);
}

t_bool	is_moved_tile(int x, int y, t_tile_type **map)
{
	if (map[y][x] == GROUND || map[y][x] == ST_N ||
		map[y][x] == ST_S || map[y][x] == ST_W || map[y][x] == ST_E)
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
	{
		mlx_clear_window(info->mlx, info->window);
		mlx_destroy_window(info->mlx, info->window);
		exit(0);
	}
	if (key == W)
		info->input.move[0] = TRUE;
	else if (key == A)
		info->input.move[1] = TRUE;
	else if (key == S)
		info->input.move[2] = TRUE;
	else if (key == D)
		info->input.move[3] = TRUE;
	else if (key == LEFT)
		info->input.rotate[0] = TRUE;
	else if (key == RIGHT)
		info->input.rotate[1] = TRUE;
	if (key == W || key == S)
		info->input.w_s = key;
	if (key == A || key == D)
		info->input.a_d = key;
	if ((key == LEFT || key == RIGHT))
		info->input.l_r = key;
	return (0);
}

int	release(int key, t_cub3d *info)
{
	if (key == W)
		info->input.move[0] = FALSE;
	else if (key == A)
		info->input.move[1] = FALSE;
	else if (key == S)
		info->input.move[2] = FALSE;
	else if (key == D)
		info->input.move[3] = FALSE;
	else if (key == LEFT)
		info->input.rotate[0] = FALSE;
	else if (key == RIGHT)
		info->input.rotate[1] = FALSE;
	if (key == info->input.w_s)
		info->input.w_s = NONE;
	if (key == info->input.a_d)
		info->input.a_d = NONE;
	if (key == info->input.l_r)
		info->input.l_r = NONE;
	return (0);
}
