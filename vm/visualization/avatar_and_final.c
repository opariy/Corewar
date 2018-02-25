/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avatar_and_final.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 23:35:12 by mkaliber          #+#    #+#             */
/*   Updated: 2017/10/29 23:35:13 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	fgt(char *str)
{
	int i;
	int x;

	i = 0;
	x = g_vh.av_pos_x / 2 - 24;
	while (i <= 48)
	{
		wattron(g_vh.avatar, COLOR_PAIR(P2) | A_BOLD);
		mvwprintw(g_vh.avatar, g_vh.av_pos, x + 1, "%c", '|');
		wattroff(g_vh.avatar, COLOR_PAIR(P2) | A_BOLD);
		wattron(g_vh.avatar, COLOR_PAIR(P2));
		mvwprintw(g_vh.avatar, g_vh.av_pos, x, "%c", str[i]);
		wattroff(g_vh.avatar, COLOR_PAIR(P2));
		i++;
		x++;
		usleep(10000);
		wrefresh(g_vh.avatar);
	}
	wattron(g_vh.avatar, COLOR_PAIR(P4));
	mvwprintw(g_vh.avatar, g_vh.av_pos, x, "%c", ' ');
	wattroff(g_vh.avatar, COLOR_PAIR(P4));
	wrefresh(g_vh.avatar);
	g_vh.av_pos++;
}

void	fgp(char *str)
{
	int i;
	int x;

	i = 0;
	x = g_vh.av_pos_x / 2 - 24;
	while (i <= 48)
	{
		if (str[i] == 32)
			wattron(g_vh.avatar, COLOR_PAIR(AVATARB));
		else
			wattron(g_vh.avatar, COLOR_PAIR(AVATAR));
		mvwprintw(g_vh.avatar, g_vh.av_pos, x, "%c", str[i]);
		if (str[i] == 32)
			wattroff(g_vh.avatar, COLOR_PAIR(AVATARB));
		else
			wattroff(g_vh.avatar, COLOR_PAIR(AVATAR));
		i++;
		x++;
	}
	usleep(50000);
	wrefresh(g_vh.avatar);
	g_vh.av_pos++;
}

void	fgtf(char *str)
{
	int i;
	int x;

	i = 0;
	x = g_vh.av_pos_x / 2 - 15;
	wattroff(g_vh.avatar, COLOR_PAIR(P2));
	wattron(g_vh.avatar, COLOR_PAIR(P2));
	mvwprintw(g_vh.avatar, g_vh.av_pos, x, "%s", str);
	wattroff(g_vh.avatar, COLOR_PAIR(P2));
	i++;
	x++;
	usleep(10000);
	wrefresh(g_vh.avatar);
	g_vh.av_pos++;
}

void	fgpf(char *str)
{
	int i;
	int x;

	i = 0;
	x = g_vh.av_pos_x / 2 - 15;
	while (i <= 30)
	{
		if (str[i] == 32)
			wattron(g_vh.avatar, COLOR_PAIR(AVATARB));
		else
			wattron(g_vh.avatar, COLOR_PAIR(AVATAR));
		mvwprintw(g_vh.avatar, g_vh.av_pos, x, "%c", str[i]);
		if (str[i] == 32)
			wattroff(g_vh.avatar, COLOR_PAIR(AVATARB));
		else
			wattroff(g_vh.avatar, COLOR_PAIR(AVATAR));
		i++;
		x++;
	}
	usleep(50000);
	wrefresh(g_vh.avatar);
	g_vh.av_pos++;
}
