/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 12:48:29 by gauffret          #+#    #+#             */
/*   Updated: 2017/05/24 12:48:30 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	init_draw2(t_env *e, int action)
{
	if (e->ray_diry >= 0 && action == 1)
		e->stepy = 1;
	if (e->ray_diry >= 0 && action == 1)
		e->side_disty = (e->mapy + 1.0 - e->ray_posy) * e->delta_disty;
	if (action == 2)
	{
		if (e->side_distx < e->side_disty)
		{
			e->side_distx += e->delta_distx;
			e->mapx += e->stepx;
			e->side = 0;
		}
		else
		{
			e->side_disty += e->delta_disty;
			e->mapy += e->stepy;
			e->side = 1;
		}
	}
}

void	init_draw(t_env *e, int x)
{
	e->camerax = 2 * x / (double)e->width - 1;
	e->ray_posx = e->posx;
	e->ray_posy = e->posy;
	e->ray_dirx = e->dirx + e->planx * e->camerax;
	e->ray_diry = e->diry + e->plany * e->camerax;
	e->mapx = (int)e->ray_posx;
	e->mapy = (int)e->ray_posy;
	e->delta_distx = sqrt(1 + (e->ray_diry * e->ray_diry) / (e->ray_dirx * \
														e->ray_dirx));
	e->delta_disty = sqrt(1 + (e->ray_dirx * e->ray_dirx) / (e->ray_diry * \
														e->ray_diry));
	e->hit = 0;
	if (e->ray_dirx < 0)
		e->stepx = -1;
	if (e->ray_dirx < 0)
		e->side_distx = (e->ray_posx - e->mapx) * e->delta_distx;
	if (e->ray_dirx >= 0)
		e->stepx = 1;
	if (e->ray_dirx >= 0)
		e->side_distx = (e->mapx + 1.0 - e->ray_posx) * e->delta_distx;
	if (e->ray_diry < 0)
		e->stepy = -1;
	if (e->ray_diry < 0)
		e->side_disty = (e->ray_posy - e->mapy) * e->delta_disty;
}

void	calc_var_draw(t_env *e)
{
	if (e->side == 0)
		e->perpwalldist = (e->mapx - e->ray_posx + \
											(1 - e->stepx) / 2) / e->ray_dirx;
	else
		e->perpwalldist = (e->mapy - e->ray_posy + \
											(1 - e->stepy) / 2) / e->ray_diry;
	e->line_height = (int)(e->height / ((e->perpwalldist == 0) \
							? (1) : (e->perpwalldist)));
	e->draw_start = -e->line_height / 2 + e->height / 2;
	e->draw_end = e->line_height / 2 + e->height / 2;
	if (e->draw_end >= e->height)
		e->draw_end = e->height - 1;
	e->wall_color = COLOR;
	if (e->side == 0 && e->color_set == 0)
		e->wall_color = (e->stepx == -1 ? NORTH : SOUTH);
	if (e->side == 0 && e->color_set == 1)
		e->wall_color = 0x00FFFFFF;
	if (e->side != 0 && e->color_set == 0)
		e->wall_color = (e->stepy == -1 ? EAST : WEST);
	if (e->side != 0 && e->color_set == 1)
		e->wall_color = 0x00000000;
}

void	draw(t_env *e, int x)
{
	while (++x < e->width)
	{
		init_draw(e, x);
		init_draw2(e, 1);
		while (e->hit == 0)
		{
			init_draw2(e, 2);
			if (e->map->map && (e->map->map[e->mapx][e->mapy] == '1' || \
								e->map->map[e->mapx][e->mapy] == 'X'))
				e->hit = 1;
			if (e->map->map && (e->map->map[e->mapx][e->mapy] == '2'))
				e->hit = 2;
		}
		calc_var_draw(e);
		if (e->hit == 1)
		{
			e->draw_start = ((e->draw_start < 0) ? (0) : (e->draw_start));
			draw_wall(x, e);
		}
		if (e->hit == 2)
			draw_gate(x, e, e->wall_color, 0);
	}
}
