/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:55:21 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/05 22:01:28 by minhulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n_len;

	n_len = ft_strlen(needle);
	if (!n_len)
		return ((char *)haystack);
	i = 0;
	while (*(haystack + i) && i < len)
	{
		if (*(haystack + i) == *needle && i + n_len <= len)
			if (!ft_strncmp(haystack + i, needle, n_len))
				return ((char *)haystack + i);
		i++;
	}
	return (0);
}
