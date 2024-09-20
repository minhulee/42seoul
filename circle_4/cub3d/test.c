/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:13:48 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/20 19:35:43 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d_bonus.h"
//#include "./includes/cub3d.h"

void	check(void)
{
	system("leaks cub3d");
}

void	test_map_array(t_map_data *map_data, t_tile_type **map)
{
	(void)map_data;
	int	i = 0;
	int	max = (int)floor(log10(map_data->height)) + 1;
	
	while (i < map_data->height + 2)
	{
		printf("%d", i);
		for (int m = (i == 0 ? 1 : (int)floor(log10(i) + 1)); m <= max; m++)
			printf(" ");
		printf("[");
		int	j = 0;
		while (j < map_data->width + 2)
		{
			if (map[i][j] == EMPTY)
				printf("  ");
			else if (map[i][j] == GROUND)
				printf("0 ");
			else if (map[i][j] == WALL)
				printf("1 ");
			else if (map[i][j] == ST_N)
				printf("N ");
			else if (map[i][j] == ST_S)
				printf("S ");
			else if (map[i][j] == ST_W)
				printf("W ");
			else if (map[i][j] == ST_E)
				printf("E ");
			j++;
		}
		printf("]\n");
		i++;
	}
}

void	test_map_array_bonus(t_map_data *map_data, t_tile **map)
{
	(void)map_data;
	int	i = 0;
	int	max = (int)floor(log10(map_data->height)) + 1;
	
	while (i < map_data->height + 2)
	{
		ft_printf("%d", i);
		for (int m = (i == 0 ? 1 : (int)floor(log10(i) + 1)); m <= max; m++)
			printf(" ");
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