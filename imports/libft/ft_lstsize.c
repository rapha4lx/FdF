/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:15:22 by rferro-d          #+#    #+#             */
/*   Updated: 2024/10/09 16:07:06 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*it;
	int		i;

	if (lst == NULL)
		return (0);
	i = 0;
	it = lst;
	while (it != NULL)
	{
		i++;
		it = it->next;
	}
	return (i);
}
