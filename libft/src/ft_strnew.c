/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:30:25 by gauffret          #+#    #+#             */
/*   Updated: 2016/11/16 11:45:49 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	int		len;

	len = (int)size;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	ft_bzero(str, len + 1);
	return (str);
}
