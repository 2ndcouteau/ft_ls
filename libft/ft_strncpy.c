/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:58:26 by qrosa             #+#    #+#             */
/*   Updated: 2015/02/23 18:34:26 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	a;

	a = 0;
	if (dst && src)
	{
		while (dst[a] && src[a] && a < n)
		{
			dst[a] = src[a];
			a++;
		}
		while (a < n)
		{
			dst[a] = '\0';
			a++;
		}
	}
	return (dst);
}
