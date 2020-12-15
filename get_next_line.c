/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:59:46 by sabrenda          #+#    #+#             */
/*   Updated: 2020/12/16 00:34:25 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_rasengan(char **s_line)
{
	char	*str;

	if (*s_line)
	{
		str = ft_strdup(*s_line);
		ft_bzero(*s_line, ft_strlen(*s_line));
		return (str);
	}
	else
		str = ft_strdup("");
	return (str);
}

char	*ft_chidori(char *point_n, char **s_line)
{
	if (*s_line)
		free(*s_line);
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
		if (!(*s_line = ft_chidori(point_n, s_line)))
			return (-1);
	ft_bzero(buf, BUFFER_SIZE + 1);
	while (!point_n && (read_f = read(fd, buf, BUFFER_SIZE)) && read_f > 0)
	{
		if ((point_n = ft_strchr(buf, '\n')))
			if (!(*s_line = ft_chidori(point_n, s_line)))
				return (-1);
		if (!(*line = ft_strjoin(*line, buf)) || read_f < 0)
			return (-1);
		ft_bzero(buf, BUFFER_SIZE + 1);
	}
	if (!point_n && (read_f == 0 || (read_f < BUFFER_SIZE && read_f >= 0)))
		return (0);
	else if (read_f < 0)
		return (-1);
	return (1);
}

t_gnl	*new_list(int fd)
{
	t_gnl	*new;

	if (!(new = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	new->fd = fd;
	new->s_line = NULL;
	new->next = NULL;
	return (new);
}

int		get_next_line(int fd, char **line)
{
	static t_gnl	*head;
	t_gnl			*tmp;
	int				x;

	if (fd < 0 || line == 0)
		return (-1);
	if (!head)
		if (!(head = new_list(fd)))
			return (-1);
	tmp = head;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			if (!(tmp->next = new_list(fd)))
				return (-1);
		tmp = tmp->next;
	}
	x = ft_get_line(tmp->fd, line, &tmp->s_line);
	return (x);
}
