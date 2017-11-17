/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:45:37 by gauffret          #+#    #+#             */
/*   Updated: 2016/11/10 14:54:16 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlen(const char *str)
{
	unsigned long	i;
	char			*s;

	i = 0;
	s = (char *)str;
	while (s[i])
	{
		i++;
	}
	return (i);
}
