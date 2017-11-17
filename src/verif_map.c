/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:38:19 by gauffret          #+#    #+#             */
/*   Updated: 2017/05/31 14:38:20 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

int		verif_map4(int **map, t_env *e, int i, int j)
{
	int		cmpt;

	cmpt = 0;
	if (map[i][j] == '2')
	{
		if (map[i - 1][j] == '1' || map[i - 1][j] == 'X')
			cmpt++;
		if (map[i + 1][j] == '1' || map[i + 1][j] == 'X')
			cmpt++;
		if (map[i][j - 1] == '1' || map[i][j - 1] == 'X')
			cmpt++;
		if (map[i][j + 1] == '1' || map[i][j + 1] == 'X')
			cmpt++;
		if (cmpt != 3)
			quit_error_map(map, e, 10);
		return (1);
	}
	return (0);
}

int		verif_map3(int **map, t_env *e, int i, int j)
{
	if (map[i][j] == '0')
	{
		if (i == 1 || j == 1 || i == e->map->width - 2 || \
			j == e->map->height - 2 || map[i - 1][j - 1] != '.' || \
			map[i - 1][j] != '.' || map[i - 1][j + 1] != '.' || \
			map[i][j - 1] != '.' || map[i][j + 1] != '.' || \
			map[i + 1][j - 1] != '.' || map[i + 1][j] != '.' || \
			map[i + 1][j + 1] != '.')
			quit_error_map(map, e, 7);
		e->posx = i;
		e->posy = j;
		return (1);
	}
	return (0);
}

void	verif_map2(int **map, t_env *e, int i, int j)
{
	if (i == 0 || j == 0 || i == e->map->width - 1 || j == e->map->height - 1)
		if (map[i][j] != 'X')
			quit_error_map(map, e, 6);
	if ((i > 0 && i < e->map->width - 1) && (j > 0 && j < e->map->height - 1))
		if (map[i][j] == 'X')
			quit_error_map(map, e, 6);
}

void	verif_map(int **map, t_env *e)
{
	int		i;
	int		j;
	int		nb_player;
	int		nb_end;

	i = 0;
	j = 0;
	nb_player = 0;
	nb_end = 0;
	while (map && map[i] && i < e->map->width)
	{
		while (map && map[i] && map[i][j] && j < e->map->height)
		{
			verif_map2(map, e, i, j);
			nb_player += verif_map3(map, e, i, j);
			nb_end += verif_map4(map, e, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	if (nb_player != 1)
		quit_error_map(map, e, 8);
	if (nb_end != 1)
		quit_error_map(map, e, 9);
}
