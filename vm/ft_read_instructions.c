/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:47:16 by opariy            #+#    #+#             */
/*   Updated: 2017/10/29 18:47:18 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ft_read_instructions(int fd, t_player *player)
{
	ssize_t r;

	player->instructions = (unsigned char*)ft_strnew(CHAMP_MAX_SIZE + 1);
	r = read(fd, player->instructions, CHAMP_MAX_SIZE + 1);
	if (r != player->player_size)
	{
		ft_free_player(&player);
		close(fd);
		ft_error("Not valid instruction size\n");
	}
	else if (r == player->player_size)
	{
		r = read(fd, NULL, 1);
		if (r != 0)
		{
			ft_free_player(&player);
			close(fd);
			ft_error("Not valid instructions\n");
		}
	}
	return (1);
}
