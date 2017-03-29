/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 16:25:25 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/22 00:27:21 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

static void	ls_option_normal(t_env **e, t_tree **tree, int argc)
{
	ls_print_tree_normal(e, tree, argc, 0);
	ls_print_tree_normal(e, tree, argc, 1);
	if ((*e)->mark_b == 1)
		ft_putchar('\n');
	ls_print_tree_normal(e, tree, argc, 2);
}

static void	ls_option_reverse(t_env **e, t_tree **tree, int argc)
{
	ls_print_tree_normal(e, tree, argc, 0);
	ls_print_tree_reverse(e, tree, argc, 1);
	if ((*e)->mark_b == 1)
		ft_putchar('\n');
	ls_print_tree_reverse(e, tree, argc, 2);
}

static void	ls_no_option(t_env **e, char **argv, int argc)
{
	t_tree	*tree;

	if ((tree = ls_construc_tree(e, argv, argc, NULL)) == NULL)
		return ;
	ls_print_tree_no_opt(e, &tree, argc, 0);
	ls_print_tree_no_opt(e, &tree, argc, 1);
	if ((*e)->mark_b == 1)
		ft_putchar('\n');
	ls_print_tree_no_opt(e, &tree, argc, 2);
	ls_free_tree(&tree);
	free(tree);
	tree = NULL;
}

static void	ls_option(t_env **e, char **argv, int argc)
{
	t_tree *tree;

	if ((tree = ls_construc_tree(e, argv, argc, NULL)) == NULL)
		return ;
	if (((*e)->nb_arg + (*e)->count) > 1)
		(*e)->mark_c = 1;
	if ((*e)->opt_s->f || !(*e)->opt_s->r)
		ls_option_normal(e, &tree, argc);
	else
		ls_option_reverse(e, &tree, argc);
	ls_free_tree(&tree);
	free(tree);
	tree = NULL;
}

void		ls_main(t_env **e, char **argv, int argc)
{
	if ((*e)->mark == 1 || (*e)->mark == 4)
		ls_no_option(e, argv, argc);
	else
		ls_option(e, argv, argc);
}
