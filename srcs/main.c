/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 20:55:19 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/20 23:01:12 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

static int	verify_argv(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (!(argv[i]) || argv[i][0] == '\0')
		{
			ls_print_error(1, "fts_open");
			return (0);
		}
		i++;
	}
	return (1);
}

int			main(int argc, char **argv)
{
	t_env	*e;

	if (verify_argv(argc, argv))
	{
		e = ft_parse_arguments(argc, argv);
		if ((*e).mark == 2)
		{
			opt_print_error(argv, e);
			return (0);
		}
		ls_check_options(&e);
		ls_main(&e, argv, argc);
		free_opt(&e);
		e = NULL;
	}
	return (0);
}
