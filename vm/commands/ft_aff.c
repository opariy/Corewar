/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 14:14:42 by opariy            #+#    #+#             */
/*   Updated: 2017/10/20 14:14:44 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_aff(t_process *p)
{
	ft_increment_index(p);
	if (g_dt.map[0][p->mem_addres] == 64)
	{
		p->args[1] = g_dt.map[0][ft_increment_index(p)];
		if (p->args[1] >= 0 && p->args[1] <= REG_NUMBER && g_dt.visual != 1)
		{
			ft_putstr("Aff: ");
			ft_putchar((char)(p->regs[p->args[1] - 1] % 256));
			ft_putstr("\n");
		}
	}
	ft_bzero(p->args, 16);
}
