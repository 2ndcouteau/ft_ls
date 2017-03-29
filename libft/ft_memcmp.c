/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:37:19 by qrosa             #+#    #+#             */
/*   Updated: 2014/11/11 20:27:15 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	a;

	a = 0;
	while (a < n)
	{
		if (((unsigned char*)s1)[a] != ((unsigned char*)s2)[a])
			return (((unsigned char*)s1)[a] - ((unsigned char*)s2)[a]);
		a++;
	}
	return (0);
}
