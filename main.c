#include "get_next_line.h"

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		printf("ERROR\n");
	printf("line 1: %s\n", get_next_line(fd));
	printf("line 2: %s\n", get_next_line(fd));
	close(fd);
	return (0);
}
