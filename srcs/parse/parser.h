/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: showoff <showoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 04:31:34 by rferro-d          #+#    #+#             */
/*   Updated: 2024/12/18 19:45:03 by showoff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H


typedef	struct s_map_pointer_array
{
	int		value;
	char	*hex;
} t_map_pointer_array;

typedef	struct s_map_pointer
{
	int		value;
	char	*hex;
	struct	s_map_pointer *next;
} t_map_pointer;

// void	ft_m_pointer_del_filter(void *, int value, char *hex);
t_map_pointer	*ft_m_pointer_new(int value, char *hex);
void	ft_m_pointer_add_back(t_map_pointer **lst, t_map_pointer *new);
void	ft_m_pointer_delone(t_map_pointer *lst);
void	ft_m_pointer_clear(t_map_pointer **lst, void (*del)(void *));

typedef struct s_lines
{
	t_map_pointer	*pointer;
	struct s_lines	*next;
}	t_lines;

t_lines	*ft_sline_new(void);
void	ft_sline_add_back(t_lines **lst, t_lines *new);
void	ft_sline_delone(t_lines *lst);
void	ft_sline_clear(t_lines **lst, void (*del)(void *));
t_lines	*ft_sline_get_last(t_lines *lst);

typedef struct s_map
{
	int		status;
	int		map_fd;
	int		fd_status;
	char	*map_file;
	int		map_width;
	int		map_height;
	
	t_lines	*map_lines;
	t_map_pointer_array **map_array;
}	t_map;

int		init_map(t_map **map);
int		map_check(char *file, t_map **map);
int		build_line(t_map **map, char **buff);
void	free_map(t_map **map);

#endif