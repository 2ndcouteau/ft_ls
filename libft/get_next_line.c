/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 11:54:13 by qrosa             #+#    #+#             */
/*   Updated: 2015/05/06 13:57:31 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_buffer(char **buffer, char **line)
{
	int		i;
	char	*tmp;

	if (!(*buffer))
		return (0);
	i = -1;
	while ((*buffer)[++i])
		if ((*buffer)[i] == '\n')
		{
			*line = ft_strsub(*buffer, 0, i);
			if (!(*line))
				return (-1);
			if (ft_strlen((*buffer) + i + 1))
			{
				tmp = *buffer;
				*buffer = ft_strdup((*buffer) + i + 1);
				if (!(*buffer))
					return (-1);
				free(tmp);
			}
			else
				ft_strdel(buffer);
			return (1);
		}
	return (0);
}

static int		recheck_buffer(int read_bytes, char **buffer, char **line)
{
	if (read_bytes == 0 && *buffer)
	{
		*line = ft_strdup(*buffer);
		if (!(*line))
			return (-1);
		ft_strdel(buffer);
		return (1);
	}
	return (read_bytes);
}

static int		find_new_line(char **buffer, char **line, char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
		{
			str[i] = '\0';
			if (*buffer)
			{
				*line = ft_strjoin(*buffer, str);
				ft_strdel(buffer);
			}
			else
				*line = ft_strdup(str);
			if (!(*line))
				return (-1);
			if (ft_strlen(str + i + 1))
			{
				*buffer = ft_strdup(str + i + 1);
				if (!(*buffer))
					return (-1);
			}
			return (1);
		}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static char		*buffer = NULL;
	char			str[BUFF_SIZE + 1];
	int				read_bytes;
	int				status;
	char			*tmp;

	ft_bzero(str, BUFF_SIZE + 1);
	if (fd < 0 || !line)
		return (-1);
	if ((status = check_buffer(&buffer, line)))
		return (status);
	while ((read_bytes = read(fd, str, BUFF_SIZE)) > 0)
	{
		if ((status = find_new_line(&buffer, line, str)))
			return (status);
		tmp = buffer;
		buffer = buffer ? ft_strjoin(tmp, str) : ft_strdup(str);
		if (!buffer)
			return (-1);
		free(tmp);
		ft_bzero(str, BUFF_SIZE + 1);
	}
	return (recheck_buffer(read_bytes, &buffer, line));
}
