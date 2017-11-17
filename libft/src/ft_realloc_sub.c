/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_sub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 10:13:17 by gauffret          #+#    #+#             */
/*   Updated: 2017/02/08 10:13:20 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_realloc_sub(char **str, int start, int len)
{
	char	*tmp;
	char	*tmp2;

	tmp2 = *str;
	tmp = ft_strsub(tmp2, start, len);
	ft_strdel(&tmp2);
	*str = ft_strdup(tmp);
	ft_strdel(&tmp);
}
