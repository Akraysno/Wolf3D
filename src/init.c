/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 10:22:53 by gauffret          #+#    #+#             */
/*   Updated: 2017/06/19 10:22:53 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	restart(t_env *e)
{
	e->sound = 0;
	e->color_set = 0;
	e->first_draw = 1;
	e->dirx = -1;
	e->diry = 0;
	e->planx = 0;
	e->plany = 0.66;
	e->rotspeed = 0.08;
	e->movespeed = 0.5;
	e->score = 0;
	e->i_weapon = 1;
	e->i_sprites = 0;
	e->end_game = 0;
	e->posx = e->sav_posx;
	e->posy = e->sav_posy;
	e->ammo[0] = 1;
	e->ammo[1] = 99;
	e->ammo[2] = 99;
	e->ammo[3] = 99;
	system(AUDIO_OFF);
	run_put_map(e);
}

void	init_nb(t_img *img, t_env *e)
{
	int		height;
	int		width;

	if (!(img->nb[0] = mlx_xpm_file_to_image(e->mlx, IMG_0, &width, &height)))
		missing_img(e);
	if (!(img->nb[1] = mlx_xpm_file_to_image(e->mlx, IMG_1, &width, &height)))
		missing_img(e);
	if (!(img->nb[2] = mlx_xpm_file_to_image(e->mlx, IMG_2, &width, &height)))
		missing_img(e);
	if (!(img->nb[3] = mlx_xpm_file_to_image(e->mlx, IMG_3, &width, &height)))
		missing_img(e);
	if (!(img->nb[4] = mlx_xpm_file_to_image(e->mlx, IMG_4, &width, &height)))
		missing_img(e);
	if (!(img->nb[5] = mlx_xpm_file_to_image(e->mlx, IMG_5, &width, &height)))
		missing_img(e);
	if (!(img->nb[6] = mlx_xpm_file_to_image(e->mlx, IMG_6, &width, &height)))
		missing_img(e);
	if (!(img->nb[7] = mlx_xpm_file_to_image(e->mlx, IMG_7, &width, &height)))
		missing_img(e);
	if (!(img->nb[8] = mlx_xpm_file_to_image(e->mlx, IMG_8, &width, &height)))
		missing_img(e);
	if (!(img->nb[9] = mlx_xpm_file_to_image(e->mlx, IMG_9, &width, &height)))
		missing_img(e);
	if (!(img->inf = mlx_xpm_file_to_image(e->mlx, IMG_INF, &width, &height)))
		missing_img(e);
}

t_img	*create_image2(t_env *e, t_img *img, int height, int width)
{
	if (!(img->board = mlx_xpm_file_to_image(e->mlx, \
									IMG_BOARD, &width, &height)))
		missing_img(e);
	if (!(img->sky = mlx_xpm_file_to_image(e->mlx, \
									IMG_SKY, &width, &height)))
		missing_img(e);
	if (!(img->end = mlx_xpm_file_to_image(e->mlx, \
									IMG_GO, &width, &height)))
		missing_img(e);
	if (!(img->menu1 = mlx_xpm_file_to_image(e->mlx, IMG_RES, \
									&width, &height)))
		missing_img(e);
	if (!(img->menu2 = mlx_xpm_file_to_image(e->mlx, IMG_QUI, \
									&width, &height)))
		missing_img(e);
	if (!(img->start = mlx_xpm_file_to_image(e->mlx, IMG_STR, \
									&width, &height)))
		missing_img(e);
	return (img);
}

t_img	*create_image(t_env *e, long int x, long int y)
{
	t_img	*img;
	int		nb_bits;
	int		len_line;
	int		endian;

	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		quit_malloc_error(e, 5);
	img->img = mlx_new_image(e->mlx, x, y);
	img->img_data = mlx_get_data_addr(img->img, &nb_bits, &len_line, &endian);
	img = create_image2(e, img, 0, 0);
	img->nb = malloc(sizeof(void *) * 10);
	init_nb(img, e);
	init_weapon(img, e);
	return (img);
}

void	game_over(t_env *e)
{
	e->end_game = 1;
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->img->end, 150, 250);
	mlx_do_sync(e->mlx);
}
