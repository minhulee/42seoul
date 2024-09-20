/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:32:05 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/20 19:33:37 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d_bonus.h"

int	click(int key, int x, int y, t_cub3d *info)
{
	(void)x;
	(void)y;
	if (key == 1)
	{
		if (info->player.left_pist.time == NONE)
			info->player.left_pist.time = 0;
	}
	return (0);
}
