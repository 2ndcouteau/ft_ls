/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_create_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 16:04:48 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/22 00:53:56 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

char	*ls_save_path(char *path, char *file_name, int i, int a)
{
	char	*ret;

	if (path == NULL)
		ret = ft_strdup(file_name);
	else
	{
		ret = ft_memalloc(ft_strlen(path) + ft_strlen(file_name) + 2);
		while (path[i] != '\0')
		{
			ret[i] = path[i];
			i++;
		}
		if (ft_strcmp(path, "/") != 0)
			ret[i++] = '/';
		while (file_name[a] != '\0')
			ret[i++] = file_name[a++];
		ret[i] = '\0';
	}
	return (ret);
}

t_tree	*tree_create_node(t_env **e, char *file_name, char *path)
{
	t_tree	*tree;

	if (!(tree = (t_tree*)malloc(sizeof(t_tree))))
		return (NULL);
	tree->content_size = ft_strlen(file_name);
	tree->content = ft_strdup(file_name);
	tree->path_name = ls_save_path(path, file_name, 0, 0);
	tree->stat_m = lstat(tree->path_name, &tree->t_stat);
	if ((*e)->opt && tree->stat_m > -1)
	{
		tree->type = l_typefile_christmas(tree->t_stat.st_mode & S_IFMT);
		if (!(tree->form = (t_form*)malloc(sizeof(t_form))))
			return (NULL);
		l_check_max(e, &tree);
	}
	else
		tree->form = NULL;
	tree->left = NULL;
	tree->right = NULL;
	return (tree);
}

t_tree	*tree_init(t_env **e, char *file_name, char *path)
{
	t_tree	*tree;

	if (!(tree = (t_tree*)malloc(sizeof(t_tree))))
		return (NULL);
	tree->content_size = ft_strlen(file_name);
	tree->content = ft_strdup(file_name);
	tree->path_name = ls_save_path(path, file_name, 0, 0);
	tree->stat_m = lstat(tree->path_name, &tree->t_stat);
	if ((*e)->opt && tree->stat_m > -1)
	{
		tree->type = l_typefile_christmas(tree->t_stat.st_mode & S_IFMT);
		if (!(tree->form = (t_form*)malloc(sizeof(t_form))))
			return (NULL);
		l_check_max(e, &tree);
	}
	else
		tree->form = NULL;
	tree->left = NULL;
	tree->right = NULL;
	return (tree);
}

t_tree	*ls_construc_tree(t_env **e, char **argv, int argc, char *path)
{
	t_tree	*tree;
	int		i;

	i = 0;
	tree = NULL;
	if ((*e)->nb_arg > 0)
	{
		tree = tree_init(e, (*e)->s_arg[i++], path);
		while (i < (*e)->nb_arg)
			tree_add_elem(e, &tree, (*e)->s_arg[i++], path);
	}
	if ((*e)->i < argc)
	{
		if (tree == NULL)
			tree = tree_init(e, argv[(*e)->i], path);
		while ((*e)->i < argc)
		{
			tree_add_elem(e, &tree, argv[(*e)->i++], path);
			(*e)->count += 1;
		}
	}
	if (tree == NULL)
		tree = tree_init(e, ".", path);
	return (tree);
}
