/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_save_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 20:55:19 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/20 23:20:09 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

static void	free_tab(t_env **e, int a)
{
	while (a < (*e)->nb_arg - 1)
		free((*e)->s_arg[a++]);
	free((*e)->s_arg);
	(*e)->s_arg = NULL;
}

static void	add_new_arg(char *str, t_env **e, int i)
{
	char	**new;

	if ((new = (char**)malloc(sizeof(char*) * ((*e)->nb_arg + 2))))
	{
		while (i < (*e)->nb_arg)
		{
			new[i] = ft_strdup((*e)->s_arg[i]);
			i++;
		}
		(*e)->nb_arg += 1;
		new[i] = ft_strdup(str);
		new[i + 1] = "\0";
	}
	free_tab(e, 0);
	(*e)->s_arg = new;
	new = NULL;
}

void		save_arg(char *str, t_env **e)
{
	if ((*e)->s_arg != NULL)
		add_new_arg(str, e, 0);
	else
	{
		if (((*e)->s_arg = (char**)malloc(sizeof(char*) * 2)))
		{
			(*e)->s_arg[0] = ft_strdup(str);
			(*e)->s_arg[1] = "\0";
			(*e)->nb_arg = 1;
		}
	}
}
