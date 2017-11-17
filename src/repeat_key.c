/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 12:15:31 by gauffret          #+#    #+#             */
/*   Updated: 2017/06/21 12:15:32 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

static void	repeat_key4(int key, t_env *e, double old_dirx, double old_planx)
{
	if (key == KEY_ARROW_RIGHT || key == KEY_D)
	{
		e->dirx = e->dirx * cos(-e->rotspeed) - e->diry * sin(-e->rotspeed);
		e->diry = old_dirx * sin(-e->rotspeed) + e->diry * cos(-e->rotspeed);
		e->planx = e->planx * cos(-e->rotspeed) - e->plany * sin(-e->rotspeed);
		e->plany = old_planx * sin(-e->rotspeed) + e->plany * cos(-e->rotspeed);
	}
	if (key == KEY_ARROW_LEFT || key == KEY_A)
	{
		e->dirx = e->dirx * cos(e->rotspeed) - e->diry * sin(e->rotspeed);
		e->diry = old_dirx * sin(e->rotspeed) + e->diry * cos(e->rotspeed);
		e->planx = e->planx * cos(e->rotspeed) - e->plany * sin(e->rotspeed);
		e->plany = old_planx * sin(e->rotspeed) + e->plany * cos(e->rotspeed);
	}
	if (key == KEY_ARROW_UP || key == KEY_W || key == KEY_ARROW_DOWN || \
		key == KEY_S || key == KEY_ARROW_RIGHT || key == KEY_D || \
		key == KEY_ARROW_LEFT || key == KEY_A)
	{
		e->score++;
		run_put_map(e);
	}
}

static void	repeat_key3(int key, t_env *e)
{
	if (key == KEY_ARROW_DOWN || key == KEY_S)
	{
		if (e->map->map[(int)(e->posx - e->dirx * \
								e->movespeed)][(int)(e->posy)] == '.' || \
			e->map->map[(int)(e->posx - e->dirx * \
								e->movespeed)][(int)(e->posy)] == '0' || \
			e->map->map[(int)(e->posx - e->dirx * \
								e->movespeed)][(int)(e->posy)] == '2')
			e->posx -= e->dirx * e->movespeed;
		if (e->map->map[(int)(e->posx)][(int)(e->posy - \
								e->diry * e->movespeed)] == '.' || \
			e->map->map[(int)(e->posx)][(int)(e->posy - \
								e->diry * e->movespeed)] == '0' || \
			e->map->map[(int)(e->posx)][(int)(e->posy - \
								e->diry * e->movespeed)] == '2')
			e->posy -= e->diry * e->movespeed;
	}
}

static void	repeat_key2(int key, t_env *e)
{
	if (key == KEY_ARROW_UP || key == KEY_W)
	{
		if (e->map->map[(int)(e->posx)][(int)(e->posy + \
										e->diry * e->movespeed)] == '.' || \
			e->map->map[(int)(e->posx)][(int)(e->posy + \
										e->diry * e->movespeed)] == '0' || \
			e->map->map[(int)(e->posx)][(int)(e->posy + \
										e->diry * e->movespeed)] == '2')
			e->posy += e->diry * e->movespeed;
		if (e->map->map[(int)(e->posx + e->dirx * \
								e->movespeed)][(int)(e->posy)] == '.' || \
			e->map->map[(int)(e->posx + e->dirx * \
								e->movespeed)][(int)(e->posy)] == '0' || \
			e->map->map[(int)(e->posx + e->dirx * \
								e->movespeed)][(int)(e->posy)] == '2')
			e->posx += e->dirx * e->movespeed;
	}
}

int			repeat_key(int key, t_env *e)
{
	double	old_dirx;
	double	old_planx;

	old_planx = e->planx;
	old_dirx = e->dirx;
	if (!e->end_game && !e->quit && !e->start)
	{
		repeat_key2(key, e);
		repeat_key3(key, e);
		repeat_key4(key, e, old_dirx, old_planx);
		if (e->map->map[(int)e->posx][(int)(e->posy)] == '2')
			game_over(e);
	}
	return (1);
}
