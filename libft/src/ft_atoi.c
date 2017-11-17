/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:49:42 by gauffret          #+#    #+#             */
/*   Updated: 2016/11/15 14:03:38 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_atoi(const char *nptr)
{
	int i;
	int neg;
	int num;

	i = 0;
	neg = 1;
	num = 0;
	while (((nptr[i] >= 9) && (nptr[i] <= 13)) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '-')
		neg = -1;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
		i++;
	while ((nptr[i] >= '0') && (nptr[i] <= '9'))
	{
		num = (num * 10) + (nptr[i] - '0');
		i++;
	}
	return (num * neg);
}
