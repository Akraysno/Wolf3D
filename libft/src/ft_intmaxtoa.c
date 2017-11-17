/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmaxtoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 13:10:45 by gauffret          #+#    #+#             */
/*   Updated: 2017/02/28 13:10:48 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_size(intmax_t n)
{
	intmax_t	rtn;

	rtn = 1;
	while (n /= 10)
		rtn++;
	return (rtn);
}

char			*ft_intmaxtoa(intmax_t n)
{
	char		*rtn;
	intmax_t	n_tmp;
	intmax_t	len;

	n_tmp = n;
	len = ft_size(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == 9223372036854775807 * -1 - 1)
		return (ft_strdup("-9223372036854775808"));
	if (n < 0)
		n_tmp = -n;
	if (n < 0)
		len++;
	rtn = ft_strnew(len);
	if (rtn == NULL)
		return (NULL);
	rtn[--len] = n_tmp % 10 + '0';
	while (n_tmp /= 10)
		rtn[--len] = n_tmp % 10 + '0';
	if (n < 0)
		rtn[0] = '-';
	return (rtn);
}
