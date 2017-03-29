/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 14:59:45 by qrosa             #+#    #+#             */
/*   Updated: 2015/12/18 18:18:59 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	unsigned int a;
	unsigned int b;

	a = 0;
	if (!s2 || s2[0] == '\0')
		return ((char *)s1);
	while (s1 && s1[a] != '\0')
	{
		b = 0;
		if (s1[a] == s2[b])
		{
			while (s1[a + b] != '\0' && s2[b] != '\0' && s1[a + b] == s2[b])
			{
				if (s2[b + 1] == '\0')
					return ((char *)s1 + a);
				b++;
			}
		}
		a++;
	}
	return (NULL);
}
