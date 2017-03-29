/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_h_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 04:32:22 by kaosu             #+#    #+#             */
/*   Updated: 2016/01/21 22:59:51 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

void		h_add_space(t_env **e, char *line, size_t *cpt)
{
	short	len;

	len = 6;
	if ((*e)->form->dev == 1)
	{
		while (len != 0)
		{
			line[*cpt] = ' ';
			*cpt += 1;
			len -= 1;
		}
	}
}

static void	h_copy_size(size_t size, size_t rest, char *line, size_t *cpt)
{
	char	*tmp;
	int		len;

	if (rest != -1 && rest > 511)
		size += 1;
	if ((tmp = ft_itoa(size)) != NULL)
	{
		len = 3 - ft_nbrlen(size);
		while (len-- > 0)
		{
			line[*cpt] = ' ';
			*cpt += 1;
		}
		l_copy_number(line, tmp, cpt);
		free(tmp);
		tmp = NULL;
	}
}

static void	h_copy_float_size(size_t size, size_t rest, char *line, size_t *cpt)
{
	size_t	tmp;

	rest *= 100;
	tmp = rest / 1024;
	if ((tmp % 10) > 4)
		rest = (tmp / 10) + 1;
	else
		rest = tmp / 10;
	if (rest == 10)
	{
		size += 1;
		rest = 0;
	}
	if (size == 10)
		h_copy_size(size, rest, line, cpt);
	else
	{
		line[*cpt] = size + 48;
		*cpt += 1;
		line[*cpt] = '.';
		*cpt += 1;
		line[*cpt] = rest + 48;
		*cpt += 1;
	}
}

static void	h_copy_unit_suffixe(size_t i, char *line, size_t *cpt)
{
	if (i == 0)
		line[*cpt] = 'B';
	if (i == 1)
		line[*cpt] = 'K';
	if (i == 2)
		line[*cpt] = 'M';
	if (i == 3)
		line[*cpt] = 'G';
	if (i == 4)
		line[*cpt] = 'T';
	if (i == 5)
		line[*cpt] = 'P';
	if (i > 5)
		line[*cpt] = '$';
}

void		h_convert_size(t_env **e, t_tree **tree, char *line, size_t *cpt)
{
	size_t	i;
	size_t	rest;
	size_t	size;

	i = 0;
	rest = -1;
	size = (*tree)->t_stat.st_size;
	while (size > 999)
	{
		rest = size % 1024;
		size /= 1024;
		i++;
	}
	if (size > 9 || rest == -1)
		h_copy_size(size, rest, line, cpt);
	else
		h_copy_float_size(size, rest, line, cpt);
	h_copy_unit_suffixe(i, line, cpt);
	*cpt += 1;
}
