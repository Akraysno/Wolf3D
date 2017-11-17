/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:59:04 by gauffret          #+#    #+#             */
/*   Updated: 2016/11/28 11:19:16 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	i;
	char	*result;

	i = 0;
	if (!s)
		return (NULL);
	str = (char *)s;
	result = ft_strnew(sizeof(char) * ft_strlen(str));
	if (!result)
		return (NULL);
	if (s && f)
	{
		while (str[i] != '\0')
		{
			result[i] = f(str[i]);
			i++;
		}
	}
	result[i] = '\0';
	return (result);
}
