#include "libft.h"

int		ft_get_split_size(char **buffer)
{
    int count;

    if (!buffer)
        return (0);
    count = 0;
    while (buffer[count])
        count++;
    return (count);
}

int		ft_get_nsplit_size(char **buffer, char exclude_c)
{
    int     it;
    int     count;

    if (!buffer)
        return (0);
    count = 0;
    it = 0;
    while (buffer[it])
    {
        if (!ft_strchr(buffer[it], exclude_c))
            count++;
        it++;
    }
    return (count);
}