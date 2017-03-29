/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_check_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 16:43:10 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/22 01:16:01 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

static void	a_action_condition(t_env **e, t_tree **tree)
{
	(*tree)->form->owner = ((*tree)->form->owner_c) ? ft_strlen((*tree)->
	form->owner_c->pw_name) : ft_nbrlen((*tree)->t_stat.st_uid);
	if ((*tree)->form->owner > (*e)->form->owner)
		(*e)->form->owner = (*tree)->form->owner;
	(*tree)->form->group = ((*tree)->form->group_c) ? ft_strlen((*tree)->
	form->group_c->gr_name) : ft_nbrlen((*tree)->t_stat.st_gid);
	if ((*tree)->form->group > (*e)->form->group)
		(*e)->form->group = (*tree)->form->group;
	if (((*tree)->form->len_blocks = ft_nbrlen((*tree)->t_stat.st_blocks))
	> (*e)->form->len_blocks)
		(*e)->form->len_blocks = (*tree)->form->len_blocks;
	(*e)->form->nb_blocks += (*tree)->t_stat.st_blocks;
	if (((*tree)->form->size = ft_nbrlen((*tree)->t_stat.st_size))
	> (*e)->form->size)
		(*e)->form->size = (*tree)->form->size;
	if (((*tree)->form->nb_links = ft_nbrlen((*tree)->t_stat.st_nlink))
	> (*e)->form->nb_links)
		(*e)->form->nb_links = (*tree)->form->nb_links;
	(*e)->form->nb_node += 1;
}

static void	a_check_condition(t_env **e, t_tree **tree)
{
	if ((*e)->opt_s->a)
		a_action_condition(e, tree);
	else if ((*e)->opt_s->f && (ft_strchr((*tree)->content, '.') ||
	ft_strstr((*tree)->content, "..")))
		a_action_condition(e, tree);
	else if ((*tree)->content[0] != '.')
		a_action_condition(e, tree);
}

void		l_check_max(t_env **e, t_tree **tree)
{
	(*tree)->form->owner_c = getpwuid((*tree)->t_stat.st_uid);
	(*tree)->form->group_c = getgrgid((*tree)->t_stat.st_gid);
	if ((*tree)->stat_m != -1)
	{
		(*e)->form->stat_m = 1;
	}
	a_check_condition(e, tree);
	if ((*tree)->type == 'b' || (*tree)->type == 'c')
	{
		(*e)->form->dev = 1;
		(*tree)->form->dev = 1;
	}
	else
		(*tree)->form->dev = 0;
}
