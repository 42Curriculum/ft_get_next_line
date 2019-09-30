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
		get_next_line(i, &str);
		get_next_line(i, &str);
		//printf(" Line 2: %s \n", str);
		get_next_line(i, &str);
		//printf(" Line 3: %s \n", str);
	}
	return (0);
}
