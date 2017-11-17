/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 11:37:21 by gauffret          #+#    #+#             */
/*   Updated: 2017/02/10 12:12:46 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strtolower(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}
