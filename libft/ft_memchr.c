/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:23:09 by qrosa             #+#    #+#             */
/*   Updated: 2014/11/12 17:54:37 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			a;
	unsigned char	*s1;

	s1 = (unsigned char*)s;
	a = 0;
	while (a < n)
	{
		if (((unsigned char*)s1)[a] == (unsigned char)c)
			return (((void*)s + a));
		a++;
	}
	return (NULL);
}
