/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_node_no_opt.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 12:30:55 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/22 01:14:49 by qrosa            ###   ########.fr       */
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

void		ls_print_node_no_opt_0(t_tree **tree)
{
	if (((*tree)->stat_m = lstat((*tree)->content, &(*tree)->t_stat)) < 0)
		ls_print_error(2, (*tree)->content);
}

void		ls_print_node_no_opt_1(t_env **e, t_tree **tree)
{
	if ((*tree)->stat_m >= 0)
	{
		if ((*tree)->type != 'd' && (*tree)->content[0] != '.' &&
	(*tree)->content[0] != '/')
		{
			(*e)->mark_b = 1;
			write(1, (*tree)->content, ft_strlen((*tree)->content));
			write(1, "\n", 1);
		}
	}
}

void		ls_print_node_no_opt_2(t_env **e, t_tree **tree, int argc)
{
	t_tree	*tree_sub;
	DIR		*p_dir;

	if ((*tree)->stat_m >= 0)
	{
		if ((p_dir = opendir((*tree)->path_name)) != NULL)
		{
			ls_read_dir(p_dir, e, tree, &tree_sub);
			if (argc > 2)
				ls_print_path((*tree)->path_name);
			ls_print_tree_sub_no_opt(&tree_sub);
			ft_putchar('\n');
			ls_free_tree(&tree_sub);
			free(tree_sub);
		}
		else if (errno == EACCES)
			ls_print_no_permission((*tree)->content, argc, (*tree)->path_name);
	}
}
