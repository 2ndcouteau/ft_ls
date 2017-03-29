/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_size.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 20:24:21 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/20 22:50:30 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

static void	l_size_normal(t_env **e, t_tree **tree, char *line, size_t *cpt)
{
	size_t	diff;
	char	*size_c;

	if ((*e)->form->dev == 1)
		diff = 8 - (*tree)->form->size;
	else
		diff = (*e)->form->size - (*tree)->form->size;
	while (diff > 0)
	{
		line[*cpt] = ' ';
		*cpt += 1;
		diff -= 1;
	}
	diff = 0;
	if ((size_c = ft_itoa((*tree)->t_stat.st_size)) != NULL)
	{
		l_copy_number(line, size_c, cpt);
		free(size_c);
		size_c = NULL;
	}
	line[*cpt] = ' ';
	*cpt += 1;
}

static void	l_size_h_opt(t_env **e, t_tree **tree, char *line, size_t *cpt)
{
	char	*size_c;

	line[*cpt] = ' ';
	*cpt += 1;
	h_convert_size(e, tree, line, cpt);
	line[*cpt] = ' ';
	*cpt += 1;
}

void		l_size_file(t_env **e, t_tree **tree, char *line, size_t *cpt)
{
	if ((*e)->opt_s->h)
	{
		h_add_space(e, line, cpt);
		l_size_h_opt(e, tree, line, cpt);
	}
	else
		l_size_normal(e, tree, line, cpt);
}
