/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 07:53:02 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/20 16:31:18 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	render(t_cub3d *info)
{
	mlx_clear_window(info->mlx, info->window);
	update_input(&info->input);
	update_player(info, &info->input);
	raycasting(info, &info->ray, &info->player, &info->camera);
	mlx_put_image_to_window(info->mlx, info->window,
		info->screen.img, 0, 0);
	return (0);
}
