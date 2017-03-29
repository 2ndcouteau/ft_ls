/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:17:01 by qrosa             #+#    #+#             */
/*   Updated: 2015/02/23 18:44:19 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int a;
	unsigned int b;

	a = 0;
	if (!s2 || s2[0] == '\0')
		return ((char *)s1);
	while (s1 && s1[a] != '\0' && (n - a) != 0)
	{
		b = 0;
		if (s1[a] == s2[b])
		{
			while (s1[a + b] != '\0' && s2[b] != '\0' && (n - (a + b)) != 0
	&& s1[a + b] == s2[b])
			{
				if ((s2[b + 1] == '\0') || ((n - b) == 0))
					return ((char *)s1 + a);
				b++;
			}
		}
		a++;
	}
	return (NULL);
}
