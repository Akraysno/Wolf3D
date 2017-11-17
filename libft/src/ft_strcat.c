/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 09:49:01 by gauffret          #+#    #+#             */
/*   Updated: 2016/11/16 10:51:57 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strcat(char *dest, const char *src)
{
	size_t	i;
	size_t	len_d;
	size_t	len_s;
	char	*source;

	source = (char *)src;
	len_d = ft_strlen(dest);
	len_s = ft_strlen(source);
	i = 0;
	if ((dest == 0) && (src == 0))
		return (0);
	while ((i < len_s) && source[i])
	{
		dest[len_d + i] = source[i];
		i++;
	}
	dest[len_d + i] = '\0';
	return (dest);
}
