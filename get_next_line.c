/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:49:46 by jjosephi          #+#    #+#             */
/*   Updated: 2019/09/27 21:39:35 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"
#include <stdio.h>

int			check_line(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void	skip_n(char **str)
{
	while (**str == '\n' )
		*str+=1;
}

char	*cpy_nn(char *line, char **next_line)
{
	int i;

	i = -1;
	while ((*next_line)[++i] != '\n' && (*next_line)[++i] !='\0')
		;
	line = ft_strnew(i);
	line = ft_strncpy(line, *next_line, i);
	*next_line += i;
	return (line);
}

int		get_next_line(const int fd, char **line)
{
	char 		buffer[BUFF_SIZE + 1];
	static char **next_line;
	int b;
	int n;

	n = 0;
	if (!(next_line))
		next_line = (char **)malloc(FD_MAX * sizeof(next_line) + 1);
	if (!(next_line[fd]))
		next_line[fd] = "";
	else if ((n = check_line(next_line[fd]) == TRUE))
	{
		skip_n(&next_line[fd]);
		*line = cpy_nn(*line,&next_line[fd]);
		printf("Line %s \n", *line);
		printf("next line %s \n", next_line[fd]);
	}

	while ((b = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[b] = '\0';
		next_line[fd] = ft_strjoin(next_line[fd], buffer);
		skip_n(&next_line[fd]);
		if ((n = check_line(next_line[fd])))
		{
			*line = cpy_nn(*line, &next_line[fd]);
			printf("Line %s \n", *line);
			printf("next line %s \n", next_line[fd]);
			return (1);
		}
	}

	*line = next_line[fd];
	return(0);
}