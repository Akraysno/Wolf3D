/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 11:46:21 by gauffret          #+#    #+#             */
/*   Updated: 2017/06/16 11:46:22 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	quit_malloc_error_img(t_env *e)
{
	ft_putstr_fd("./wolf3d : malloc error.\n", 2);
	system(AUDIO_OFF);
	supp_map(e);
	supp_all_img(e);
	if (e->mlx && e->win)
	{
		mlx_clear_window(e->mlx, e->win);
		mlx_destroy_window(e->mlx, e->win);
	}
	if (e)
		ft_memdel((void **)&e);
	exit(1);
}

void	missing_img(t_env *e)
{
	(void)e;
	ft_putstr_fd("./wolf3d : image missing.\n", 2);
	quit(e);
}

t_img	*init_weapon3(t_img *img, t_env *e)
{
	int		h;
	int		w;

	img->sprites = malloc(sizeof(void *) * 8);
	if (!img->shades)
		quit_malloc_error_img(e);
	if (!(img->sprites[0] = mlx_xpm_file_to_image(e->mlx, IMG_KNIFE_R, &w, &h)))
		missing_img(e);
	if (!(img->sprites[1] = mlx_xpm_file_to_image(e->mlx, IMG_PIST_R, &w, &h)))
		missing_img(e);
	if (!(img->sprites[2] = mlx_xpm_file_to_image(e->mlx, IMG_MITR_R, &w, &h)))
		missing_img(e);
	if (!(img->sprites[3] = mlx_xpm_file_to_image(e->mlx, IMG_MACH_R, &w, &h)))
		missing_img(e);
	if (!(img->sprites[4] = mlx_xpm_file_to_image(e->mlx, IMG_KNIFE_F, &w, &h)))
		missing_img(e);
	if (!(img->sprites[5] = mlx_xpm_file_to_image(e->mlx, IMG_PIST_F, &w, &h)))
		missing_img(e);
	if (!(img->sprites[6] = mlx_xpm_file_to_image(e->mlx, IMG_MITR_F, &w, &h)))
		missing_img(e);
	if (!(img->sprites[7] = mlx_xpm_file_to_image(e->mlx, IMG_MACH_F, &w, &h)))
		missing_img(e);
	return (img);
}

t_img	*init_weapon2(t_img *img, t_env *e)
{
	int		h;
	int		w;

	img->shades = malloc(sizeof(void *) * 4);
	if (!img->shades)
		quit_malloc_error_img(e);
	if (!(img->shades[0] = mlx_xpm_file_to_image(e->mlx, IMG_KNIFE_S, &w, &h)))
		missing_img(e);
	if (!(img->shades[1] = mlx_xpm_file_to_image(e->mlx, IMG_PIST_S, &w, &h)))
		missing_img(e);
	if (!(img->shades[2] = mlx_xpm_file_to_image(e->mlx, IMG_MITR_S, &w, &h)))
		missing_img(e);
	if (!(img->shades[3] = mlx_xpm_file_to_image(e->mlx, IMG_MACH_S, &w, &h)))
		missing_img(e);
	img = init_weapon3(img, e);
	e->i_weapon = 1;
	e->ammo = (int *)malloc(sizeof(int) * 4);
	if (!img->shades)
		quit_malloc_error_img(e);
	e->ammo[0] = 1;
	e->ammo[1] = 99;
	e->ammo[2] = 99;
	e->ammo[3] = 99;
	return (img);
}

void	init_weapon(t_img *img, t_env *e)
{
	img = init_weapon2(img, e);
	img->w_sprites = (int *)malloc(sizeof(int) * 8);
	if (!img->shades)
		quit_malloc_error_img(e);
	img->w_sprites[0] = 420;
	img->w_sprites[1] = 58;
	img->w_sprites[2] = 58;
	img->w_sprites[3] = 320;
	img->w_sprites[4] = 420;
	img->w_sprites[5] = 58;
	img->w_sprites[6] = 58;
	img->w_sprites[7] = 280;
	img->h_sprites = (int *)malloc(sizeof(int) * 8);
	if (!img->shades)
		quit_malloc_error_img(e);
	img->h_sprites[0] = 594;
	img->h_sprites[1] = 149;
	img->h_sprites[2] = 149;
	img->h_sprites[3] = 589;
	img->h_sprites[4] = 547;
	img->h_sprites[5] = 149;
	img->h_sprites[6] = 149;
	img->h_sprites[7] = 529;
}
