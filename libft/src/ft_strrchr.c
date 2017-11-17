/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:23:55 by gauffret          #+#    #+#             */
/*   Updated: 2016/11/09 13:28:39 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	char			*str;
	unsigned long	i;

	str = (char *)s;
	i = 0;
	while (str[i])
		i++;
	while (i != 0)
	{
		if (str[i] == c)
			return (str + i);
		i--;
	}
	if (str[0] == c)
		return (str);
	return (0);
}
