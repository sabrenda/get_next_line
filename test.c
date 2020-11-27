#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#define BUFFER_SIZE 8

int main()
{
	int fd = open("file", O_RDONLY);
	char buffer[BUFFER_SIZE + 1];
	int i, last;

	last = read(fd, buffer, BUFFER_SIZE);
	last = read(fd, buffer, BUFFER_SIZE);
	buffer[last] = '\0';
	printf("%d\n",last);
	printf("%s\n",buffer);
	return (0);
}
