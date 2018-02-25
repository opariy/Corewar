/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 22:34:34 by ymushet           #+#    #+#             */
/*   Updated: 2017/10/29 22:35:59 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_free_player(t_player **player)
{
	t_player	*p;

	p = *player;
	ft_strdel((char**)&p->prog_name);
	ft_strdel((char**)&p->comment);
	ft_strdel((char**)&p->instructions);
	free(p);
	*player = NULL;
}
