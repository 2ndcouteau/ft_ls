/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 11:54:15 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/04 19:06:41 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

void	ls_print_tree_no_opt(t_env **e, t_tree **tree, int argc, short mark)
{
	if ((*tree)->left != NULL)
		ls_print_tree_no_opt(e, &(*tree)->left, argc, mark);
	if (mark == 0)
		ls_print_node_no_opt_0(tree);
	else if (mark == 1)
		ls_print_node_no_opt_1(e, tree);
	else
		ls_print_node_no_opt_2(e, tree, argc);
	if ((*tree)->right != NULL)
		ls_print_tree_no_opt(e, &(*tree)->right, argc, mark);
}

void	ls_print_tree_normal(t_env **e, t_tree **tree, int argc, short mark)
{
	if ((*tree)->left != NULL)
		ls_print_tree_normal(e, &(*tree)->left, argc, mark);
	if (mark == 0)
		ls_print_node_opt_0(tree);
	else if (mark == 1)
		ls_print_node_opt_1(e, tree);
	else
		ls_print_node_opt_2(e, tree, argc);
	if ((*tree)->right != NULL)
		ls_print_tree_normal(e, &(*tree)->right, argc, mark);
}

void	ls_print_tree_reverse(t_env **e, t_tree **tree, int argc, short mark)
{
	if ((*tree)->right != NULL)
		ls_print_tree_reverse(e, &(*tree)->right, argc, mark);
	if (mark == 0)
		ls_print_node_opt_0(tree);
	else if (mark == 1)
		ls_print_node_opt_1(e, tree);
	else
		ls_print_node_opt_3(e, tree, argc);
	if ((*tree)->left != NULL)
		ls_print_tree_reverse(e, &(*tree)->left, argc, mark);
}
