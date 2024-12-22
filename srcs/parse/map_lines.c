/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:35:51 by rferro-d          #+#    #+#             */
/*   Updated: 2024/12/21 21:36:04 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>
#include <stdlib.h>

t_lines	*ft_sline_new(void)
{
	t_lines	*it;

	it = (t_lines *)malloc(sizeof(t_lines));
	if (!it)
		return (NULL);
	it->next = NULL;
	it->pointer = NULL;
	return (it);
}

void	ft_sline_add_back(t_lines **lst, t_lines *new)
{
	t_lines	*it;

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

void	ft_sline_delone(t_lines *lst)
{
	if (lst == NULL)
		return ;
	free(lst);
}

void	ft_sline_clear(t_lines **lst)
{
	t_lines	*it;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		it = (*lst)->next;
		ft_m_pointer_clear(&(*lst)->pointer);
		ft_sline_delone((*lst));
		*lst = it;
	}
}

t_lines	*ft_sline_get_last(t_lines *lst)
{
	if (lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
