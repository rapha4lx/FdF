/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_and_replace.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 22:20:08 by rferro-d          #+#    #+#             */
/*   Updated: 2025/01/03 16:29:45 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_search_and_replace(char *str, const char search, const char replace)
{
	int		i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		if ((unsigned char)str[i] == (unsigned char)search)
			str[i] = replace;
		i++;
	}
}
