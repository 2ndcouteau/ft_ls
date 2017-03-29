/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 16:49:25 by qrosa             #+#    #+#             */
/*   Updated: 2015/05/12 14:25:41 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush_back(t_list **list, t_list *elem)
{
	t_list *tmp;

	tmp = *list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = elem;
	free(tmp);
}
