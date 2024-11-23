/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:15:05 by rferro-d          #+#    #+#             */
/*   Updated: 2024/10/09 11:54:28 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	sz;
	char	*str;

	sz = ft_strlen((char *)s);
	str = (char *)malloc(sizeof(char) * (sz + 1));
	if (str == NULL)
		return (NULL);
	while (*s)
		*str++ = *s++;
	*str = '\0';
	return (str - sz);
}
