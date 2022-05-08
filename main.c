#include "get_next_line.h"

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		printf("ERROR\n");
	printf("result: %s\n", get_next_line(fd));
	close(fd);
	return (0);
}
