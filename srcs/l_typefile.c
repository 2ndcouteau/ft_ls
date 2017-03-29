/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_typefile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 20:25:20 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/20 22:17:01 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

char	l_typefile_christmas(mode_t mode)
{
	if (mode == S_IFREG)
		return ('-');
	if (mode == S_IFDIR)
		return ('d');
	if (mode == S_IFLNK)
		return ('l');
	if (mode == S_IFSOCK)
		return ('s');
	if (mode == S_IFIFO)
		return ('p');
	if (mode == S_IFBLK)
		return ('b');
	if (mode == S_IFCHR)
		return ('c');
	return ('?');
}
