/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 16:07:49 by qrosa             #+#    #+#             */
/*   Updated: 2014/11/14 20:17:44 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_sttrcpy(char *dst, const char *src, size_t i, size_t n)
{
	unsigned int a;

	a = 0;
	while (a < n)
	{
		dst[a] = src[i];
		a++;
		i++;
	}
	dst[n] = '\0';
	return (dst);
}

char			*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *scop;

	if (s == NULL)
		return (NULL);
	if ((scop = ((char*)malloc(sizeof(char) * len + 1))))
	{
		scop = ft_sttrcpy(scop, s, start, len);
		return (scop);
	}
	return (scop);
}
