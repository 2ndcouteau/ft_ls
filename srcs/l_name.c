/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_name.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 21:43:18 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/22 01:05:02 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

void	l_name(t_env **e, t_tree **tree, char *line, size_t *cpt)
{
	int		i;

	i = 0;
	while ((*tree)->content[i] != '\0')
	{
		line[*cpt] = (*tree)->content[i];
		i++;
		*cpt += 1;
	}
	line[*cpt] = '\0';
}

void	l_link(t_env **e, t_tree **tree, char *line, size_t *cpt)
{
	char	link[PATH_MAX];
	int		i;

	i = 0;
	ft_bzero((void*)link, PATH_MAX);
	if (readlink((*tree)->path_name, link, sizeof(link)) > 0)
	{
		line[*cpt] = ' ';
		line[*cpt + 1] = '-';
		line[*cpt + 2] = '>';
		line[*cpt + 3] = ' ';
		*cpt += 4;
		while (link[i] != '\0')
		{
			line[*cpt] = link[i];
			i++;
			*cpt += 1;
		}
	}
}
