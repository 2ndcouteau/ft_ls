/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_nb_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 14:56:09 by kaosu             #+#    #+#             */
/*   Updated: 2016/01/20 22:45:05 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

void	l_nb_links(t_env **e, t_tree **tree, char *line, size_t *cpt)
{
	size_t	diff;
	char	*nb_links;

	diff = (*e)->form->nb_links - (*tree)->form->nb_links;
	while (diff != 0)
	{
		line[*cpt] = ' ';
		*cpt += 1;
		diff -= 1;
	}
	if ((nb_links = ft_itoa((*tree)->t_stat.st_nlink)) != NULL)
	{
		l_copy_number(line, nb_links, cpt);
		free(nb_links);
		nb_links = NULL;
	}
	line[*cpt] = ' ';
	*cpt += 1;
}
