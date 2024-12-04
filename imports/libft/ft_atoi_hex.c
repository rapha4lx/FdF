/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:32:16 by rferro-d          #+#    #+#             */
/*   Updated: 2024/12/04 19:39:43 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\v'
		|| c == '\t' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi_hexa(const char *str)
{
	int	result;
	int	digit;

	digit = 0;
	result = 0;
	if (!str)
		return (0xffffff);
	while (is_space(*str))
		str++;
	if (*str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X'))
		str += 2;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			digit = *str - '0';
		else if (*str >= 'a' && *str <= 'f')
			digit = *str - 'a' + 10;
		else if (*str >= 'A' && *str <= 'F')
			digit = *str - 'A' + 10;
		else
			break ;
		result = result * 16 + digit;
		str++;
	}
	return (result);
}
