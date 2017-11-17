/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 15:45:30 by gauffret          #+#    #+#             */
/*   Updated: 2017/05/31 15:45:30 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	suppr_map(int **map, int height)
{
	int		i;

	i = 0;
	while (map && map[i] && i < height)
	{
		ft_memdel((void **)&map[i]);
		i++;
	}
	ft_memdel((void **)&map);
}

void	suppr_data_error_map(int **map, t_env *e)
{
	suppr_map(map, e->map->height);
	ft_memdel((void **)&e->map);
	ft_memdel((void **)&e);
	exit(1);
}

void	quit_error_map(int **map, t_env *e, int action)
{
	if (action == 1)
		ft_putstr_fd("./wolf3d : Wrong data\n", 2);
	if (action == 2)
		ft_putstr_fd("./wolf3d : Error malloc\n", 2);
	if (action == 3)
		ft_putstr_fd("./wolf3d : Too many lines\n", 2);
	if (action == 4)
		ft_putstr_fd("./wolf3d : Different line length\n", 2);
	if (action == 5)
		ft_putstr_fd("./wolf3d : Not enough lines\n", 2);
	if (action == 6)
		ft_putstr_fd("./wolf3d : Invalid map\n", 2);
	if (action == 7)
		ft_putstr_fd("./wolf3d : Misplaced player\n", 2);
	if (action == 8)
		ft_putstr_fd("./wolf3d : Wrong player number\n", 2);
	if (action == 9)
		ft_putstr_fd("./wolf3d : Wrong gate number\n", 2);
	if (action == 10)
		ft_putstr_fd("./wolf3d : Misplaced gate\n", 2);
	if (action == 11)
		ft_putstr_fd("./wolf3d : Wrong file\n", 2);
	suppr_data_error_map(map, e);
}
