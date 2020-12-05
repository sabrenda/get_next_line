/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ahmed <Ahmed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:45:03 by sabrenda          #+#    #+#             */
/*   Updated: 2020/12/05 13:56:02 by Ahmed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1024
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct		s_gnl
{
	int 			fd;
	char			*s_line;
	struct s_gnl	*next;
}					t_gnl;

int		get_next_line(int fd, char **line);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *str);
char	*ft_rasengan(char	**s_line);
char	*ft_chidori(char *point_n);
int		ft_get_line(int fd, char **line, char **s_line);
void	ft_bzero(char *s, size_t n);
t_gnl	*new_list(int fd);
size_t	ft_strlen(const char *str);

#endif
