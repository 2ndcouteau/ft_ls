/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 19:33:52 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/20 22:45:52 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

void	l_print_long(t_env **e, t_tree **tree_sub)
{
	if ((*tree_sub)->left != NULL)
		l_print_long(e, &(*tree_sub)->left);
	l_print_line(e, tree_sub);
	if ((*tree_sub)->right != NULL)
		l_print_long(e, &(*tree_sub)->right);
}

void	l_print_long_clair(t_env **e, t_tree **tree_sub)
{
	if ((*tree_sub)->left != NULL)
		l_print_long_clair(e, &(*tree_sub)->left);
	if ((*tree_sub)->content[0] != '.')
		l_print_line(e, tree_sub);
	if ((*tree_sub)->right != NULL)
		l_print_long_clair(e, &(*tree_sub)->right);
}

void	l_print_long_rev(t_env **e, t_tree **tree_sub)
{
	if ((*tree_sub)->right != NULL)
		l_print_long_rev(e, &(*tree_sub)->right);
	l_print_line(e, tree_sub);
	if ((*tree_sub)->left != NULL)
		l_print_long_rev(e, &(*tree_sub)->left);
}

void	l_print_long_clair_rev(t_env **e, t_tree **tree_sub)
{
	if ((*tree_sub)->right != NULL)
		l_print_long_clair_rev(e, &(*tree_sub)->right);
	if ((*tree_sub)->content[0] != '.')
		l_print_line(e, tree_sub);
	if ((*tree_sub)->left != NULL)
		l_print_long_clair_rev(e, &(*tree_sub)->left);
}
