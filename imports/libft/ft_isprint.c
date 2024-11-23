/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:13:15 by rferro-d          #+#    #+#             */
/*   Updated: 2024/09/25 14:27:00 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
int	main()
{
	printf("%d\n", ft_isprint(33));
	printf("%d\n", ft_isprint(127));
	printf("%d\n", isprint(33));
	printf("%d\n", isprint(127));
}*/
