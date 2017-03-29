/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 19:44:24 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/16 21:05:22 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*freespace;
	char	*init_space;

	freespace = (void *)malloc(size);
	init_space = (char *)freespace;
	if (init_space != NULL)
	{
		ft_bzero(init_space, size);
		return (freespace);
	}
	return (NULL);
}
