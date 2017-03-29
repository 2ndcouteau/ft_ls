/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 15:35:58 by qrosa             #+#    #+#             */
/*   Updated: 2014/12/07 03:47:24 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*src;
	t_list	*dst;
	t_list	*begin_list;

	src = lst;
	dst = f(src);
	begin_list = dst;
	while (src->next != NULL)
	{
		dst->next = f(src->next);
		dst = dst->next;
		src = src->next;
	}
	return (begin_list);
}
