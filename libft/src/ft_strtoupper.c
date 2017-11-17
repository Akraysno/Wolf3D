/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 11:37:30 by gauffret          #+#    #+#             */
/*   Updated: 2017/02/10 11:37:31 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strtoupper(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}
