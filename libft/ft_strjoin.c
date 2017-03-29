/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 16:17:56 by qrosa             #+#    #+#             */
/*   Updated: 2015/05/12 18:36:06 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_lenjoin(char const *s1, char const *s2)
{
	int		a;
	int		b;
	int		c;

	a = 0;
	b = 0;
	c = 0;
	if (s1 != NULL)
	{
		while (s1[a] != '\0')
			a++;
	}
	if (s2 != NULL)
	{
		while (s2[b] != '\0')
			b++;
	}
	c = a + b;
	return (c);
}

static void	ft_strcpjoin(char const *s1, char const *s2, char *dst)
{
	size_t	a;
	size_t	i;

	i = 0;
	a = 0;
	if (s1 != NULL)
	{
		while (s1[a] != '\0')
		{
			dst[i] = s1[a];
			a++;
			i++;
		}
	}
	a = 0;
	if (s2 != NULL)
	{
		while (s2[a] != '\0')
		{
			dst[i] = s2[a];
			a++;
			i++;
		}
		dst[i] = '\0';
	}
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;

	result = NULL;
	if (s1 != NULL && s2 != NULL)
	{
		if ((result = (char*)malloc(sizeof(char) * ft_lenjoin(s1, s2) + 1)))
			ft_strcpjoin(s1, s2, result);
		else
			return (NULL);
		return (result);
	}
	else if (s1 != NULL)
		return ((char*)s1);
	else if (s2 != NULL)
		return ((char*)s2);
	else
		return (NULL);
}
