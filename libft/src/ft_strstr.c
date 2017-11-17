/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:41:49 by gauffret          #+#    #+#             */
/*   Updated: 2016/11/15 12:08:29 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strstr(const char *meule_de_foin, const char *aiguille)
{
	char			*meule;
	char			*aigui;
	unsigned long	i;
	unsigned long	j;
	unsigned long	len;

	meule = (char *)meule_de_foin;
	aigui = (char *)aiguille;
	len = ft_strlen(aigui);
	i = 0;
	j = 0;
	if (((meule[i] == 0) && (aigui[i] == 0)) || (aigui[i] == 0))
		return (meule);
	while (meule[i])
	{
		while ((meule[i + j] == aigui[j]) && meule[i + j] && aigui[j])
		{
			if (j == len - 1)
				return (meule + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
