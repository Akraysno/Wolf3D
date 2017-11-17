/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:53:54 by gauffret          #+#    #+#             */
/*   Updated: 2016/11/17 09:57:32 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*cont;

	cont = (void *)content;
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	if (!cont)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content = malloc(content_size);
		if (!new->content)
			return (NULL);
		ft_memcpy(new->content, cont, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
