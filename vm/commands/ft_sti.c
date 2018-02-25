/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 16:15:35 by opariy            #+#    #+#             */
/*   Updated: 2017/10/30 01:52:12 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int		ft_get_value(int ind)
{
	int result;

	if (ind < 0)
	{
		while (ind < 0)
			ind += MEM_SIZE;
		result = ind;
	}
	else if (ind >= MEM_SIZE)
		result = ind % MEM_SIZE;
	else
		result = ind;
	return (result);
}

void	ft_write_bold(int num, int start, int end)
{
	int i;

	i = -1;
	while (++i < end)
		g_dt.map[2][ft_get_value(start + i)] = (unsigned char)(-num);
}

void	ft_write_col(int num, int address)
{
	g_dt.map[1][ft_get_value(address)] = (unsigned char)(num + 64);
	g_dt.map[1][ft_get_value(address + 1)] = (unsigned char)(num + 64);
	g_dt.map[1][ft_get_value(address + 2)] = (unsigned char)(num + 64);
	g_dt.map[1][ft_get_value(address + 3)] = (unsigned char)(num + 64);
}

int		ft_increment_index(t_process *process)
{
	process->mem_addres = (ft_get_value(process->mem_addres + 1)) % MEM_SIZE;
	return (process->mem_addres);
}

int		ft_take_args_2(t_process *process, int a)
{
	int res;

	if (a == 2)
		res = (short)(g_dt.map[0][ft_increment_index(process)] << 8) |
g_dt.map[0][ft_increment_index(process)];
	else
	{
		res = ((g_dt.map[0][ft_increment_index(process)] << 24) |
(g_dt.map[0][ft_increment_index(process)] << 16) |
(g_dt.map[0][ft_increment_index(process)] << 8) |
(g_dt.map[0][ft_increment_index(process)]));
	}
	return (res);
}
