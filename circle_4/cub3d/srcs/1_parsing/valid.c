/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 11:07:58 by minhulee          #+#    #+#             */
/*   Updated: 2024/08/25 11:20:29 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_bool	is_valid_file_name(char *file)
{
	while (file && *file != '\0')
	{
		if (*(file - 1) == '.')
			break ;
		file++;
	}
	if (ft_strncmp(file, "cub", 4))
		return (FALSE);
	return (TRUE);
}