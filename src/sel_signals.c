/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sel_signals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 15:54:24 by dromansk          #+#    #+#             */
/*   Updated: 2019/09/03 19:55:00 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	win_resize(int sig)
{
	t_select	*sel;
	if (sig = SIGWINCH)
	{
		ft_do_caps("cl");
		sel = store_sel(NULL);
		print_opts(sel);
	}
}

void	sel_signals(void)
{
	signal(SIGWINCH, win_resize);
	signal(SIGKILL, sel_kill);
	signal(SIGSTOP, sel_stop);
	signal(SIGCONT, sel_cont);
}
