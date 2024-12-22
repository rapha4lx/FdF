/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:33:56 by rferro-d          #+#    #+#             */
/*   Updated: 2024/12/21 21:34:39 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../imports/libft/libft.h"
#include "parser.h"
#include <stdlib.h>

t_map_pointer	*ft_m_pointer_new(int value, char *hex)
{
	t_map_pointer	*node;

	node = (t_map_pointer *)malloc(sizeof(t_map_pointer) * 1);
	if (!node)
		return (NULL);
	node->value = value;
	node->hex = hex;
	node->next = NULL;
	return (node);
}

void	ft_m_pointer_add_back(t_map_pointer **lst, t_map_pointer *new)
{
	t_map_pointer	*it;

	if (!lst)
		return ;
	if (!(*lst))
	{
		(*lst) = new;
		return ;
	}
	it = *lst;
	while (it->next != NULL)
		it = it->next;
	it->next = new;
}

void	ft_m_pointer_delone(t_map_pointer *lst)
{
	if (lst == NULL)
		return ;
	if (lst->hex)
		free(lst->hex);
	free(lst);
}

void	ft_m_pointer_clear(t_map_pointer **lst)
{
	t_map_pointer	*it;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		it = (*lst)->next;
		ft_m_pointer_delone((*lst));
		*lst = it;
	}
}
