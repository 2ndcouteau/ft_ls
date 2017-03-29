/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 16:33:55 by qrosa             #+#    #+#             */
/*   Updated: 2015/03/21 19:57:01 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*result;
	int		b;
	int		e;
	int		mode;

	if (s == NULL)
		return (NULL);
	e = ft_strlen(s);
	mode = -1;
	b = 0;
	if (!(result = (char*)malloc(sizeof(char) * e + 1)))
		return (NULL);
	while ((s[b] == ' ' || s[b] == '\t' || s[b] == '\n') && s[b] != '\0')
		b++;
	while (s[e] == ' ' || s[e] == '\t' || s[e] == '\n' || s[e] == '\0')
		e--;
	while (b <= e)
	{
		result[++mode] = s[b];
		b++;
	}
	result[++mode] = '\0';
	return (result);
}
