/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:13:48 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/11 17:57:01 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	test_map_array(t_map_data *map_data, t_tile **map)
{
	(void)map_data;
	int	i = 0;
	
	while (i < map_data->height + 2)
	{
		ft_printf("%d", i);
		for (int a = i / 10; a < map_data->width / 10; a++)
			ft_printf(" ");
		if (i >= map_data->height - map_data->height % 10)
			ft_printf(" ");
		ft_printf("[");
		int	j = 0;
		while (j < map_data->width + 2)
		{
			if (map[i][j].type == EMPTY)
				ft_printf("  ");
			else if (map[i][j].type == GROUND)
				ft_printf("0 ");
			else if (map[i][j].type == WALL)
				ft_printf("1 ");
			else if (map[i][j].type == DOOR)
				ft_printf("D ");
			else if (map[i][j].type == ST_N)
				ft_printf("N ");
			else if (map[i][j].type == ST_S)
				ft_printf("S ");
			else if (map[i][j].type == ST_W)
				ft_printf("W ");
			else if (map[i][j].type == ST_E)
				ft_printf("E ");
			j++;
		}
		ft_printf("]\n");
		i++;
	}
}