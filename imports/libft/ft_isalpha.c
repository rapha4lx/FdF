/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:14:13 by rferro-d          #+#    #+#             */
/*   Updated: 2024/09/23 19:14:45 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1024);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main()
{
	printf("ft: %d\n", ft_isalpha('a'));
	printf("ft: %d\n", ft_isalpha('2'));
	printf("ofc: %d\n", isalpha('a'));
	printf("ofc: %d\n", isalpha('2'));

}*/
