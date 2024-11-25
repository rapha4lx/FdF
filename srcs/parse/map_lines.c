#include "parser.h" 
#include <stdio.h>

void	ft_sline_add_back(t_lines **lst, t_lines *new)
{

}

void	ft_sline_delone(t_lines *lst, void (*del)(void *))
{

}

void	ft_sline_clear(t_lines **lst, void (*del)(void *))
{
    t_lines	*it;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		it = (*lst)->next;
        ft_m_pointer_clear((*lst)->pointer,)
		ft_lstdelone(*lst, del);
		*lst = it;
	}
}
