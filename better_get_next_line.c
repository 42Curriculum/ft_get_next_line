/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   better_get_next_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:49:46 by jjosephi          #+#    #+#             */
/*   Updated: 2019/09/26 12:56:57 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

static char	*ft_strnjoin(char *s1, char **s2)
{
	size_t	len;
	char	*str;

	len = ft_strlen(s1) + ft_strlen(*s2) + 1;
	if (!(str = malloc(len)))
		return (NULL);
	str = ft_strcpy(str, s1);
	return (ft_strcat(str, *s2));
}


static void del_read(char *next_line)
{
	int i;

	i = 0;
	while (next_line[i])
		i++;
	ft_strdel(&next_line);
	*next_line += i + 2;
}

static int check_line(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			return (1);
		}
		if (str[i] == '\0'  && str[i + 1] != '\0')
		{
			del_read(str);
			return(1);
		}
		else if (str[i] == '\0'  && str[i + 1] == '\0')
			return (0);
		i++;
	}
	return (0);
}

int			better_get_next_line(const int fd, char **line)
{
	char 		*buffer[BUFF_SIZE + 2];
	static char **next_line;
	int			b;

	if (!(next_line))
		if(!(next_line = (char **)malloc(FD_MAX * sizeof(next_line) + 1)))
		return (-1);
	while ((b = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[b] = NULL;
		buffer[b + 1] = NULL;
		next_line[fd] = ft_strnjoin(next_line[fd], buffer);
	}
	b = check_line(next_line[fd]);
	
	
	line = next_line;
	return (b);
}