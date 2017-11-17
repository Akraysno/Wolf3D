/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:11:42 by gauffret          #+#    #+#             */
/*   Updated: 2016/11/28 11:24:22 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;
	char			*result;

	if (!s)
		return (NULL);
	str = (char *)s;
	i = 0;
	result = ft_strnew(sizeof(char) * ft_strlen(str));
	if (!result)
		return (NULL);
	if (s && f)
	{
		while (str[i] != '\0')
		{
			result[i] = f(i, str[i]);
			i++;
		}
	}
	result[i] = '\0';
	return (result);
}
