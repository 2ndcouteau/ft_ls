/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 20:03:59 by qrosa             #+#    #+#             */
/*   Updated: 2014/11/14 20:15:53 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*memcpytse(void *block, void const *content, size_t content_size)
{
	size_t	cpt;

	cpt = 0;
	while (cpt < content_size)
	{
		((unsigned char *)block)[cpt] = ((unsigned char *)content)[cpt];
		cpt++;
	}
	return (block);
}

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;
	void	*block;

	if (!(tmp = malloc(sizeof(*tmp))))
		return (NULL);
	if (tmp != NULL && content)
	{
		block = ft_memalloc(content_size);
		block = memcpytse(block, content, content_size);
		tmp->content_size = content_size;
		tmp->content = block;
		tmp->next = NULL;
	}
	else
	{
		tmp->content = NULL;
		tmp->content_size = 0;
		tmp->next = NULL;
	}
	return (tmp);
}
