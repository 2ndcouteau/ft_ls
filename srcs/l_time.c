/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_time.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 21:41:23 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/20 22:51:01 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

static void	l_time_date(char *time_p, char *line, size_t *cpt)
{
	int		i;

	i = 4;
	while (i != 11)
	{
		line[*cpt] = time_p[i];
		i++;
		*cpt += 1;
	}
	i = 19;
	while (i != 24)
	{
		line[*cpt] = time_p[i];
		i++;
		*cpt += 1;
	}
	line[*cpt] = ' ';
	*cpt += 1;
}

static void	l_time_hour(char *time_p, char *line, size_t *cpt)
{
	int		i;

	i = 4;
	while (i != 16)
	{
		line[*cpt] = time_p[i];
		i++;
		*cpt += 1;
	}
	line[*cpt] = ' ';
	*cpt += 1;
}

void		l_time(t_env **e, t_tree **tree, char *line, size_t *cpt)
{
	char	*time_p;

	time_p = ctime(&(*tree)->t_stat.st_mtime);
	if (((*tree)->t_stat.st_mtime > ((*e)->time_n - 16070000)) &&
	((*tree)->t_stat.st_mtime < (*e)->time_n + 3600))
		l_time_hour(time_p, line, cpt);
	else
		l_time_date(time_p, line, cpt);
}
