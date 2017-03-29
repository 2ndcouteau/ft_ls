/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_exist_letter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 20:55:19 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/20 23:06:05 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

static void	add_option_null(char c, t_env **e)
{
	if (((*e)->opt = ft_memalloc(2)))
	{
		(*e)->opt[0] = c;
		(*e)->opt[1] = '\0';
		(*e)->mark = 0;
	}
}

static void	add_option(char c, t_env **e, int i)
{
	char	*new;

	if ((*e)->opt != NULL)
	{
		if ((new = ft_memalloc(ft_strlen((*e)->opt) + 2)))
		{
			while ((*e)->opt[i] != '\0')
			{
				new[i] = (*e)->opt[i];
				i++;
			}
			new[i] = c;
			new[i + 1] = '\0';
			free((*e)->opt);
			(*e)->opt = new;
			new = NULL;
		}
	}
	else
		add_option_null(c, e);
}

void		opt_exist_letter(char *str, t_env **e, int i, int a)
{
	while (str[i] != '\0')
	{
		while ((*e)->opt != NULL && (*e)->opt[a] != '\0' &&
	str[i] != (*e)->opt[a])
			a++;
		if ((*e)->opt == NULL || (*e)->opt[a] == '\0')
			add_option(str[i], e, 0);
		else
		{
			a = 0;
			i++;
		}
	}
}
