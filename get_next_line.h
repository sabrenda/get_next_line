/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:57:53 by sabrenda          #+#    #+#             */
/*   Updated: 2020/12/05 15:00:04 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int			get_next_line(int fd, char **line);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *str);
char		*ft_rasengan(char	**s_line);
char		*ft_chidori(char *point_n);
int			ft_get_line(int fd, char **line, char **s_line);
void		ft_bzero(char *s, size_t n);
t_gnl		*new_list(int fd);
size_t		ft_strlen(const char *str);

typedef struct		s_gnl
{
	int				fd;
	char			*s_line;
	struct s_gnl	*next;
}					t_gnl;

#endif
