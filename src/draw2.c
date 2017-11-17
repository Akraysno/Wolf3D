/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:30:24 by gauffret          #+#    #+#             */
/*   Updated: 2017/06/07 14:30:30 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	draw_weapon(t_env *e)
{
	if (e->img->sprites[e->i_weapon + 4 * e->i_sprites])
		mlx_put_image_to_window(e->mlx, e->win, e->img->sprites[e->i_weapon + \
		4 * e->i_sprites], e->img->w_sprites[e->i_weapon + 4 * e->i_sprites], \
					e->img->h_sprites[e->i_weapon + 4 * e->i_sprites]);
}

void	draw_bot2(t_env *e)
{
	int		score;

	score = ((e->score > 999999) ? (999999) : (e->score));
	mlx_put_image_to_window(e->mlx, e->win, e->img->shades[e->i_weapon], 623, \
							e->height - 85);
	mlx_put_image_to_window(e->mlx, e->win, e->img->nb[(score / 100000) % 10], \
										115, e->height - 58);
	mlx_put_image_to_window(e->mlx, e->win, e->img->nb[(score / 10000) % 10], \
										136, e->height - 58);
	mlx_put_image_to_window(e->mlx, e->win, e->img->nb[(score / 1000) % 10], \
										157, e->height - 58);
	mlx_put_image_to_window(e->mlx, e->win, e->img->nb[(score / 100) % 10], \
										178, e->height - 58);
	mlx_put_image_to_window(e->mlx, e->win, e->img->nb[(score / 10) % 10], \
										199, e->height - 58);
	mlx_put_image_to_window(e->mlx, e->win, e->img->nb[score % 10], 220, \
										e->height - 58);
}

void	draw_bot(t_env *e)
{
	int		ammo;

	ammo = ((e->ammo[e->i_weapon] > 99) ? (99) : (e->ammo[e->i_weapon]));
	mlx_put_image_to_window(e->mlx, e->win, e->img->board, 0, e->height - 101);
	mlx_put_image_to_window(e->mlx, e->win, e->img->nb[0], 265, e->height - 58);
	mlx_put_image_to_window(e->mlx, e->win, e->img->nb[1], 295, e->height - 58);
	mlx_put_image_to_window(e->mlx, e->win, e->img->nb[1], 420, e->height - 58);
	mlx_put_image_to_window(e->mlx, e->win, e->img->nb[0], 435, e->height - 58);
	mlx_put_image_to_window(e->mlx, e->win, e->img->nb[0], 455, e->height - 58);
	mlx_put_image_to_window(e->mlx, e->win, e->img->nb[0], 40, e->height - 58);
	mlx_put_image_to_window(e->mlx, e->win, e->img->nb[1], 70, e->height - 58);
	draw_bot2(e);
	if (e->i_weapon == 0)
		mlx_put_image_to_window(e->mlx, e->win, e->img->inf, 538, \
								e->height - 48);
	else
	{
		mlx_put_image_to_window(e->mlx, e->win, e->img->nb[ammo / 10], \
								534, e->height - 58);
		mlx_put_image_to_window(e->mlx, e->win, e->img->nb[ammo % 10], \
								556, e->height - 58);
	}
}
