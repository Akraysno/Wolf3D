/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:55:49 by gauffret          #+#    #+#             */
/*   Updated: 2016/11/07 12:26:50 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned long	i;
	char			*mem;
	const char		*cpy;

	i = 0;
	mem = dest;
	cpy = src;
	while (i < n)
	{
		mem[i] = cpy[i];
		i++;
	}
	return (mem);
}
