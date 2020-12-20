/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ahmed <Ahmed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:39:00 by sabrenda          #+#    #+#             */
/*   Updated: 2020/12/19 07:46:47 by Ahmed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	if (!(str = (char*)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[j])
			str[i++] = s1[j++];
	j = 0;
	free(s1);
	if (s2)
		while (s2[j])
			str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *str)
{
	char	*cp;
	int		i;

	i = 0;
	while (str[i])
		i++;
	if (!(cp = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		cp[i] = str[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
	{
		while (s[i])
			i++;
		return ((char *)s + i);
	}
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

t_gnl	*nw_lst(int fd)
{
	t_gnl	*new;

	if (!(new = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	new->fd = fd;
	new->buf_line = NULL;
	new->next = NULL;
	return (new);
}
