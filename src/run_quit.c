/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_quit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 13:30:52 by gauffret          #+#    #+#             */
/*   Updated: 2017/05/23 13:30:52 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	supp_map(t_env *e)
{
	int		i;

	i = 0;
	while (e->map && e->map->map && e->map->map[i])
	{
		ft_memdel((void **)e->map->map[i]);
		i++;
	}
	ft_memdel((void **)e->map->map);
	ft_memdel((void **)e->map);
}

void	quit_malloc_error(t_env *e, int err)
{
	ft_putstr_fd("./wolf3d : malloc error.\n", 2);
	system(AUDIO_OFF);
	if (err == 3)
		ft_memdel((void **)&e->map);
	if (err == 2 || err == 3)
		ft_memdel((void **)&e);
	exit(1);
}

void	run_put_map(t_env *e)
{
	if (!e->start)
	{
		draw(e, -1);
		if (e->i_weapon != 0)
			draw_center(e, 0, (e->width / 2) - 11, (e->height / 2) - 11);
		mlx_clear_window(e->mlx, e->win);
		mlx_put_image_to_window(e->mlx, e->win, e->img->sky, -400, -200);
		mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, 0);
		draw_bot(e);
		draw_weapon(e);
		mlx_do_sync(e->mlx);
		if (e->first_draw)
			system(S_ALLRIGHT);
		if (e->first_draw)
			e->first_draw = 0;
	}
	else
		mlx_put_image_to_window(e->mlx, e->win, e->img->start, 0, 0);
}

void	quit_error(t_env *e, int action)
{
	if (action == 1)
		ft_putstr_fd("./wolf3d : Not enough arguments\n", 2);
	if (action == 2)
		ft_putstr_fd("./wolf3d : Invalid map\n", 2);
	if (action == 3)
		ft_putendl_fd("./wolf3d : Missing data", 2);
	if (action == 5)
		ft_putendl_fd("./wolf3d : No such map", 2);
	if (action == 2 || action == 5 || action == 3)
		ft_memdel((void **)&e);
	exit(1);
}

int		quit(t_env *e)
{
	system(AUDIO_OFF);
	if (e && e->map)
		suppr_map(e->map->map, e->map->height);
	if (e && e->img)
		mlx_destroy_image(e->mlx, e->img->img);
	if (e && e->mlx && e->win)
	{
		mlx_clear_window(e->mlx, e->win);
		mlx_destroy_window(e->mlx, e->win);
	}
	if (e)
		ft_memdel((void **)&e);
	exit(1);
}
