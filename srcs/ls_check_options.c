/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_check_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:09:14 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/20 22:51:42 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

static bool	check_short(t_env **e, char opt, bool check)
{
	if (ft_strchr((*e)->opt, opt))
		return (1);
	else if (check == 1)
		return (1);
	else
		return (0);
}

static bool	check_long(t_env **e, char *opt, bool check)
{
	if (ft_strstr((*e)->l_opt, opt))
		return (1);
	else if (check == 1)
		return (1);
	else
		return (0);
}

static void	check_short_option(t_env **e)
{
	(*e)->opt_s->a = check_short(e, 'a', (*e)->opt_s->a);
	(*e)->opt_s->f = check_short(e, 'f', false);
	(*e)->opt_s->h = check_short(e, 'h', (*e)->opt_s->h);
	(*e)->opt_s->l = check_short(e, 'l', false);
	(*e)->opt_s->r = check_short(e, 'r', (*e)->opt_s->r);
	(*e)->opt_s->s = check_short(e, 's', false);
	(*e)->opt_s->t = check_short(e, 't', false);
	(*e)->opt_s->rec = check_short(e, 'R', (*e)->opt_s->rec);
}

static void	check_long_option(t_env **e)
{
	(*e)->opt_s->a = check_long(e, "all", (*e)->opt_s->a);
	(*e)->opt_s->h = check_long(e, "human-readable", (*e)->opt_s->h);
	(*e)->opt_s->rec = check_long(e, "recursive", (*e)->opt_s->rec);
	(*e)->opt_s->r = check_long(e, "reverse", (*e)->opt_s->r);
}

void		ls_check_options(t_env **e)
{
	if ((*e)->opt != NULL)
		check_short_option(e);
	if ((*e)->l_opt != NULL)
		check_long_option(e);
}
