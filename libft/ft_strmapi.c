/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 19:34:02 by qrosa             #+#    #+#             */
/*   Updated: 2014/11/14 20:11:21 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dst;
	size_t	n;

	n = 0;
	if (s != NULL && f != NULL)
	{
		dst = ft_strdup(s);
		while (dst[n] != '\0')
		{
			dst[n] = f(n, dst[n]);
			n++;
		}
		return (dst);
	}
	else
		return (NULL);
}
