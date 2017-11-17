/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 13:43:33 by gauffret          #+#    #+#             */
/*   Updated: 2017/05/23 13:43:35 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

int		gere_mouse(int code, int x, int y, t_env *e)
{
	(void)x;
	if (!e->end_game && code == 1 && y > 0 && e->ammo[e->i_weapon] > 0)
		if (!e->start && !e->quit)
			shoot(e);
	return (1);
}
