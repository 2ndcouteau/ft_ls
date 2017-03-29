/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 20:55:19 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/20 22:35:19 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

static void	opt_exist(char *str, t_env **e)
{
	if (str[1] == '-')
		opt_exist_long(str, e);
	else
		opt_exist_letter(str, e, 1, 0);
}

void		ft_get_options(int argc, char **argv, t_env **e)
{
	while ((*e)->i < argc && (*e)->mark < 2)
	{
		if (argv[(*e)->i][0] == '-' && argv[(*e)->i][1] != '\0')
		{
			if (opt_is_valid(argv[(*e)->i], e))
			{
				if ((*e)->mark < 2)
					opt_exist(argv[(*e)->i], e);
			}
			else
				(*e)->mark = 2;
		}
		else
			save_arg(argv[(*e)->i], e);
		(*e)->i++;
	}
}
