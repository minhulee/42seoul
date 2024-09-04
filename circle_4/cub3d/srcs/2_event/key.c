/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 07:25:12 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/04 15:52:52 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	update_player(t_cub3d *info, t_input *input)
{
	move_forward_backward(info, input->w_s, &info->player, info->map_data.map);
	move_left_right(info, input->a_d, &info->player, info->map_data.map);
	rotate_left_right(info, input->l_r, &info->player, &info->camera);
}

void	update_input(t_cub3d *info, t_input *input)
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
		if (input->move[4])
			input->l_r = LEFT;
		else if (input->move[5])
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
		info->input.move[4] = TRUE;
	else if (key == RIGHT)
		info->input.move[5] = TRUE;
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
		info->input.move[4] = FALSE;
	else if (key == RIGHT)
		info->input.move[5] = FALSE;
	if (key == info->input.w_s)
		info->input.w_s = NONE;
	if (key == info->input.a_d)
		info->input.a_d = NONE;
	if (key == info->input.l_r)
		info->input.l_r = NONE;
	return (0);
}