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

void	n_sucks(char *str)
{
	while (*str)
	{
		if (*str == '\n')
		{
			while (*str == '\n')
				str++;
			return ;
		}
		str++;
	}
}

int 		skip_newline(char *str, int n)
{
	while (str[n] == '\n')
	{
		n++;
	}
	return(n);
}

char		*copy_to_newline(char *str)
{
	size_t i;
	char *s;
	i = 0;

	while (str[i] != '\n')
	{
		i++;
	}
	s = ft_strnew(i);
	s = ft_strncpy(s, str, i);
	return(s);
}

int			check_line(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
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
	else if ((n = check_line(next_line[fd])))
	{
		*line = copy_to_newline(next_line[fd]);
		n_sucks(next_line[fd]);
		next_line[fd] += (n = skip_newline(next_line[fd],n));
	}

	while ((b = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[b] = '\0';
		next_line[fd] = ft_strjoin(next_line[fd], buffer);
		//next_line[fd] += (n = skip_newline(next_line[fd],n));
		if ((n = check_line(next_line[fd])))
		{
			*line = copy_to_newline(next_line[fd]);
			return (1);
		}
	}
	next_line[fd] += (n = skip_newline(next_line[fd],n));
	*line = next_line[fd];
	return(0);
}