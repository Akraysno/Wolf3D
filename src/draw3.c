/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 10:23:04 by gauffret          #+#    #+#             */
/*   Updated: 2017/06/26 10:23:06 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void		draw_wall(int x, t_env *e)
{
	int		y;
	int		top;
	int		bot;

	top = ((e->color_set == 0) ? (TOP) : (0x00FFFFFF));
	bot = ((e->color_set == 0) ? (GROUND) : (0x00FFFFFF));
	y = 0;
	while (y < e->draw_start)
	{
		*(unsigned *)(e->img->img_data + y * e->width * 4 + x * 4) = top;
		y++;
	}
	while (y < e->draw_end)
	{
		*(unsigned *)(e->img->img_data + y * e->width * 4 + x * 4) = \
			e->wall_color;
		y++;
	}
	while (y < e->height - 1)
	{
		*(unsigned *)(e->img->img_data + y * e->width * 4 + x * 4) = bot;
		y++;
	}
}

static void	draw_gate2(int x, t_env *e, int y)
{
	int		bot;

	bot = ((e->color_set == 0) ? (GROUND) : (0x00FFFFFF));
	while (y < e->draw_end)
	{
		*(unsigned *)(e->img->img_data + y * e->width * 4 + x * 4) = 0xFF000000;
		y++;
	}
	while (y < e->height)
	{
		*(unsigned *)(e->img->img_data + y * e->width * 4 + x * 4) = bot;
		y++;
	}
}

void		draw_gate(int x, t_env *e, int color, int y)
{
	int		tmp;
	int		top;

	top = ((e->color_set == 0) ? (TOP) : (0x00FFFFFF));
	while (y < e->draw_start)
	{
		*(unsigned *)(e->img->img_data + y * e->width * 4 + x * 4) = top;
		y++;
	}
	tmp = e->draw_start + ((e->draw_end - e->draw_start) / 7);
	if (y < 0)
		y = 0;
	while (y < tmp && tmp >= 0)
	{
		*(unsigned *)(e->img->img_data + y * e->width * 4 + x * 4) = color;
		y++;
	}
	draw_gate2(x, e, y);
}
