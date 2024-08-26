/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 11:07:58 by minhulee          #+#    #+#             */
/*   Updated: 2024/08/26 14:06:19 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	is_valid_file_name(char *file)
{
	while (*file != '\0' && (*(file) != '.' || *(file + 1) == '.' || *(file + 1) == '/'))
		file++;
	if (ft_strncmp(file, ".cub", 5))
		ft_err("parsing :: invalid file name.");
}