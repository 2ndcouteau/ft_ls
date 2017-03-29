/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 17:40:37 by qrosa             #+#    #+#             */
/*   Updated: 2014/11/14 20:16:08 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memcpyy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if ((dest == 0) || (src == 0) || (n == 0))
		return (0);
	while (i < n)
	{
		((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
		i++;
	}
	return (dest);
}

void		*ft_realloc(void *ptr, size_t size)
{
	void	*result;

	if (size == 0)
	{
		free(ptr);
		ptr = NULL;
		return (ptr);
	}
	if (ptr == NULL)
	{
		result = malloc(size);
		return (result);
	}
	result = malloc(size);
	ft_memcpyy(result, ptr, size);
	free(ptr);
	return (result);
}
