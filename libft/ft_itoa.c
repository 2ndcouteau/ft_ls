/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 17:15:40 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/16 20:45:41 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_len(int n, size_t *size, int *e)
{
	*size = 1;
	*e = 1;
	if (n < 0)
	{
		*size += 1;
		n = -n;
	}
	while (n / *e > 9)
	{
		*e *= 10;
		*size += 1;
	}
}

char		*ft_itoa(int n)
{
	size_t	size;
	size_t	i;
	int		e;
	char	*result;

	ft_len(n, &size, &e);
	if ((result = ft_memalloc(size + 1)))
	{
		i = 0;
		if (n < 0)
			result[i++] = '-';
		if (n < 0)
			n = -n;
		while (e > 0)
		{
			result[i++] = (n / e % 10) + 48;
			e /= 10;
		}
		result[i] = '\0';
		return (result);
	}
	return (NULL);
}
