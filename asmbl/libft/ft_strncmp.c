/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:38:35 by rbozhko           #+#    #+#             */
/*   Updated: 2016/12/25 16:49:49 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	i = 0;
	while ((str1[i] != '\0' || str2[i] != '\0') && i < n)
	{
		if ((unsigned char)str1[i] > (unsigned char)str2[i])
			return (*(unsigned char*)(str1 + i) - *(unsigned char*)(str2 + i));
		else if ((unsigned char)str1[i] < (unsigned char)str2[i])
			return (*(unsigned char*)(str1 + i) - *(unsigned char*)(str2 + i));
		i++;
	}
	return (0);
}
