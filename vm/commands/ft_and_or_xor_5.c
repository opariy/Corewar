/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and_or_xor_5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 01:45:39 by opariy            #+#    #+#             */
/*   Updated: 2017/10/30 01:45:41 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_and_or_xor_5(t_process *p, char op, char c)
{
	if (c == -12 && p->args[3] >= 0 && p->args[3] <= REG_NUMBER)
	{
		p->args[1] = ft_take_ind(p->mem_addres - 7 + p->args[1] % IDX_MOD);
		p->args[2] = ft_take_ind(p->mem_addres - 7 + p->args[2] % IDX_MOD);
		if (op == 6)
			(p->regs[p->args[3]] = p->args[1] & p->args[2]);
		if (op == 7)
			(p->regs[p->args[3]] = p->args[1] | p->args[2]);
		if (op == 8)
			(p->regs[p->args[3]] = p->args[1] ^ p->args[2]);
		p->cary = (p->regs[p->args[3]] == 0) ? 1 : 0;
	}
	else if (c == -28 && p->args[3] >= 0 && p->args[3] <= REG_NUMBER)
	{
		p->args[1] = ft_take_ind(p->mem_addres - 9 + p->args[1] % IDX_MOD);
		if (op == 6)
			(p->regs[p->args[3]] = p->args[1] & p->args[2]);
		if (op == 7)
			(p->regs[p->args[3]] = p->args[1] | p->args[2]);
		if (op == 8)
			(p->regs[p->args[3]] = p->args[1] ^ p->args[2]);
		p->cary = (p->regs[p->args[3]] == 0) ? 1 : 0;
	}
}
