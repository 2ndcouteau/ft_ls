/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 20:55:19 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/20 22:37:25 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

t_env	*ft_parse_arguments(int argc, char **argv)
{
	t_env	*env;

	env = NULL;
	if ((env = malloc(sizeof(t_env))))
	{
		opt_init_env(&env);
		if (argc != 1)
			ft_get_options(argc, argv, &env);
	}
	else
		env->error = 1;
	return (env);
}
