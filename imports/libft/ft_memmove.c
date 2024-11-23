/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:21:36 by rferro-d          #+#    #+#             */
/*   Updated: 2024/10/08 18:26:42 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;
	size_t			i;

	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned char *)src;
	i = 0;
	if (tmp_dest <= tmp_src || tmp_dest > (tmp_src + n))
	{
		while (i < n)
		{
			tmp_dest[i] = tmp_src[i];
			i++;
		}
		dest = (void *)tmp_dest;
	}
	else
	{
		while (n--)
			tmp_dest[n] = tmp_src[n];
		dest = (void *)tmp_dest;
	}
	return (dest);
}
