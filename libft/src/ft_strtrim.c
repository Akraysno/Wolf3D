/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:14:33 by gauffret          #+#    #+#             */
/*   Updated: 2016/11/28 11:48:33 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strtrim(char const *s)
{
	size_t		min;
	size_t		len;
	size_t		j;

	if (!s)
		return (NULL);
	min = 0;
	j = ft_strlen(s);
	while (s[min] != '\0' && \
			(s[min] == ' ' || s[min] == '\t' || s[min] == '\n'))
		min++;
	while ((j > min) && \
			(s[j - 1] == ' ' || s[j - 1] == '\t' || s[j - 1] == '\n'))
		j--;
	len = j - min;
	return (ft_strsub(s, min, len));
}
