/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_print_total.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 22:20:39 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/20 22:46:32 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

void	l_print_total(t_env **e)
{
	char *total;

	ft_putstr("total ");
	total = ft_itoa((*e)->form->nb_blocks);
	ft_putendl(total);
	free(total);
	total = NULL;
}
