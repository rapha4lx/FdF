/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:35:46 by rferro-d          #+#    #+#             */
/*   Updated: 2024/10/10 19:00:40 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	alloc_number(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*tmp;
	int		i;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = alloc_number(n);
	tmp = (char *)malloc(sizeof(char) * (i + 1));
	if (tmp == NULL)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		tmp[0] = '-';
	}
	tmp[i--] = '\0';
	while (n != 0)
	{
		tmp[i--] = (n % 10) + 48;
		n /= 10;
	}
	return (tmp);
}
