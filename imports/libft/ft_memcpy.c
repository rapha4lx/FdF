/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:34:00 by rferro-d          #+#    #+#             */
/*   Updated: 2024/10/08 16:04:38 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*temp_dest;
	char	*temp_src;
	size_t	count;

	count = 0;
	temp_dest = dest;
	temp_src = (char *)src;
	while (count < n)
	{
		temp_dest[count] = temp_src[count];
		count++;
	}
	return (dest);
}
