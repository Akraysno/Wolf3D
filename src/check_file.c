/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 11:36:32 by gauffret          #+#    #+#             */
/*   Updated: 2017/05/31 11:36:35 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

/*
** Conditions de map valide :
** - Map carree
** - Bordures avec X
** - Murs definis par 1
** - Emplacements vides definis par .
** - 1 placement de personmage avec 0 avec 8 cases vides autour
** - 1 Sortie avec 2 avec 3 mur colles contre elle
** - Les lignes de commentaires commencent par #
*/

static int	**fill_map(int **map, char *line, t_env *e, int nb_line)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (line && line[i])
	{
		if (line[i] == '0' || line[i] == '.' || line[i] == 'X' \
							|| line[i] == '1' || line[i] == '2')
		{
			map[nb_line][j] = line[i];
			j++;
		}
		else if (line && line[i] && line[i] != ' ')
			quit_error_map(map, e, 1);
		i++;
	}
	return (map);
}

static int	**create_map(int **map, int len, t_env *e)
{
	int		i;

	e->map->width = len;
	e->map->height = len;
	map = (int **)malloc(sizeof(int *) * len);
	if (!map)
		quit_error_map(map, e, 2);
	i = 0;
	while (i < len)
	{
		map[i] = (int *)malloc(sizeof(int) * len);
		if (!map[i])
			quit_error_map(map, e, 2);
		i++;
	}
	return (map);
}

static int	**modif_map(int **map, char *line, t_env *e, int len)
{
	int		i;

	i = 0;
	if (line && line[0] && line[0] == 'X')
	{
		if (e->map->line == e->map->height && e->map->line != 0 \
												&& e->map->height != 0)
			quit_error_map(map, e, 3);
		while (line && line[i])
		{
			((line[i] != ' ') ? (len++) : (0));
			i++;
		}
		if (!map)
			map = create_map(map, len, e);
		if (len != e->map->width)
			quit_error_map(map, e, 4);
		map = fill_map(map, line, e, e->map->line);
		e->map->line++;
	}
	else if (line && line[0] && line[0] == '#')
		return (map);
	else if (line && line[0])
		quit_error_map(map, e, 1);
	return (map);
}

static int	**read_file(char *file, t_env *e)
{
	char	*line;
	int		fd;
	int		ret;
	int		**map;

	map = NULL;
	fd = open(file, O_RDWR);
	if (fd < 0)
	{
		perror(file);
		quit_error(e, 5);
	}
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (ret == -1)
			quit_error(e, 5);
		if (!line)
			quit_error(e, 3);
		map = modif_map(map, line, e, 0);
		ft_strdel(&line);
	}
	return (map);
}

int			**check_file(char *file, t_env *e)
{
	int	**map;

	map = NULL;
	if (ft_strcmp(&file[ft_strlen(file) - 5], ".wolf") != 0)
		quit_error_map(map, e, 11);
	e->map->line = 0;
	e->map->col = 0;
	e->map->width = 0;
	e->map->height = 0;
	e->map->map = NULL;
	map = read_file(file, e);
	if (e->map->line != e->map->height)
		quit_error_map(map, e, 5);
	e->map->line = 0;
	e->map->col = 0;
	verif_map(map, e);
	return (map);
}
