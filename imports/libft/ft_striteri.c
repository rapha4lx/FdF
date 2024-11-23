/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:57:56 by rferro-d          #+#    #+#             */
/*   Updated: 2024/10/10 14:55:20 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	sz;

	if (s == NULL || f == NULL)
		return ;
	sz = 0;
	while (s[sz])
	{
		(*f)(sz, s + sz);
		sz++;
	}
}
