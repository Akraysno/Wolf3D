/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 11:19:16 by gauffret          #+#    #+#             */
/*   Updated: 2017/02/10 11:50:27 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_usize(unsigned int n)
{
	unsigned long	rtn;

	rtn = 1;
	while (n /= 10)
		rtn++;
	return (rtn);
}

char			*ft_uitoa(unsigned int n)
{
	char			*rtn;
	unsigned int	n_tmp;
	unsigned int	len;

	n_tmp = n;
	len = ft_usize(n);
	if (n == 0)
		return (ft_strdup("0"));
	rtn = ft_strnew(len);
	if (rtn == NULL)
		return (NULL);
	rtn[--len] = n_tmp % 10 + '0';
	while (n_tmp /= 10)
		rtn[--len] = n_tmp % 10 + '0';
	return (rtn);
}
