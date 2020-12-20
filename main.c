#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd = open("file", O_RDONLY);
	char *line;
	int i;
	line = NULL;
	while ((i = get_next_line(fd, &line)))
	{
		printf("i = %d %s\n", i, line);
		free(line);
	}
	printf("i = %d %s\n", i, line);
	free(line);
    //while (1);
	line  = NULL;
	return (0);
}
