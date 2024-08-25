/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:46:44 by minhulee          #+#    #+#             */
/*   Updated: 2024/08/25 18:18:49 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	*load_xpm(t_cub3d *info, char *path, int size)
{
	void	*xpm;

	xpm = mlx_xpm_file_to_image(info->mlx, path, &size, &size);
	if (!xpm)
		ft_err("parsing :: failed load to xpm file. (invalid path)");
	return (xpm);
}