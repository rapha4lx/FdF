/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 04:31:34 by rferro-d          #+#    #+#             */
/*   Updated: 2024/11/24 23:02:19 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef	struct s_map_pointer
{
	int		value;
	char	*hex;
	struct	s_map_pointer *next;
} t_map_pointer;

void	ft_m_pointer_del_filter(void *, int value, char *hex);
void	ft_m_pointer_add_back(t_map_pointer **lst, t_map_pointer *new);
void	ft_m_pointer_delone(t_map_pointer *lst, void (*del)(void *));
void	ft_m_pointer_clear(t_map_pointer **lst, void (*del)(void *));

typedef struct s_lines
{
	t_map_pointer	*pointer;
	struct s_lines	*next;
}	t_lines;

void	ft_sline_add_back(t_lines **lst, t_lines *new);
void	ft_sline_delone(t_lines *lst, void (*del)(void *));
void	ft_sline_clear(t_lines **lst, void (*del)(void *));

typedef struct s_map
{
    int     status;
	int		map_width;
	int		map_height;
	t_lines *map_lines;
}       t_map;

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *));


int map_check(char *file, t_map **map);

#endif