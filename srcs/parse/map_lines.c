#include "parser.h" 
#include <stdio.h>
#include <stdlib.h>

t_lines		*ft_sline_new(void)
{
	t_lines		*it;

	it = (t_lines*)malloc(sizeof(t_lines) * 1);
	if (!it)
		return (NULL);
	it->next = NULL;
	it->pointer = NULL;
	return (it);
}

void	ft_sline_add_back(t_lines **lst, t_lines *new)
{
	t_lines *it;

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

void	ft_sline_clear(t_lines **lst, void (*del)(void *))
{
	t_lines	*it;

	if (lst == NULL)
		return ;
	if (del == NULL)
	{
		while(*lst != NULL)
		{
			it = (*lst)->next;
			ft_m_pointer_clear(&(*lst)->pointer, NULL);
			ft_sline_delone((*lst));
			*lst = it;
		}
	}
	// else
	// 	while (*lst != NULL)
	// 	{
	// 		it = (*lst)->next;
	// 		ft_m_pointer_clear((*lst)->pointer);
	// 		*lst = it;
	// 	}
}
