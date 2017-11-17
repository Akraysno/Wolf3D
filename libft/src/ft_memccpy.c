/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:48:14 by gauffret          #+#    #+#             */
/*   Updated: 2016/11/08 10:43:41 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
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
		if (cpy[i] == c)
		{
			return (mem + i + 1);
		}
		i++;
	}
	return (0);
}
