/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:05:02 by rferro-d          #+#    #+#             */
/*   Updated: 2024/11/24 13:45:07 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*t_line_new_line(const char *str, int size)
{
	t_list	*new;
	char	*buff;
	int		i;

	buff = (char *)malloc(sizeof(char) * (size + 1));
	if (!buff)
		return (NULL);
	i = 0;
	while (str[i] && i < size)
	{
		buff[i] = str[i];
		i++;
	}
	buff[i] = '\0';
	new = (t_list *)malloc(sizeof(t_list) * 1);
	if (!new)
		return (NULL);
	new->content = (void *)buff;
	new->next = NULL;
	return (new);
}

static int	process_line(int fd, char *buff, t_list **head)
{
	int	n_count;
	int	b_len;

	if (read(fd, buff, BUFFER_SIZE) <= 0)
		return (0);
	b_len = ft_strlen(buff);
	n_count = ft_strchr(buff, '\n') - buff;
	if (n_count < b_len)
	{
		while (buff && n_count < b_len)
		{
			if (n_count == 0)
				n_count++;
			ft_lstadd_back(head, t_line_new_line(buff, n_count));
			buff += n_count;
			n_count = ft_strchr(buff, '\n') - buff;
			b_len = ft_strlen(buff);
		}
		if (b_len)
			ft_lstadd_back(head, t_line_new_line(buff, b_len));
		return (0);
	}
	ft_lstadd_back(head, t_line_new_line(buff, b_len));
	return (1);
}

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
		if (line && *line && (*line)[ft_strchr(*line, '\n') - *line] == '\n')
			return (*line);
		temp = (*head)->next;
		temp_buff = *line;
		*line = ft_strjoin(*line, (char *)(*head)->content);
		if (temp_buff)
			free(temp_buff);
		ft_lstclear(head, &free_content);
		*head = temp;
	}
	return (*line);
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
		if ((size_t)(ft_strchr(line, '\n') - *line) < ft_strlen(line))
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
