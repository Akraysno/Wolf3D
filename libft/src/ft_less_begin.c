/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_less_begin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 10:04:26 by gauffret          #+#    #+#             */
/*   Updated: 2017/02/10 12:11:39 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_less_begin(char *str, int start)
{
	char	*tmp;

	tmp = ft_strsub(str, start, ft_strlen(str) - start);
	ft_strdel(&str);
	str = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (str);
}
