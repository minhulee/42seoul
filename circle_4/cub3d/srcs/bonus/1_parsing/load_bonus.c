/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:46:44 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/20 19:33:18 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d_bonus.h"

void	xpm_to_int_array(int **wall, t_img img, int size)
{
	int	i;
	int	j;

	*wall = (int *)ft_calloc(sizeof(int), (size * size));
	if (!*wall)
		ft_err("parsing :: failed create wall array (*malloc).");
	ft_printf("[%p]\n", *wall);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			(*wall)[i * size + j] = ((int *)img.addr)[i * size + j];
			j++;
		}
		i++;
	}
}

void	load_action(t_cub3d *info, int **dst, char *path, int size)
{
	t_img	img;

	ft_printf("load xpm path : [%s] ", path);
	img.img = mlx_xpm_file_to_image(info->mlx, path, &size, &size);
	if (!img.img)
		ft_err("init :: failed load to xpm file. (pist action)");
	img.addr = mlx_get_data_addr(img.img, &img.bpp,
			&img.line_len, &img.endian);
	xpm_to_int_array(dst, img, size);
	mlx_destroy_image(info->mlx, img.img);
}

void	load_xpm(t_cub3d *info, int **dst, char *path, int size)
{
	t_img	img;

	path = ft_strcut(path, 0, ft_strlen(path) - 1);
	ft_printf("load xpm path : [%s] ", path);
	img.img = mlx_xpm_file_to_image(info->mlx, path, &size, &size);
	if (!img.img)
		ft_err("parsing :: failed load to xpm file. (invalid path)");
	free(path);
	img.addr = mlx_get_data_addr(img.img, &img.bpp,
			&img.line_len, &img.endian);
	xpm_to_int_array(dst, img, size);
	mlx_destroy_image(info->mlx, img.img);
}
