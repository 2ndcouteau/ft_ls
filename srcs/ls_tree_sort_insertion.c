/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_tree_sort_insertion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 17:47:16 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/20 23:00:01 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

void	tree_insert_node_alpha_date(t_env **e, t_tree **tree,
	char *name, char *path)
{
	if (ls_strcmp_alpha(name, (*tree)->content) > 0)
	{
		if ((*tree)->left == NULL)
			(*tree)->left = tree_create_node(e, name, path);
		else
			tree_insert_node_date(e, &(*tree)->left, name, path);
	}
	else
	{
		if ((*tree)->right == NULL)
			(*tree)->right = tree_create_node(e, name, path);
		else
			tree_insert_node_date(e, &(*tree)->right, name, path);
	}
}

void	tree_insert_node_alpha(t_env **e, t_tree **tree, char *name, char *path)
{
	if (ls_strcmp_alpha(name, (*tree)->content) > 0)
	{
		if ((*tree)->left == NULL)
			(*tree)->left = tree_create_node(e, name, path);
		else
			tree_insert_node_alpha(e, &(*tree)->left, name, path);
	}
	else
	{
		if ((*tree)->right == NULL)
			(*tree)->right = tree_create_node(e, name, path);
		else
			tree_insert_node_alpha(e, &(*tree)->right, name, path);
	}
}

void	tree_insert_node_date(t_env **e, t_tree **tree, char *name, char *path)
{
	time_t		diff;

	diff = ls_strcmp_date(ls_save_path(path, name, 0, 0), ls_save_path(path,
	(*tree)->content, 0, 0));
	if (diff < 0)
	{
		if ((*tree)->left == NULL)
			(*tree)->left = tree_create_node(e, name, path);
		else
			tree_insert_node_date(e, &(*tree)->left, name, path);
	}
	else if (diff > 0)
	{
		if ((*tree)->right == NULL)
			(*tree)->right = tree_create_node(e, name, path);
		else
			tree_insert_node_date(e, &(*tree)->right, name, path);
	}
	else
		tree_insert_node_alpha_date(e, tree, name, path);
}

void	tree_insert_node_f(t_env **e, t_tree **tree, char *name, char *path)
{
	if ((*tree)->right == NULL)
		(*tree)->right = tree_create_node(e, name, path);
	else
		tree_insert_node_f(e, &(*tree)->right, name, path);
}
