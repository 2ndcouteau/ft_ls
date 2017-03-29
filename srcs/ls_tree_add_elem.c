/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_tree_add_elem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 22:58:49 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/20 22:58:51 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

void	tree_add_elem(t_env **e, t_tree **tree, char *name, char *path)
{
	if ((*e)->opt != NULL)
	{
		if ((*e)->opt_s->f)
			tree_insert_node_f(e, tree, name, path);
		else if ((*e)->opt_s->t)
			tree_insert_node_date(e, tree, name, path);
		else
			tree_insert_node_alpha(e, tree, name, path);
	}
	else
		tree_insert_node_alpha(e, tree, name, path);
}
