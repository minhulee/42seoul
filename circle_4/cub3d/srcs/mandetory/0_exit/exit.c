/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 11:01:20 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/20 19:37:38 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	ft_err(char *err)
{
	printf("Error\n");
	printf("cub3d :: %s\n", err);
	exit(1);
}

void	ft_err_map(char *err, int row, int col)
{
	printf("Error\n");
	if (col == -1)
		printf("cub3d :: %s (%d line).\n", err, row);
	else
		printf("cub3d :: %s (%d, %d).\n", err, row, col);
	exit(1);
}

int	exit_game(t_cub3d *info)
{
	mlx_clear_window(info->mlx, info->window);
	mlx_destroy_image(info->mlx, info->screen.img);
	exit(0);
	return (0);
}
