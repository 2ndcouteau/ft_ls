/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_tree_sub.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 11:54:15 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/21 20:33:54 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

void		ls_print_tree_sub_no_opt(t_tree **tree_sub)
{
	if ((*tree_sub)->left != NULL)
		ls_print_tree_sub_no_opt(&(*tree_sub)->left);
	ft_putendl_clair((*tree_sub)->content);
	if ((*tree_sub)->right != NULL)
		ls_print_tree_sub_no_opt(&(*tree_sub)->right);
}

void		ls_print_tree_sub_opt(t_env **e, t_tree **tree_sub)
{
	if ((*e)->opt_s->l)
	{
		if (((*e)->opt_s->a || (*e)->opt_s->f || (*e)->form->nb_node > 2) &&
	(*e)->form->stat_m == 1)
			l_print_total(e);
		ls_print_long_format(e, tree_sub);
		l_init_form(e);
	}
	else
	{
		if ((*e)->form->nb_node > 2 && ft_strchr((*e)->opt, 's') &&
	(*e)->form->stat_m == 1)
			l_print_total(e);
		ls_print_short_format(e, tree_sub);
		l_init_form(e);
	}
}

void		ls_print_tree_sub_opt_rev(t_env **e, t_tree **tree_sub)
{
	if ((*e)->opt_s->l)
	{
		if (((*e)->opt_s->a || (*e)->opt_s->f || (*e)->form->nb_node > 2) &&
	(*e)->form->stat_m == 1)
			l_print_total(e);
		ls_print_long_format_rev(e, tree_sub);
		l_init_form(e);
	}
	else
	{
		if ((*e)->form->nb_node > 2 && ft_strchr((*e)->opt, 's') &&
	(*e)->form->stat_m == 1)
			l_print_total(e);
		ls_print_short_format_rev(e, tree_sub);
		l_init_form(e);
	}
}
