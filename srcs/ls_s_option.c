/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_s_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 22:43:38 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/20 22:58:19 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

void	ls_s_opt(t_env **e, t_tree **tree)
{
	size_t	diff;

	if ((*e)->opt_s->s)
	{
		diff = (*e)->form->len_blocks - (*tree)->form->len_blocks;
		while (diff != 0)
		{
			ft_putchar(' ');
			diff -= 1;
		}
		ft_putnbr((*tree)->t_stat.st_blocks);
		ft_putchar(' ');
	}
}

void	l_s_opt(t_env **e, t_tree **tree, char *line, size_t *cpt)
{
	size_t	diff;
	char	*nb_blocks;

	if ((*e)->opt_s->s)
	{
		diff = (*e)->form->len_blocks - (*tree)->form->len_blocks;
		while (diff != 0)
		{
			line[*cpt] = ' ';
			*cpt += 1;
			diff -= 1;
		}
		if ((nb_blocks = ft_itoa((*tree)->t_stat.st_blocks)) != NULL)
		{
			l_copy_number(line, nb_blocks, cpt);
			free(nb_blocks);
			nb_blocks = NULL;
		}
		line[*cpt] = ' ';
		*cpt += 1;
	}
}
