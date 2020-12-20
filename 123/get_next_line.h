/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:50:50 by sabrenda          #+#    #+#             */
/*   Updated: 2020/12/19 20:18:02 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_gnl
{
	int				fd;
	char			*buf_line;
	struct s_gnl	*next;
}					t_gnl;
int					get_next_line(int fd, char **line);
int					ft_get_line(int fd, char **line, char **buf_line);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *str);
char				*ft_linestart_or_tail(char **buf_line);
char				*ft_point_change(char *point_n, char **buf_line);
t_gnl				*nw_lst(int fd);
int					ft_clean(t_gnl **head, t_gnl *tmp, t_gnl *before);

#endif
