/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_init_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 20:55:19 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/20 23:13:19 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/ft_ls.h>

static void	ls_init_opt(t_env **e)
{
	(*e)->opt_s->a = 0;
	(*e)->opt_s->f = 0;
	(*e)->opt_s->h = 0;
	(*e)->opt_s->l = 0;
	(*e)->opt_s->r = 0;
	(*e)->opt_s->s = 0;
	(*e)->opt_s->t = 0;
	(*e)->opt_s->rec = 0;
}

void		opt_init_env(t_env **e)
{
	(*e)->i = 1;
	(*e)->count = 0;
	(*e)->opt = NULL;
	(*e)->l_opt = NULL;
	(*e)->nb_arg = 0;
	(*e)->s_arg = NULL;
	(*e)->bad_char = 0;
	(*e)->error = 0;
	(*e)->mark = 1;
	(*e)->mark_b = 0;
	(*e)->mark_c = 0;
	(*e)->form = (t_form*)malloc(sizeof(t_form));
	(*e)->opt_s = (t_opt*)malloc(sizeof(t_opt));
	(*e)->time_n = time(NULL);
	ls_init_opt(e);
	l_init_form(e);
}
