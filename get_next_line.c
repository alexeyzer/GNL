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

char	*ft_strdups(const char *s1)
{
	int		i;
	char	*a;

	i = ft_strlen(s1);
	a = (char*)malloc(sizeof(char) * i);
	if (a == NULL)
		return (NULL);
	ft_memcpy(a, s1, i);
	return (a);
}

char	*ft_strjoins(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*memstr;

	if ((s1 == NULL || s2 == NULL))
		return (NULL);
	i = 0;
	j = 0;
	memstr = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (memstr == NULL)
		return (NULL);
	ft_strclr(memstr);
	while (s1[i] != '\0')
	{
		memstr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		memstr[i] = s2[j];
		i++;
		j++;
	}
	return (memstr);
}

int		crstr(char **line, char *bufer, int status)
{
	if (!(*line))
	{
		if (bufer[status] == '\n' || status == 0)
		{
			if (!(*line = ft_strdups(bufer)))
			return (-1);
		}
		else if (!(*line = ft_strdup(bufer)))
			return (-1);
	}
	else
	{
		if (bufer[status] == '\n' || status == 0)
		{
			if (!((*line) = ft_strjoins(ft_strdup(*line),bufer)))
				return (-1);
		}
		else
		{ 
			if (!((*line) = ft_strjoin(ft_strdup(*line),bufer)))
				return (-1);
		}
	}
	return (1);
}

int		buf_check(char *bufer, int status, char **line, int fd)
{
	int	i;

	i = 0;
	while (bufer[i] != '\n')
		i++;
		
	if (bufer[i] == '\n')
			return (crstr(line, bufer, status));
		else if	(status <= BUFF_SIZE)
		{
			if(crstr(line, bufer, status))
				return (get_next_line(fd, line));
			else
				return (-1);
		}	

}

int		get_next_line(const int fd, char **line)
{
	char	Bufer[BUFF_SIZE];
	int		status;

	if (fd < 0)
		return (0);
	status = 0;
	while ((status = read(fd, Bufer, BUFF_SIZE)))
	{
		printf("%c", Bufer[status - 1]);
		printf("%d",status);
		if (status < 0)
			return (-1);
		if (status == 0)
			return (crstr(line, Bufer, status));
		
	}
	return (0);
}