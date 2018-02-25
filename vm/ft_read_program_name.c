/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_program_name.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:48:53 by opariy            #+#    #+#             */
/*   Updated: 2017/10/29 18:48:54 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	ft_read_program_name(int fd, t_player *player)
{
	ssize_t	r;
	ssize_t	len;

	len = PROG_NAME_LENGTH + 1;
	while ((len % 4) != 0)
		len++;
	r = read(fd, player->prog_name, len);
	if (r != len)
	{
		ft_free_player(&player);
		close(fd);
		ft_error("Not valid program name\n");
	}
	return (1);
}
