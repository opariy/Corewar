/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 12:44:37 by ymushet           #+#    #+#             */
/*   Updated: 2017/10/25 12:44:44 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_init_f(void)
{
	g_f[0] = &ft_live;
	g_f[1] = &ft_ld;
	g_f[2] = &ft_st;
	g_f[3] = &ft_add;
	g_f[4] = &ft_sub;
	g_f[5] = &ft_xor_and_or;
	g_f[6] = &ft_xor_and_or;
	g_f[7] = &ft_xor_and_or;
	g_f[8] = &ft_zjmp;
	g_f[9] = &ft_ldi;
	g_f[10] = &ft_sti;
	g_f[11] = &ft_fork;
	g_f[12] = &ft_lld;
	g_f[13] = &ft_lldi;
	g_f[14] = &ft_lfork;
	g_f[15] = &ft_aff;
}

void		ft_dump(char *addr)
{
	int		i;

	i = -1;
	while (++i < MEM_SIZE)
	{
		ft_printf("%.2x ", (unsigned char)addr[i]);
		if ((i + 1) % 64 == 0)
			ft_printf("\n");
	}
}

void		ft_print_winner(void)
{
	ft_putstr("Contestant ");
	ft_putnbr(g_dt.last_live->number);
	ft_putstr(", \"");
	ft_putstr((char *)g_dt.last_live->prog_name);
	ft_putstr("\", has won !\n");
}

int			main(int argc, char **argv)
{
	if (argc < 2)
		ft_error("Wrong corewar arguments\n");
	else
	{
		ft_init_global();
		ft_init_f();
		ft_parse_args(0, argv, 1, NULL);
		g_dt.count_processes = g_dt.count_players;
		ft_sort_player();
		g_dt.map = ft_create_map(g_dt.player_g, g_dt.count_players);
		g_dt.process_g = ft_create_proceses(g_dt.player_g);
		g_dt.last_live = g_dt.player_g;
		if (g_dt.visual == 1)
		{
			init_ncurses();
			print_map();
		}
		ft_game_cycle();
	}
	if (g_dt.visual == 0 && g_dt.dump > 0)
		ft_dump((char *)g_dt.map[0]);
	if (g_dt.visual == 0 && g_dt.dump == -1)
		ft_print_winner();
	return (0);
}
