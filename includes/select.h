/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 16:39:42 by dromansk          #+#    #+#             */
/*   Updated: 2019/09/03 20:33:07 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H
# include "termcap.h"
# include "sel_structs.h"
# define ULINE "\e[4m"
# define REV "\e[7m"
# define REV_ULINE "\e[4;7m"
# define NORM "\e[m"

t_sel_list		*make_list(int ac, char **av);
t_select		*make_select(t_sel_list *options, termios_p *termios);

void			print_opts(t_select *sel);
void			columnize_opts(t_select *sel);

#endif
