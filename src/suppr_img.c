/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suppr_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 10:18:36 by gauffret          #+#    #+#             */
/*   Updated: 2017/06/19 10:18:37 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	supp_all_img2(t_env *e, int i)
{
	if (e && e->img && e->img->shades)
		mlx_destroy_image(e->mlx, e->img->shades);
	while (++i < 8)
		if (e && e->img && e->img->sprites && e->img->sprites[i])
			mlx_destroy_image(e->mlx, e->img->sprites[i]);
	if (e && e->img && e->img->sprites)
		mlx_destroy_image(e->mlx, e->img->sprites);
	if (e && e->img && e->img->inf)
		mlx_destroy_image(e->mlx, e->img->inf);
	if (e && e->ammo)
		ft_memdel((void **)e->ammo);
	if (e && e->img && e->img->w_sprites)
		ft_memdel((void **)e->img->w_sprites);
	if (e && e->img && e->img->h_sprites)
		ft_memdel((void **)e->img->h_sprites);
	if (e && e->img)
		ft_memdel((void **)e->img);
}

void	supp_all_img(t_env *e)
{
	int		i;

	i = -1;
	if (e && e->img && e->img->img)
		mlx_destroy_image(e->mlx, e->img->img);
	if (e && e->img && e->img->board)
		mlx_destroy_image(e->mlx, e->img->board);
	if (e && e->img && e->img->end)
		mlx_destroy_image(e->mlx, e->img->end);
	if (e && e->img && e->img->sky)
		mlx_destroy_image(e->mlx, e->img->sky);
	while (++i < 10)
		if (e && e->img && e->img->nb && e->img->nb[i])
			mlx_destroy_image(e->mlx, e->img->nb[i]);
	i = -1;
	if (e && e->img && e->img->nb)
		mlx_destroy_image(e->mlx, e->img->nb);
	while (++i < 4)
		if (e && e->img && e->img->shades && e->img->shades[i])
			mlx_destroy_image(e->mlx, e->img->shades[i]);
	supp_all_img2(e, -1);
}
