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

void	crstr(char **line, char *bufer)
{
	char *copy;

	copy = NULL;
	if(*line[0] == NULL)
	{
		*line = ft_strdup(bufer);
		return (1);
	}
	else
	{
		if(!(copy = ft_strdup(*line)))
			return 0;
		((*line) = ft_strjoin(copy,))
	}
}

int		get_next_line(const int fd, char **line)
{
	char	Bufer[BUFF_SIZE];
	int		status;

	if (fd < 0 || Line = NULL)
		return (-1);
	status = 0;
	while (status = read(fd, Bufer, BUFF_SIZE))
	{
		if (status < 0)
			return (-1);
		if (status = 0 || Buffer[status] = '\n')
		{
			if((crstr(line, Bufer))
				return (1);
		}
		else if	(status < BUFF_SIZE)
		{
			if(crstr(line, Bufer)
			{
				get_next_line(fd, line);
				return (1);
			}
		}	
	}
	return (0);
}