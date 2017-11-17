/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:59:46 by gauffret          #+#    #+#             */
/*   Updated: 2016/11/16 11:33:49 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_d;
	size_t	len_s;
	char	*source;
	size_t	i;

	i = 0;
	source = (char *)src;
	while (dst[i] && (i < size))
		i++;
	len_d = i;
	len_s = ft_strlen(source);
	while (source[i - len_d] && ((i < size - 1)))
	{
		dst[i] = src[i - len_d];
		i++;
	}
	if (len_d < size)
		dst[i] = '\0';
	return (len_d + len_s);
}
