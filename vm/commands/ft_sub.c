/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 19:53:07 by opariy            #+#    #+#             */
/*   Updated: 2017/10/22 19:53:09 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void		ft_sub(t_process *p)
{
	if (g_dt.map[0][ft_get_value(p->mem_addres + 1)] == 84)
	{
		ft_take_args(p, 0, g_dt.map[0][p->mem_addres]);
		if (p->args[1] >= 0 && p->args[1] <= REG_NUMBER && p->args[2] >= 0
			&& p->args[2] <= REG_NUMBER && p->args[3] >= 0 &&
				p->args[3] <= REG_NUMBER)
		{
			p->regs[p->args[3]] = p->regs[p->args[1]] - p->regs[p->args[2]];
			if (p->regs[p->args[3]] == 0)
				p->cary = 1;
			else
				p->cary = 0;
		}
	}
	else
		ft_increment_index(p);
	ft_bzero(p->args, 16);
}
