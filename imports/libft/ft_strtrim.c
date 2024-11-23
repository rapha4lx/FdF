/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:34:21 by rferro-d          #+#    #+#             */
/*   Updated: 2024/10/10 19:01:06 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char const s1, char const *set)
{
	while (*set)
		if (s1 == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && is_set(*s1, set))
		s1++;
	end = ft_strlen(s1);
	while (end > 0 && is_set(s1[end - 1], set))
		end--;
	return (ft_substr(s1, 0, end));
}
