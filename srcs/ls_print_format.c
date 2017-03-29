/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 21:17:01 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/20 19:08:04 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

void	ls_print_long_format(t_env **e, t_tree **tree_sub)
{
	if ((*e)->opt_s->a || (*e)->opt_s->f)
		l_print_long(e, tree_sub);
	else
		l_print_long_clair(e, tree_sub);
}

void	ls_print_short_format(t_env **e, t_tree **tree_sub)
{
	if ((*tree_sub)->left != NULL)
		ls_print_short_format(e, &(*tree_sub)->left);
	ls_print_elem(e, tree_sub);
	if ((*tree_sub)->right != NULL)
		ls_print_short_format(e, &(*tree_sub)->right);
}

void	ls_print_long_format_rev(t_env **e, t_tree **tree_sub)
{
	if ((*e)->opt_s->a || (*e)->opt_s->f)
		l_print_long_rev(e, tree_sub);
	else
		l_print_long_clair_rev(e, tree_sub);
}

void	ls_print_short_format_rev(t_env **e, t_tree **tree_sub)
{
	if ((*tree_sub)->right != NULL)
		ls_print_short_format_rev(e, &(*tree_sub)->right);
	ls_print_elem(e, tree_sub);
	if ((*tree_sub)->left != NULL)
		ls_print_short_format_rev(e, &(*tree_sub)->left);
}
