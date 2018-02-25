/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_coment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:43:21 by opariy            #+#    #+#             */
/*   Updated: 2017/10/29 18:43:22 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ft_read_comment(int fd, t_player *player)
{
	ssize_t r;
	ssize_t len;

	len = COMMENT_LENGTH + 1;
	while ((len % 4) != 0)
		len++;
	r = read(fd, player->comment, len);
	if (r != len)
	{
		ft_free_player(&player);
		close(fd);
		ft_error("Not valid comment\n");
	}
	return (1);
}
