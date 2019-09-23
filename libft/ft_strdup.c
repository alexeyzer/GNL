/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 21:10:54 by aguiller          #+#    #+#             */
/*   Updated: 2019/09/23 13:16:21 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft/libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*a;

	i = ft_strlen(s1);
	a = (char*)malloc(sizeof(char) * (i + 1));
	if (a == NULL)
		return (NULL);
	ft_memcpy(a, s1, i);
	a[i] = '\0';
	return (a);
}
