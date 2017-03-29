/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_recursive_tree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 14:00:17 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/20 22:23:56 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

static void	ls_recursive_tree_normal(t_env **e, t_tree **tree_sub)
{
	if ((*tree_sub)->left != NULL)
		ls_recursive_tree_normal(e, &(*tree_sub)->left);
	if (ft_strcmp((*tree_sub)->content, ".") != 0 &&
	ft_strcmp((*tree_sub)->content, "..") != 0)
	{
		if ((*e)->opt_s->a || (*e)->opt_s->f)
			ls_print_node_opt_2(e, tree_sub, 3);
		else if (ft_strncmp((*tree_sub)->content, ".", 1))
			ls_print_node_opt_2(e, tree_sub, 3);
	}
	if ((*tree_sub)->right != NULL)
		ls_recursive_tree_normal(e, &(*tree_sub)->right);
}

static void	ls_recursive_tree_reverse(t_env **e, t_tree **tree_sub)
{
	if ((*tree_sub)->right != NULL)
		ls_recursive_tree_reverse(e, &(*tree_sub)->right);
	if (ft_strcmp((*tree_sub)->content, ".") != 0 &&
	ft_strcmp((*tree_sub)->content, "..") != 0)
	{
		if ((*e)->opt_s->a || (*e)->opt_s->f)
			ls_print_node_opt_3(e, tree_sub, 3);
		else if (ft_strncmp((*tree_sub)->content, ".", 1))
			ls_print_node_opt_3(e, tree_sub, 3);
	}
	if ((*tree_sub)->left != NULL)
		ls_recursive_tree_reverse(e, &(*tree_sub)->left);
}

void		ls_recursive_tree(t_env **e, t_tree **tree_sub, bool mark)
{
	if (mark == 0)
		ls_recursive_tree_normal(e, tree_sub);
	else
		ls_recursive_tree_reverse(e, tree_sub);
}
