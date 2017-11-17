/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:23:51 by gauffret          #+#    #+#             */
/*   Updated: 2016/11/28 14:27:57 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_nbwords(const char *s, char c)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (*s)
	{
		if (i == 1 && *s == c)
			i = 0;
		if (i == 0 && *s != c)
		{
			i = 1;
			res++;
		}
		s++;
	}
	return (res);
}

static int		ft_len(const char *s, char c)
{
	int		rtn;

	rtn = 0;
	while (*s != c && *s != '\0')
	{
		rtn++;
		s++;
	}
	return (rtn);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**rtn;
	size_t	i;
	size_t	nbwords;

	i = 0;
	if (s == NULL)
		return (NULL);
	nbwords = ft_nbwords(s, c);
	rtn = (char **)malloc(sizeof(rtn) * (nbwords + 1));
	if (rtn == NULL)
		return (NULL);
	while (nbwords > 0)
	{
		while (*s == c && *s != '\0')
			s++;
		rtn[i] = ft_strsub(s, 0, ft_len(s, c));
		if (rtn[i] == NULL)
			return (NULL);
		s += ft_len(s, c);
		i++;
		nbwords--;
	}
	rtn[i] = NULL;
	return (rtn);
}
