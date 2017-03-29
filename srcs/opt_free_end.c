/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_free_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 18:13:01 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/20 23:12:59 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

static void	free_s_arg(t_env **e)
{
	int i;

	i = 0;
	while (i < (*e)->nb_arg)
	{
		free((*e)->s_arg[i]);
		(*e)->s_arg[i++] = NULL;
	}
	free((*e)->s_arg);
	(*e)->s_arg = NULL;
}

void		free_opt(t_env **e)
{
	if ((*e)->opt != NULL)
		free((*e)->opt);
	(*e)->opt = NULL;
	if ((*e)->l_opt != NULL)
		free((*e)->l_opt);
	(*e)->l_opt = NULL;
	if ((*e)->form != NULL)
		free((*e)->form);
	(*e)->form = NULL;
	if ((*e)->opt_s != NULL)
		free((*e)->opt_s);
	(*e)->form = NULL;
	if ((*e)->s_arg != NULL)
		free_s_arg(e);
	free(*e);
	*e = NULL;
}
