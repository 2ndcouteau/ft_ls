/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_read_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 21:38:28 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/22 00:54:01 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

void	ls_read_dir(DIR *p_dir, t_env **e, t_tree **tree, t_tree **tree_sub)
{
	struct dirent	*s_dir;

	*tree_sub = NULL;
	while ((s_dir = readdir(p_dir)) != NULL)
	{
		if (*tree_sub == NULL)
			*tree_sub = tree_init(e, s_dir->d_name, (*tree)->path_name);
		else
			tree_add_elem(e, tree_sub, s_dir->d_name, (*tree)->path_name);
	}
	closedir(p_dir);
}
