/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:58:27 by qrosa             #+#    #+#             */
/*   Updated: 2015/02/23 18:45:02 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	a;

	a = 0;
	while ((unsigned char)s1[a] && (unsigned char)s2[a] &&
	(unsigned char)(s1[a]) == (unsigned char)(s2[a]))
		a++;
	return ((unsigned char)(s1[a]) - (unsigned char)(s2[a]));
}
