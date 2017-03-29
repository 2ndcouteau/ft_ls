/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 19:38:52 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/16 18:30:43 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

void	ls_free_tree(t_tree **tree)
{
	if ((*tree)->left != NULL)
		ls_free_tree(&(*tree)->left);
	free((*tree)->content);
	(*tree)->content = NULL;
	free((*tree)->path_name);
	(*tree)->path_name = NULL;
	if ((*tree)->form != NULL)
		free((*tree)->form);
	(*tree)->form = NULL;
	if ((*tree)->left != NULL)
		free((*tree)->left);
	(*tree)->left = NULL;
	if ((*tree)->right != NULL)
		ls_free_tree(&(*tree)->right);
	if ((*tree)->right != NULL)
		free((*tree)->right);
	(*tree)->right = NULL;
}
