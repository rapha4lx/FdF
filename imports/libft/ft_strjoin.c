/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:59:47 by rferro-d          #+#    #+#             */
/*   Updated: 2024/10/09 12:23:49 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buff;
	size_t	sz1;
	size_t	sz2;
	size_t	i;

	sz1 = ft_strlen((char *)s1);
	sz2 = ft_strlen((char *)s2);
	buff = (char *)malloc(sizeof(char) * ((sz1 + sz2) + 1));
	if (buff == NULL)
		return (NULL);
	i = 0;
	while (sz1 > i || sz2 > i)
	{
		if (sz1 > i)
			buff[i] = *((char *)s1 + i);
		if (sz2 > i)
			buff[sz1 + i] = *((char *)s2 + i);
		i++;
	}
	buff[sz1 + sz2] = '\0';
	return (buff);
}
