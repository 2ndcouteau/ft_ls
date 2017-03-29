/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_acl_extend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 16:38:42 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/20 22:39:38 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

static int	l_acl(char *path)
{
	acl_t	acl;

	acl = acl_get_link_np(path, ACL_TYPE_EXTENDED);
	if (acl)
	{
		acl_free(acl);
		return (1);
	}
	acl_free(acl);
	acl = NULL;
	return (0);
}

void		l_acl_extend(t_tree **tree, char *line, size_t *cpt)
{
	if (listxattr((*tree)->path_name, NULL, 5, XATTR_NOFOLLOW) > 0)
		line[*cpt] = '@';
	else if (l_acl((*tree)->path_name))
		line[*cpt] = '+';
	else
		line[*cpt] = ' ';
	*cpt += 1;
	line[*cpt] = ' ';
	*cpt += 1;
}
