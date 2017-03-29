/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:07:14 by qrosa             #+#    #+#             */
/*   Updated: 2014/11/12 19:53:11 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		a;
	char	*tmp;

	tmp = NULL;
	a = 0;
	while (s[a] != '\0')
	{
		if (s[a] == c)
			tmp = ((char*)&s[a]);
		a++;
	}
	if (c == 0)
		return ((char*)&s[a]);
	return (tmp);
}
