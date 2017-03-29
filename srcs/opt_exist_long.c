/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_exist_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 20:55:19 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/20 23:11:03 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

static void	add_l_option_nnull(char *str, t_env **e, int i)
{
	int		a;
	char	*new;

	a = 2;
	if ((new = ft_memalloc(ft_strlen(str) + ft_strlen((*e)->l_opt) + 2)))
	{
		while ((*e)->l_opt[i] != '\0')
		{
			new[i] = (*e)->l_opt[i];
			i++;
		}
		new[i] = ' ';
		i++;
		while (str[a] != '\0')
		{
			new[i] = str[a];
			i++;
			a++;
		}
		new[i] = '\0';
	}
	free((*e)->l_opt);
	(*e)->l_opt = new;
	new = NULL;
}

static void	add_l_option(char *str, t_env **e)
{
	if ((*e)->l_opt != NULL)
		add_l_option_nnull(str, e, 0);
	else
	{
		(*e)->l_opt = ft_strdup(str + 2);
		(*e)->mark = 0;
	}
}

static bool	check_opt_exist(char *str, t_env **e, int i, int a)
{
	while ((*e)->l_opt[a] != '\0')
	{
		i = 2;
		while ((*e)->l_opt[a] != '\0' && (*e)->l_opt[a] != ' ' &&
	str[i] != '\0' && (*e)->l_opt[a] == str[i])
		{
			i++;
			a++;
		}
		if (str[i] != '\0' || (str[i] == '\0' && ((*e)->l_opt[a] != '\0' &&
	(*e)->l_opt[a] != ' ')))
			i = 2;
		else
			return (0);
		while ((*e)->l_opt[a] != ' ' && (*e)->l_opt[a] != '\0')
			a++;
		if ((*e)->l_opt[a] == ' ')
			a++;
	}
	return (1);
}

bool		opt_exist_long(char *str, t_env **e)
{
	if ((*e)->l_opt != NULL)
	{
		if (!(check_opt_exist(str, e, 2, 0)))
			return (0);
		add_l_option(str, e);
	}
	else
		add_l_option(str, e);
	return (1);
}
