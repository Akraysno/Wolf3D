/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:35:17 by gauffret          #+#    #+#             */
/*   Updated: 2016/11/15 12:27:11 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*ft_strnstr2(char *str1, char *str2, size_t len)
{
	unsigned long	i;
	unsigned long	j;
	unsigned long	len_s2;

	len_s2 = ft_strlen(str2);
	i = 0;
	j = 0;
	while (str1[i] && (i < len))
	{
		if (str1[i] == str2[0])
		{
			while ((str1[i + j] == str2[j]) && str1[i + j] && ((i + j) < len))
			{
				if (j == len_s2 - 1)
					return (str1 + i);
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (0);
}

char		*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	char			*str1;
	char			*str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	if (str2[0] == 0)
		return (str1);
	return (ft_strnstr2(str1, str2, len));
}
