/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:36:23 by gauffret          #+#    #+#             */
/*   Updated: 2016/11/16 10:54:50 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	len_d;
	size_t	i;
	char	*source;

	source = (char *)src;
	len_d = ft_strlen(dest);
	i = 0;
	while ((i < n) && source[i])
	{
		dest[len_d + i] = source[i];
		i++;
	}
	dest[len_d + i] = '\0';
	return (dest);
}
