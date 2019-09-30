#include "get_next_line.h"
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	char *str ;
	int i;
	//(void)argv;
	i = open(argv[1], O_RDONLY);
	if (argc > 1)
	{
		if (get_next_line(i, &str) == 1)
			printf("Line 1: %s\n", str);
		if (get_next_line(i, &str) == 1)
			printf("Line 2: %s\n", str);
		if (get_next_line(i, &str) == 1)
			printf("Line 3: %s\n", str);
		if (get_next_line(i, &str) == 1)
			printf("Line 4: %s\n", str);
	}
	return (0);
}
