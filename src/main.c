/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 13:26:12 by gauffret          #+#    #+#             */
/*   Updated: 2017/05/23 13:26:13 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	shoot(t_env *e)
{
	e->i_sprites = 1;
	run_put_map(e);
	if (e->i_weapon == 0)
		system(S_KNIFE);
	if (e->i_weapon == 1)
		system(S_PIST);
	if (e->i_weapon == 2)
		system(S_MITR);
	if (e->i_weapon == 3)
		system(S_MACH);
	mlx_do_sync(e->mlx);
	usleep(100000);
	e->score++;
	e->i_sprites = 0;
	if (e->i_weapon != 0)
		e->ammo[e->i_weapon]--;
	run_put_map(e);
}

void	draw_center(t_env *e, int deg, int i, int j)
{
	int	color;
	int x;
	int y;

	color = mlx_get_color_value(e->mlx, 0x00C0C0C0);
	while (deg < 360)
	{
		x = (int)(400 + 7 * cos(deg));
		y = (int)(400 + 7 * sin(deg));
		*(unsigned *)(e->img->img_data + y * e->width * 4 + x * 4) = color;
		deg++;
	}
	while (i++ < 400 + 9)
		if ((i > (400 - 10) && i < (400 - 3)) || (i > (400 + 3) && i < \
																(400 + 10)))
			*(unsigned *)(e->img->img_data + lrint((400 - 1) * \
									e->width * 4.0) + lrint(i * 4.0)) = color;
	while (j++ < 400 + 9)
		if ((j > (400 - 10) && j < (400 - 4)) || \
									(j > (400 + 3) && j < (400 + 9)))
			*(unsigned *)(e->img->img_data + lrint(j * e->width * 4.0) + \
											lrint((400) * 4.0)) = color;
	*(unsigned *)(e->img->img_data + lrint((400 - 1) * e->width * 4.0) + \
											lrint(400 * 4.0)) = color;
}

t_env	*init_env(t_env *e, char *av)
{
	e->width = W_WIDTH;
	e->height = W_HEIGHT;
	e->sav_width = e->width;
	e->sav_height = e->height;
	e->sound = 0;
	e->map = (t_map *)malloc(sizeof(t_map));
	if (!e->map)
		quit_malloc_error(e, 2);
	e->map->map = check_file(av, e);
	if (!e->map->map)
		quit_error(e, 3);
	e->dirx = -1;
	e->diry = 0;
	e->planx = 0;
	e->plany = 0.66;
	e->rotspeed = 0.1;
	e->movespeed = 0.5;
	e->score = 0;
	e->i_weapon = 0;
	e->i_sprites = 0;
	e->mlx = mlx_init();
	e->end_game = 0;
	e->sav_posx = e->posx;
	e->sav_posy = e->posy;
	return (e);
}

int		main(int ac, char **av)
{
	t_env	*e;

	if (ac == 1)
		quit_error(NULL, 1);
	e = (t_env *)malloc(sizeof(t_env));
	if (!e)
		quit_malloc_error(e, 1);
	e = init_env(e, av[1]);
	e->start = 1;
	e->quit = 0;
	e->restart = 0;
	e->first_draw = 1;
	e->color_set = 0;
	system(AUDIO_OFF);
	e->win = mlx_new_window(e->mlx, e->width, e->height, "Wolf3D");
	e->img = create_image(e, e->width, e->height);
	run_put_map(e);
	mlx_hook(e->win, 17, (1L << 17), quit, e);
	mlx_hook(e->win, KEY_PRESS, KEY_PRESS_MASK, repeat_key, e);
	mlx_key_hook(e->win, gere_key, e);
	mlx_mouse_hook(e->win, gere_mouse, e);
	mlx_loop(e->mlx);
	return (1);
}
