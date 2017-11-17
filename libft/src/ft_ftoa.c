/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 12:46:01 by gauffret          #+#    #+#             */
/*   Updated: 2017/02/10 12:46:03 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static unsigned int		calc_size(double *nbr)
{
	int		x;

	x = 0;
	while (*nbr > 1)
	{
		*nbr /= 10;
		x++;
	}
	return (x);
}

static char				*ft_ftoa_int(double nbr, unsigned int size, \
									unsigned int x)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew((x == 0) ? (1) : (x));
	if (x < size)
	{
		if (x == 0)
		{
			str[i++] = '0';
			size--;
		}
		else
		{
			while (x--)
			{
				nbr = (nbr - (int)(nbr)) * 10;
				str[i++] = (int)(nbr) + '0';
				size--;
			}
		}
	}
	else
		ft_strdel(&str);
	return (str);
}

static char				*ft_ftoa_float(double nbr, unsigned int size, \
									unsigned int len_prec, unsigned int x)
{
	int		i;
	char	*str;

	str = ft_strnew((len_prec > 0) ? (len_prec + 1) : (0));
	i = 0;
	if (x < size)
		while (x--)
			nbr = (nbr - (int)(nbr)) * 10;
	if (len_prec < size)
	{
		if (len_prec > 0 && (str[i++] = '.'))
			while (len_prec--)
			{
				nbr = (nbr - (int)(nbr)) * 10;
				str[i++] = (int)(nbr + 0.1) + '0';
				size--;
			}
		str[i] = '\0';
	}
	else
		ft_strdel(&str);
	return (str);
}

char					*ft_ftoa_neg(double *nbr)
{
	char	*str;

	if (*nbr < 0)
	{
		str = ft_strnew(1);
		str[0] = '-';
		*nbr *= -1;
	}
	else
	{
		str = ft_strnew(0);
	}
	return (str);
}

char					*ft_ftoa(double nbr, unsigned int len_prec, char *str)
{
	unsigned int	size;
	unsigned int	x;
	int				i;
	char			*str2;

	i = -1;
	str = ft_ftoa_neg(&nbr);
	x = calc_size(&nbr);
	size = ((len_prec > 0) ? (len_prec + 1) : (0)) + x + 1;
	str2 = ft_ftoa_int(nbr, size, x);
	str = ((str) ? (ft_concat(str, str2)) : ft_strdup(str2));
	ft_strdel(&str2);
	str2 = ft_ftoa_float(nbr, size, len_prec, x);
	if (str2 && str)
		str = ft_concat(str, str2);
	ft_strdel(&str2);
	while (str[++i])
		if (!ft_isdigit(str[i]) && str[i] != '.' && (i != 1 && str[i] != '-'))
		{
			str[i] -= 10;
			i = -1;
		}
	return (str);
}
