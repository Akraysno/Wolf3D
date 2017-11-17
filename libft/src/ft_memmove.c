/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 11:45:31 by gauffret          #+#    #+#             */
/*   Updated: 2016/11/16 14:03:10 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*mem;
	size_t			i;

	mem = (unsigned char *)src;
	dst = dest;
	if (mem == dst)
		return (0);
	if (mem < dst)
	{
		i = n + 1;
		while (--i != 0)
		{
			dst[i - 1] = mem[i - 1];
		}
	}
	else
	{
		i = -1;
		while (++i < n)
		{
			dst[i] = mem[i];
		}
	}
	return (dst);
}
