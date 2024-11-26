#include "libft.h"

void	ft_free_split(char **buffer)
{
    int it;

    if (!buffer)
        return ;
    it = 0;
    while (buffer[it] != NULL)
    {
            free(buffer[it]);
            it++;
    }
    free(buffer);
}