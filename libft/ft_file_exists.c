/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_exists.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaosu <kaosu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 12:42:08 by kaosu             #+#    #+#             */
/*   Updated: 2015/12/15 12:52:59 by kaosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_file_exists(const char *filename)
{
	FILE *file;

	if ((file = fopen(filename, "r")))
	{
		fclose(file);
		return (1);
	}
	return (0);
}
