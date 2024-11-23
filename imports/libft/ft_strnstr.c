/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:20:40 by rferro-d          #+#    #+#             */
/*   Updated: 2024/09/27 17:03:55 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*dst;
	char	*src;

	i = 0;
	dst = (char *)big;
	src = (char *)little;
	if (*src == '\0' || src == NULL)
		return (dst);
	while (dst[i] && i < len)
	{
		j = 0;
		while (src[j] == dst[i + j] && i + j < len)
		{
			if (src[j + 1] == '\0')
				return (dst + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
