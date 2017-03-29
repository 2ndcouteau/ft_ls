/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:50:35 by qrosa             #+#    #+#             */
/*   Updated: 2014/11/12 17:02:51 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			b;
	unsigned char	c1;
	unsigned char	*dst1;
	unsigned char	*src1;

	b = 0;
	dst1 = (unsigned char*)dst;
	src1 = (unsigned char*)src;
	c1 = (unsigned char)c;
	while (b < n)
	{
		if ((*dst1++ = *src1++) == c1)
			return (dst1);
		b++;
	}
	return (NULL);
}
