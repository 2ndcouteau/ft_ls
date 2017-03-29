/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_elem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 17:02:43 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/21 20:31:41 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

static void	ls_print_elem_valid(t_env **e, t_tree **tree_sub)
{
	if ((*e)->opt_s->a || (*e)->opt_s->f)
	{
		ls_s_opt(e, tree_sub);
		ft_putendl((*tree_sub)->content);
	}
	else if ((*tree_sub)->content[0] != '.')
	{
		ls_s_opt(e, tree_sub);
		ft_putendl((*tree_sub)->content);
	}
}

static void	ls_print_elem_unvalid(t_env **e, t_tree **tree_sub)
{
	if ((*e)->opt_s->a || (*e)->opt_s->f)
		ls_print_error(2, (*tree_sub)->content);
	else if ((*tree_sub)->content[0] != '.')
		ls_print_error(2, (*tree_sub)->content);
}

void		ls_print_elem(t_env **e, t_tree **tree_sub)
{
	if ((*e)->form->stat_m == 1)
		ls_print_elem_valid(e, tree_sub);
	else
		ls_print_elem_unvalid(e, tree_sub);
}
