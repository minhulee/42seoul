/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:20:35 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/09 09:59:07 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				flag;
	int				sum;
	unsigned int	i;

	flag = 1;
	sum = 0;
	i = 0;
	while (*(str + i) == 32 || (*(str + i) >= 9 && *(str + i) <= 13))
		i++;
	if (*(str + i) == '-' || *(str + i) == '+')
	{
		if (*(str + i) == '-')
			flag *= -1;
		i++;
	}
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		sum *= 10;
		sum += *(str + i) - '0';
		i++;
	}
	return (flag * sum);
}

int	ft_isatoi(const char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		i++;
	}
	return (ft_atoi(str));
}
