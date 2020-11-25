/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:24:46 by sabrenda          #+#    #+#             */
/*   Updated: 2020/11/25 23:39:49 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int		get_next_line(int fd, char **line)
{
	unsigned int	n;
	unsigned int	last;
	char			*buffer;

	n = 0;
	m = 0;
	last = 0;
	while(1)
	{
	if (!(buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	last = read(fd, buffer, BUFFER_SIZE);
	buffer[last] = '\0';
	}

}
char	*ft_realloc(char *src, size_t buf)
{

	return (src);
}
int		read_from_fd(int fd)
{
	char	*buf;
	int		rs;

	rs = 0;
	if (!(buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	rs = read(fd, buf, BUFFER_SIZE);
	buf[rs] = '\0';
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
