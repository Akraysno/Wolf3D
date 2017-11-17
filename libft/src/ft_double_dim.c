/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_dim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 11:43:56 by gauffret          #+#    #+#             */
/*   Updated: 2016/11/17 14:29:30 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**ft_double_dim(char **tab, int len_dim1, int len_dim2)
{
	int		i;

	i = 0;
	tab = (char **)malloc(len_dim1 * sizeof(char *));
	if (!tab)
		return (NULL);
	while (i < len_dim1)
	{
		tab[i] = (char *)malloc(len_dim2 * sizeof(char *));
		if (!tab[i])
			return (NULL);
		i++;
	}
	return (tab);
}
