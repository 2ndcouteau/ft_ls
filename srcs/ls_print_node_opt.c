/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_node_opt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 16:07:11 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/22 00:54:08 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

static void	ls_print_no_permission(char *name, int argc, char *path)
{
	if (argc > 2)
		ls_print_path(path);
	ls_print_error(2, name);
	ft_putchar('\n');
}

void		ls_print_node_opt_0(t_tree **tree)
{
	if ((*tree)->stat_m < 0)
		ls_print_error(2, (*tree)->content);
}

void		ls_print_node_opt_1(t_env **e, t_tree **tree)
{
	if ((*tree)->stat_m >= 0)
	{
		if ((*tree)->type != 'd')
		{
			(*e)->mark_b = 1;
			if ((*e)->opt_s->l)
				l_print_line(e, tree);
			else
				ls_print_elem(e, tree);
		}
	}
}

void		ls_print_node_opt_2(t_env **e, t_tree **tree, int argc)
{
	t_tree	*tree_sub;
	DIR		*p_dir;

	if ((*tree)->stat_m >= 0)
	{
		if ((*tree)->type != 'l' &&
		(p_dir = opendir((*tree)->path_name)) != NULL)
		{
			l_init_form(e);
			ls_read_dir(p_dir, e, tree, &tree_sub);
			if ((*e)->mark_c == 1)
				ls_print_path((*tree)->path_name);
			(*e)->mark_c = 1;
			ls_print_tree_sub_opt(e, &tree_sub);
			ft_putchar('\n');
			if ((*e)->opt_s->rec)
				ls_recursive_tree(e, &tree_sub, 0);
			ls_free_tree(&tree_sub);
			free(tree_sub);
		}
		else if (errno == EACCES)
			ls_print_no_permission((*tree)->content, argc, (*tree)->path_name);
	}
}

void		ls_print_node_opt_3(t_env **e, t_tree **tree, int argc)
{
	t_tree			*tree_sub;
	DIR				*p_dir;

	if ((*tree)->stat_m >= 0)
	{
		if ((*tree)->type != 'l' &&
		(p_dir = opendir((*tree)->path_name)) != NULL)
		{
			ls_read_dir(p_dir, e, tree, &tree_sub);
			if ((*e)->mark_c == 1)
				ls_print_path((*tree)->path_name);
			(*e)->mark_c = 1;
			ls_print_tree_sub_opt_rev(e, &tree_sub);
			ft_putchar('\n');
			if ((*e)->opt_s->rec)
				ls_recursive_tree(e, &tree_sub, 1);
			ls_free_tree(&tree_sub);
			free(tree_sub);
		}
		else if (errno == EACCES)
			ls_print_no_permission((*tree)->content, argc, (*tree)->path_name);
	}
}
