/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kill_processes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 22:43:37 by ymushet           #+#    #+#             */
/*   Updated: 2017/10/29 22:49:47 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		ft_kill_head(void)
{
	t_process	*h;

	h = g_dt.process_g;
	while (h != NULL && h->alive == 0)
	{
		g_dt.process_g = g_dt.process_g->next;
		free(h);
		g_dt.count_processes--;
		h = g_dt.process_g;
	}
}

void			ft_kill_processes(void)
{
	t_process	*h;
	t_process	*prev;

	ft_kill_head();
	h = g_dt.process_g;
	prev = NULL;
	while (h != NULL)
	{
		while (h != NULL && h->alive != 0)
		{
			prev = h;
			h->alive = 0;
			h = h->next;
		}
		if (h == NULL)
			return ;
		prev->next = h->next;
		free(h);
		g_dt.count_processes--;
		h = prev->next;
	}
}
