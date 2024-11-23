/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:12:40 by rferro-d          #+#    #+#             */
/*   Updated: 2024/10/08 16:19:43 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc;

	if (nmemb != 0 && size != 0)
		if ((nmemb * size) / size != nmemb)
			return (NULL);
	alloc = malloc(nmemb * size);
	if (alloc == NULL)
		return (NULL);
	ft_bzero(alloc, nmemb * size);
	return (alloc);
}
