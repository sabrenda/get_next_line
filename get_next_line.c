/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:24:46 by sabrenda          #+#    #+#             */
/*   Updated: 2020/11/29 09:47:22 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int				read_file;
	char			buffer[2];
	char			*point_n;
	static char		*global;
	int				enter;

	enter = 1;
	if (global)
		*line = ft_strdup(global);
	else
		*line = ft_strdup("");
	while (enter && (read_file = read(fd, buffer, 1)) && read_file > 0)
	{
		buffer[1] = '\0';
		if ((point_n = ft_strchr(buffer, '\n')))
		{
			enter = 0;
			point_n++[0] = '\0';
			global = ft_strdup(point_n);
		}
		*line = ft_strjoin(*line, buffer);
	}
	if (read_file < 0)
		return (-1);
	if (!enter)
		return 1;
	else
	{
		free(global);
		return 0;
	}
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
