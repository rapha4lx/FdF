/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:17:55 by rferro-d          #+#    #+#             */
/*   Updated: 2024/11/25 21:37:11 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	size;

	size = 0;
	if (str == NULL)
		return (size);
	while (str[size] != '\0')
		size++;
	return (size);
}
/*
#include <string.h>
int	main()
{
	printf("%ld\n", ft_strlen("asdk\nkwki"));
	printf("%ld\n", strlen("asdk\nkwki"));
}*/
