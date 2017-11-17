/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:26:36 by gauffret          #+#    #+#             */
/*   Updated: 2016/11/16 11:47:50 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*result;
	size_t	i;

	if (s)
	{
		i = 0;
		str = (char *)s;
		result = (char *)malloc(sizeof(char) * (len + 1));
		if (!result)
			return (NULL);
		while (i < len)
		{
			result[i] = str[start + i];
			i++;
		}
		result[len] = '\0';
		return (result);
	}
	return (0);
}
