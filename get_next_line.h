/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 08:19:05 by alexzudin         #+#    #+#             */
/*   Updated: 2019/09/28 16:45:28 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# define BUFF_SIZE 32
int		get_next_line(const int fd, char **line);
int		crstr(char **line, char *bufer, int status);
char	*ft_strjoins(char const *s1, char const *s2);
char	*ft_strdups(const char *s1);

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include "libft/libft.h"

#endif
