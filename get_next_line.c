/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:24:46 by sabrenda          #+#    #+#             */
/*   Updated: 2020/11/28 05:46:31 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int				read_file;
	char			buffer[BUFFER_SIZE + 1];
	char			*point_n;
	static char		*global;
	int 			flag;

	flag = 1;
	if (global)
		*line = ft_strdup(global);
	else
		*line = ft_strdup("");
	while(flag && (read_file = read(fd, buffer, BUFFER_SIZE)) && read_file > 0)
	{
		buffer[BUFFER_SIZE] = '\0';
		if (point_n = ft_strchr(buffer,'\n'))
		{
			flag = 0;
			*point_n = '\0';
			point_n++;
			*global = ft_strdup(point_n);
		}
		*line = ft_strjoin(*line, buffer);
	}
	if (read_file < 0)
		return (-1);
	if (!flag)
		return (1);
	return (0);
}

int main()
{
	int fd = open("file", O_RDONLY);
	char *line;
	int i;
	while ((i = get_next_line(fd, &line)))
	{
		printf("i = %d %s\n", i, line);
		free(line);
	}
	printf("i = %d %s\n", i, line);
	free(line);
	return (0);
}
