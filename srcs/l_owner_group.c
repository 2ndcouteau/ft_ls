/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_owner_group.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 01:04:43 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/22 01:15:47 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

static void	l_bad_owner(t_env **e, t_tree **tree, char *line, size_t *cpt)
{
	char	*owner;
	int		i;

	i = 0;
	owner = ft_itoa((*tree)->t_stat.st_uid);
	while (owner[i] != '\0')
	{
		line[*cpt] = owner[i];
		i++;
		*cpt += 1;
	}
	i = (*e)->form->owner - i;
	while (i != -2)
	{
		line[*cpt] = ' ';
		*cpt += 1;
		i--;
	}
	free(owner);
	owner = NULL;
}

static void	l_bad_group(t_env **e, t_tree **tree, char *line, size_t *cpt)
{
	char	*group;
	int		i;

	i = 0;
	group = ft_itoa((*tree)->t_stat.st_gid);
	while (group[i] != '\0')
	{
		line[*cpt] = group[i];
		i++;
		*cpt += 1;
	}
	i = (*e)->form->group - i;
	while (i != -2)
	{
		line[*cpt] = ' ';
		*cpt += 1;
		i--;
	}
	free(group);
	group = NULL;
}

void		l_owner_name(t_env **e, t_tree **tree, char *line, size_t *cpt)
{
	int		i;

	i = 0;
	if (!(*tree)->form->owner_c)
		l_bad_owner(e, tree, line, cpt);
	else
	{
		while ((*tree)->form->owner_c->pw_name[i] != '\0')
		{
			line[*cpt] = (*tree)->form->owner_c->pw_name[i];
			i++;
			*cpt += 1;
		}
		i = (*e)->form->owner - i;
		while (i != -2)
		{
			line[*cpt] = ' ';
			*cpt += 1;
			i--;
		}
	}
}

void		l_group_name(t_env **e, t_tree **tree, char *line, size_t *cpt)
{
	int		i;
	bool	check;

	i = 0;
	check = 0;
	if (!(*tree)->form->group_c)
		l_bad_group(e, tree, line, cpt);
	else
	{
		while ((*tree)->form->group_c->gr_name[i] != '\0')
		{
			line[*cpt] = (*tree)->form->group_c->gr_name[i];
			i++;
			*cpt += 1;
		}
		i = (*e)->form->group - i;
		while (i != -1)
		{
			line[*cpt] = ' ';
			*cpt += 1;
			i--;
		}
		line[*cpt] = ' ';
		*cpt += 1;
	}
}
