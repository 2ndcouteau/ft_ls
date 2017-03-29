/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_tree_insert_strcmp.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 01:29:34 by kaosu             #+#    #+#             */
/*   Updated: 2016/01/20 22:59:20 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

int	ls_strcmp_alpha(char *new, char *name_node)
{
	int	i;

	i = 0;
	while (new[i] != '\0' && name_node[i] == new[i])
		i++;
	return (name_node[i] - new[i]);
}

int	ls_strcmp_date(char *new, char *name_node)
{
	struct stat	s_node;
	struct stat	s_new;

	lstat(new, &s_new);
	lstat(name_node, &s_node);
	return (s_node.st_mtime - s_new.st_mtime);
}
