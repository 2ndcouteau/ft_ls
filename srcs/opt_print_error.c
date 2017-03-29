/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_print_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 20:55:19 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/20 23:57:22 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

void	opt_print_error(char **argv, t_env *e)
{
	if (e->error == 1)
		ft_putendl_fd("Bad malloc.", 2);
	else if (e->error == 2)
	{
		ft_putstr_fd("ls: illegal option -- ", 2);
		ft_putchar_fd(e->bad_char, 2);
		ft_putchar_fd('\n', 2);
		ft_putstr_fd(SHORT_H, 2);
		ft_putstr_fd(LONG_H, 2);
		ft_putendl_fd(FILE_H, 2);
	}
	else if (e->error == 3)
	{
		ft_putstr_fd("ls: illegal option -- ", 2);
		ft_putstr_fd(argv[e->i - 1] + 2, 2);
		ft_putchar_fd('\n', 2);
		ft_putstr_fd(SHORT_H, 2);
		ft_putstr_fd(LONG_H, 2);
		ft_putendl_fd(FILE_H, 2);
	}
}
