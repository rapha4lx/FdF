/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:43:14 by rferro-d          #+#    #+#             */
/*   Updated: 2024/09/25 14:25:35 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
/*
#include <string.h>
int	main()
{
	char s[] = "ASDHAJHWA";
	char s2[] = "ASDHAJHWA";
	
	bzero(s, 3);
	ft_bzero(s2, 3);

	write(1, s, 9);
	write(1, "\n", 1);
	write(1, s2, 9);
}*/
