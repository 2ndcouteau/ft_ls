/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_init_form.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 20:46:37 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/21 18:13:06 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

void	l_init_form(t_env **e)
{
	(*e)->form->owner_c = NULL;
	(*e)->form->group_c = NULL;
	(*e)->form->owner = 1;
	(*e)->form->group = 1;
	(*e)->form->size = 1;
	(*e)->form->nb_links = 1;
	(*e)->form->len_blocks = 0;
	(*e)->form->nb_blocks = 0;
	(*e)->form->nb_node = 0;
	(*e)->form->dev = 0;
	(*e)->form->stat_m = 0;
}
