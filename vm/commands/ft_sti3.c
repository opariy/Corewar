/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 01:52:40 by ymushet           #+#    #+#             */
/*   Updated: 2017/10/30 01:54:37 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_take_args(t_process *process, int i, int command)
{
	process->mem_addres = ft_increment_index(process);
	process->args[0] = command;
	process->args[1] = g_dt.map[0][process->mem_addres] >> 6;
	process->args[2] = (g_dt.map[0][process->mem_addres]) << 2;
	process->args[2] = ((unsigned char)process->args[2]) >> 6;
	process->args[3] = g_dt.map[0][process->mem_addres] << 4;
	process->args[3] = ((unsigned char)process->args[3]) >> 6;
	i = 0;
	while (++i < 4)
	{
		if (process->args[i] == REG_CODE)
			process->args[i] = g_dt.map[0][ft_increment_index(process)] - 1;
		else if (process->args[i] == DIR_CODE)
		{
			if (command == 2 || command == 6 || command == 7 ||
command == 8 || command == 13)
				process->args[i] = ft_take_args_2(process, 4);
			else
				process->args[i] = ft_take_args_2(process, 2);
		}
		else if (process->args[i] == IND_CODE)
			process->args[i] = ft_take_args_2(process, 2);
	}
	ft_increment_index(process);
}

int		ft_get_ind(int value)
{
	int result;

	result = (g_dt.map[0][ft_get_value(value)] << 24) |
(g_dt.map[0][ft_get_value(value + 1)] << 16) |
(g_dt.map[0][ft_get_value(value + 2)] << 8) |
g_dt.map[0][ft_get_value(value + 3)];
	return (result);
}
