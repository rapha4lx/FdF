#include "parser.h"
#include <stdlib.h>

void	ft_m_pointer_add_back(t_map_pointer **lst, t_map_pointer *new)
{

}

void	ft_m_pointer_delone(t_map_pointer *lst, void (*del)(void *))
{

}

void	ft_m_pointer_clear(t_map_pointer **lst)
{
    t_map_pointer	*it;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		it = (*lst)->next;
        ft_m_pointer_clear((*lst)->pointer,)
		*lst = it;
	}
    
}

