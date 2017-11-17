/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:11:00 by gauffret          #+#    #+#             */
/*   Updated: 2016/11/09 12:45:07 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strcpy(char *dest, const char *src)
{
	char	*srce;
	int		i;
	int		len_s;

	srce = (char *)src;
	i = 0;
	len_s = ft_strlen(srce);
	if ((srce + len_s < dest) || (dest + len_s < srce))
	{
		while (i < len_s)
		{
			dest[i] = srce[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}
