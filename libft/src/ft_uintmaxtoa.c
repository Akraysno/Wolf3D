/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintmaxtoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 13:10:24 by gauffret          #+#    #+#             */
/*   Updated: 2017/02/28 13:10:26 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_size(uintmax_t n)
{
	uintmax_t	rtn;

	rtn = 1;
	while (n /= 10)
		rtn++;
	return (rtn);
}

char			*ft_uintmaxtoa(uintmax_t n)
{
	char		*rtn;
	uintmax_t	n_tmp;
	uintmax_t	len;

	n_tmp = n;
	len = ft_size(n);
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
