/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 08:10:16 by alexzudin         #+#    #+#             */
/*   Updated: 2019/09/23 13:16:19 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>

int makeline(char **line, char **s, int fd, int status)
{
	int i;

	i = 0;
	while(s[i] != '\n' || s[i] != '\0')
		i++;
	if (s[i] == '\n')
	{
		*line = ft_strsub(&s[fd], 0, i);
		free(&s[fd]);
		ft_strdel(&s[fd]);
	}
	else
	{
		if (i == BUFF_SIZE)
			return (get_next_line(fd, line);
		*line = ft_strsub(&s[fd], 0, i);
		free(&s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*s[400];
	char 		*mem;
	char		bufer[BUFF_SIZE + 1];
	int			status;

	if (fd < 0 || line == NULL)
		return (0);
	status = 0;
	while ((status = read(fd, bufer, BUFF_SIZE) > 0))
	{
		bufer[status] = '\0'; 
		if (s[fd] == NULL)
			s[fd] = ft_strnew(0);
		mem = ft_strjoin(s[fd], bufer);
		free(s[fd]);
		s[fd] = mem;
	}
	if (status < 0)
		return (-1);
	if (status == 0 && s[fd] == NULL)
		return (0);
	return (makeline(line, s, fd, status));
}