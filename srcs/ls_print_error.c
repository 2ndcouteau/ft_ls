/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 11:56:50 by kaosu             #+#    #+#             */
/*   Updated: 2016/01/20 22:55:44 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

void	ls_print_error(int error, char *name)
{
	if (error == 1)
	{
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd(name, 2);
		ft_putendl_fd(": No such file or directory", 2);
	}
	else if (error == 2)
	{
		ft_putstr_fd("ls: ", 2);
		perror(name);
	}
}
