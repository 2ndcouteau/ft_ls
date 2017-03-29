/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_print_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:32:14 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/21 20:32:07 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

static void	l_print_line_valid(t_env **e, t_tree **tree)
{
	char	*line;
	size_t	cpt;

	cpt = 0;
	line = ft_memalloc(1024);
	l_s_opt(e, tree, line, &cpt);
	line[cpt++] = (*tree)->type;
	l_right(tree, line, &cpt);
	l_acl_extend(tree, line, &cpt);
	l_nb_links(e, tree, line, &cpt);
	l_owner_name(e, tree, line, &cpt);
	l_group_name(e, tree, line, &cpt);
	if ((*tree)->form->dev == 1)
		l_min_maj(e, tree, line, &cpt);
	else
		l_size_file(e, tree, line, &cpt);
	l_time(e, tree, line, &cpt);
	l_name(e, tree, line, &cpt);
	if ((*tree)->type == 'l')
		l_link(e, tree, line, &cpt);
	line[cpt] = '\0';
	ft_putendl(line);
	free(line);
	line = NULL;
}

void		l_print_line(t_env **e, t_tree **tree)
{
	if ((*e)->form->stat_m == 1)
		l_print_line_valid(e, tree);
	else
		ls_print_error(2, (*tree)->content);
}
