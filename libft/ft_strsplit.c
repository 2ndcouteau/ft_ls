/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 20:27:46 by qrosa             #+#    #+#             */
/*   Updated: 2014/11/14 20:17:18 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nb_words(char const *s, char c)
{
	size_t	nb;
	size_t	i;
	size_t	size;

	size = ft_strlen(s);
	i = 0;
	nb = 0;
	if (!s)
		return (0);
	while (i < size)
	{
		if (s[i] != c)
		{
			while (s[i] != c && i < size)
				i++;
			nb++;
		}
		i++;
	}
	return (nb);
}

void			ft_initialize_word(size_t *i, size_t *b, size_t *m)
{
	*i = 0;
	*b = 0;
	*m = 0;
}

static size_t	*ft_size_words(char const *s, char c, size_t nb_words)
{
	size_t	*tab;
	size_t	i;
	size_t	b;
	size_t	m;

	ft_initialize_word(&i, &b, &m);
	if (!(tab = (size_t*)malloc(sizeof(size_t) * nb_words)))
		return (NULL);
	while (s[i] != '\0' && m < nb_words)
	{
		b = 0;
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
			{
				b++;
				i++;
			}
			tab[m] = b;
			m++;
		}
		i++;
	}
	return (tab);
}

char			**check_error(char const *s, char c)
{
	char	**result;

	if (c == 0 || s == NULL)
	{
		result = (char**)malloc(sizeof(char*) * 1);
		result[0] = 0;
		return (result);
	}
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**result;
	size_t	h;
	size_t	*l;
	size_t	i;

	if (check_error(s, c))
		return (check_error(s, c));
	h = ft_nb_words(s, c);
	l = ft_size_words(s, c, h);
	result = (char**)malloc(sizeof(char*) * h + 1);
	result[h + 1] = NULL;
	i = 0;
	while (i != h)
	{
		result[i] = (char*)malloc(sizeof(char) * l[i] + 1);
		ft_bzero(result[i], l[i] + 1);
		while (*s == c)
			s++;
		ft_memcpy(result[i], s, l[i]);
		s += l[i];
		i++;
	}
	return (result);
}
