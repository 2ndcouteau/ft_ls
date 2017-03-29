/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_min_maj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 20:22:36 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/20 22:43:51 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

static void	l_add_min_maj(char *min_maj, char *line, size_t *cpt, bool mark)
{
	int		len;

	len = (mark == 1) ? 4 : 3;
	len -= ft_strlen(min_maj);
	while (len != 0)
	{
		line[*cpt] = ' ';
		*cpt += 1;
		len--;
	}
	while (min_maj[len] != '\0')
	{
		line[*cpt] = min_maj[len];
		*cpt += 1;
		len++;
	}
	if (mark == 0)
		line[*cpt] = ',';
	else
		line[*cpt] = ' ';
	*cpt += 1;
}

void		l_min_maj(t_env **e, t_tree **tree, char *line, size_t *cpt)
{
	char	*major;
	char	*minor;

	major = ft_itoa(major((*tree)->t_stat.st_rdev));
	minor = ft_itoa(minor((*tree)->t_stat.st_rdev));
	l_add_min_maj(major, line, cpt, 0);
	l_add_min_maj(minor, line, cpt, 1);
	free(minor);
	free(major);
	minor = NULL;
	major = NULL;
}
