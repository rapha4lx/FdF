/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:05:02 by rferro-d          #+#    #+#             */
/*   Updated: 2024/11/25 21:47:02 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void    free_content(void * p)
{
    free (p);
}

static char	*get_line(t_list **head, char **line)
{
	char	*temp_buff;
	t_list	*temp;

	while (*head)
	{
		if (line && *line && ft_strchr(*line, '\n'))
			return (*line);
		temp = (*head)->next;
		temp_buff = *line;
		if (*line || (*head)->content)
			*line = ft_strjoin(*line, (char *)(*head)->content);
		if (temp_buff)
			free(temp_buff);
		// ft_lstclear(head, &free_content);
		ft_lstdelone(*head, &free_content);
		*head = temp;
	}
	return (*line);
}

int		process_line(int fd, char *buff, t_list **head)
{
	int i;
	char	*tmp;

	if (read(fd, buff, BUFFER_SIZE) <= 0)
		return (0);
	if (ft_strchr(buff, '\n'))
	{
		while (buff)
		{
			tmp = ft_strchr(buff, '\n');
			if (!tmp)
				break;
			i = (tmp - buff) + 1;
			ft_lstadd_back(head, ft_lstnew(ft_substr(buff, 0, i)));
			buff += i;
		}
		ft_lstadd_back(head, ft_lstnew(ft_strdup(buff)));
		return (0);
	}
	else
		ft_lstadd_back(head, ft_lstnew(ft_strdup(buff)));
	return (1);
}

char	*get_next_line(int fd)
{
	char			buff[BUFFER_SIZE + 1];
	char			*line;
	int				i;
	static t_list	*head = NULL;

	i = -1;
	line = NULL;
	while (BUFFER_SIZE >= ++i)
		buff[i] = '\0';
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (head)
	{
		line = get_line(&head, &line);
		if (ft_strchr(line, '\n'))
			return (line);
	}
	while (process_line(fd, buff, &head))
	{
		i = -1;
		while (BUFFER_SIZE >= ++i)
			buff[i] = '\0';
	}
	return (line = get_line(&head, &line));
}
