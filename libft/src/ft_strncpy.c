/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:32:03 by gauffret          #+#    #+#             */
/*   Updated: 2016/11/16 10:29:18 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	unsigned char	*srce;
	size_t			i;

	srce = (unsigned char *)src;
	i = 0;
	while ((i < n) && (srce[i] != '\0'))
	{
		dest[i] = srce[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
