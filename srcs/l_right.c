/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_right.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 16:17:03 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/20 22:47:22 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

static void	l_add_read_right(t_tree **tree, char *line,
	size_t *cpt, mode_t masque)
{
	if ((*tree)->t_stat.st_mode & masque)
		line[*cpt] = 'r';
	else
		line[*cpt] = '-';
	*cpt += 1;
}

static void	l_add_write_right(t_tree **tree, char *line,
	size_t *cpt, mode_t masque)
{
	if ((*tree)->t_stat.st_mode & masque)
		line[*cpt] = 'w';
	else
		line[*cpt] = '-';
	*cpt += 1;
}

static void	l_add_exec_right(t_tree **tree, char *line,
	mode_t masque1, mode_t masque2)
{
	if ((*tree)->t_stat.st_mode & masque1)
		*line = ((*tree)->t_stat.st_mode & masque2) ? 's' : 'S';
	else
		*line = ((*tree)->t_stat.st_mode & masque2) ? 'x' : '-';
}

static void	l_add_exec_right_other(t_tree **tree, char *line, size_t *cpt)
{
	if ((*tree)->t_stat.st_mode & S_ISVTX)
		line[*cpt] = ((*tree)->t_stat.st_mode & S_IXOTH) ? 't' : 'T';
	else
		line[*cpt] = ((*tree)->t_stat.st_mode & S_IXOTH) ? 'x' : '-';
}

void		l_right(t_tree **tree, char *line, size_t *cpt)
{
	l_add_read_right(tree, line, cpt, S_IRUSR);
	l_add_write_right(tree, line, cpt, S_IWUSR);
	l_add_exec_right(tree, &line[*cpt], S_ISUID, S_IXUSR);
	*cpt += 1;
	l_add_read_right(tree, line, cpt, S_IRGRP);
	l_add_write_right(tree, line, cpt, S_IWGRP);
	l_add_exec_right(tree, &line[*cpt], S_ISGID, S_IXGRP);
	*cpt += 1;
	l_add_read_right(tree, line, cpt, S_IROTH);
	l_add_write_right(tree, line, cpt, S_IWOTH);
	l_add_exec_right_other(tree, line, cpt);
	*cpt += 1;
}
