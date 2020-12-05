/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ahmed <Ahmed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:24:46 by sabrenda          #+#    #+#             */
/*   Updated: 2020/12/05 13:55:15 by Ahmed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_rasengan(char	**s_line)
{
	char	*str;
	str = NULL;
	if (*s_line)
	{
		str = ft_strdup(*s_line);
		ft_bzero(*s_line, sizeof(*s_line));
		return (str);
	}
	else
		str = ft_strdup("");
	return (str);
}

char	*ft_chidori(char *point_n)
{
		*point_n = '\0';
		point_n++;
		return (ft_strdup(point_n));
}

int		ft_get_line(int fd, char **line, char **s_line)
{
	char			buf[BUFFER_SIZE + 1];
	char			*point_n;
	int				read_f;

	read_f = 0;
	if (!(*line = ft_rasengan(s_line)))
		return (-1);
	if ((point_n = ft_strchr(*line, '\n')))
		*s_line = ft_chidori(point_n);
	ft_bzero(buf, BUFFER_SIZE + 1);
	while (!point_n && (read_f = read(fd, buf, BUFFER_SIZE)) && read_f > 0)
	{
		if ((point_n = ft_strchr(buf, '\n')))
			*s_line = ft_chidori(point_n);
		if(!(*line = ft_strjoin(*line, buf)) && read_f < 0)
			return (-1);
		ft_bzero(buf, BUFFER_SIZE + 1);
	}
	if (!point_n && (read_f == 0 || (read_f < BUFFER_SIZE && read_f >= 0)))
		return (0);
	else if (read_f < 0)
		return (-1);
	else
		return (1);
}

t_gnl	*new_list(fd)
{
	t_gnl	*new;

	if (!(new = (t_gnl *)malloc(sizeof(t_gnl))))
		return NULL;
		new->fd = fd;
		new->s_line = NULL;
		new->next = NULL;
	return (new);
}

int		get_next_line(int fd, char **line)
{
	static t_gnl	*head;
	t_gnl			*tmp;

	if (fd < 0 || line == 0)
		return (-1);
	if (!head)
		head = new_list(fd);
	tmp = head;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = new_list(fd);
		tmp = tmp->next;
	}
	return (ft_get_line(tmp->fd, line, &tmp->s_line));
}
