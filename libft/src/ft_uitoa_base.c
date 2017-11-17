/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 11:19:25 by gauffret          #+#    #+#             */
/*   Updated: 2017/02/10 15:04:26 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*create_base(char *char_base, int base)
{
	int i;

	i = 0;
	while (i < base)
	{
		if (i > 9)
			char_base[i] = 'A' + i - 10;
		else
			char_base[i] = i + '0';
		i++;
	}
	char_base[i] = '\0';
	return (char_base);
}

static char	*convert_value(char *c_base, int base, unsigned int value, \
							char *char_value)
{
	int				i;
	char			*str;
	unsigned int	reste;

	reste = 0;
	if (value <= 0)
		return (ft_strdup("0"));
	while (reste < value)
	{
		str = ft_strnew(((char_value) ? (ft_strlen(char_value)) : (0)) + 1);
		if (char_value && (i = -1))
		{
			str[0] = '\0';
			while (char_value[++i])
				str[i + 1] = char_value[i];
			ft_strdel(&char_value);
		}
		reste = value % base;
		value /= base;
		str[0] = c_base[reste];
		reste = 0;
		char_value = ft_strdup(str);
		ft_strdel(&str);
	}
	return (char_value);
}

char		*ft_uitoa_base(unsigned int value, int base)
{
	char	*char_base;
	char	*char_value;

	if (base < 2 || base > 16)
		return (0);
	char_base = (char *)malloc(sizeof(char) * (base + 1));
	if (!char_base)
		return (NULL);
	char_value = NULL;
	char_base = create_base(char_base, base);
	if (base == 10)
		char_value = ft_uitoa(value);
	else
		char_value = convert_value(char_base, base, value, char_value);
	return (char_value);
}
