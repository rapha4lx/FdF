/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:06:33 by rferro-d          #+#    #+#             */
/*   Updated: 2024/10/08 13:44:19 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*buff;
	size_t	sz;

	sz = ft_strlen((char *)s);
	buff = (char *)ft_calloc(sizeof(char), (sz + 1));
	if (buff == NULL)
		return (NULL);
	while (sz-- > 0)
		buff[sz] = (*f)(sz, s[sz]);
	return (buff);
}
