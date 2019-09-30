/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:49:46 by jjosephi          #+#    #+#             */
/*   Updated: 2019/09/30 13:24:16 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"
#include <stdio.h>

int		check_line(char *str)
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
	while (**str == '\n')
		*str += 1;
}

char	*cpy_nn(char *line, char **next_line)
{
	int i;

	i = 0;
	while ((*next_line)[i] != '\n' && (*next_line)[i] != '\0')
		i++;
	line = ft_strnew(i);
	line = ft_strncpy(line, *next_line, i);
	*next_line += i;
	return (line);
}

int		get_next_line(const int fd, char **line)
{
	char		buffer[BUFF_SIZE + 1];
	static char **next_line;
	int			b;

	if (!(next_line))
		next_line = malloc(4094 * (sizeof(next_line) + 1));
	if (!(next_line[fd]))
		next_line[fd] = "";
	skip_n(&next_line[fd]);
	if ((check_line(next_line[fd]) == TRUE))
	{
		if (next_line[fd][0] == '\0')
			return (0);
		*line = cpy_nn(*line, &next_line[fd]);
		return (1);
	}
	while ((b = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[b] = '\0';
		next_line[fd] = ft_strjoin(next_line[fd], buffer);
		skip_n(&next_line[fd]);
		if ((check_line(next_line[fd]) == TRUE))
		{
			*line = cpy_nn(*line, &next_line[fd]);
			return (1);
		}
	}
	return (0);
}
