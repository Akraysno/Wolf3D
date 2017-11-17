/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 16:14:28 by gauffret          #+#    #+#             */
/*   Updated: 2016/11/28 14:27:41 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_size(int n)
{
	int		rtn;

	rtn = 1;
	while (n /= 10)
		rtn++;
	return (rtn);
}

char			*ft_itoa(int n)
{
	char	*rtn;
	int		n_tmp;
	int		len;

	n_tmp = n;
	len = ft_size(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == 2147483647)
		return (ft_strdup("2147483647"));
	if (n == (-2147483648))
		return (ft_strdup("-2147483648"));
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
