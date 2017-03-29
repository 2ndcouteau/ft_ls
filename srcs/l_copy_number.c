/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_copy_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaosu <kaosu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 14:56:56 by kaosu             #+#    #+#             */
/*   Updated: 2016/01/17 14:57:06 by kaosu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

void	l_copy_number(char *line, char *number, size_t *cpt)
{
	int i;

	i = 0;
	while (number[i] != '\0')
	{
		line[*cpt] = number[i];
		i++;
		*cpt += 1;
	}
}
