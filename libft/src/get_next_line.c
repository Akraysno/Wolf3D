/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:04:03 by gauffret          #+#    #+#             */
/*   Updated: 2017/02/10 12:10:59 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

/*
** Permet de lancer les action :
** - Lire une ligne sauvegardee sans faire de read (action 1)
** - Lire une ligne sauvegardee si rien n'as ete read et aucune (action 2)
*/

int		get_line(t_gnl *link, int action, char **line)
{
	char	*tmp_str;
	char	*tmp;

	if (action == 1)
		tmp_str = ft_strchr(link->str, END_LINE);
	if (action == 1)
		if (tmp_str && tmp_str[0] == END_LINE)
		{
			link->len = (ft_strlen(link->str) - ft_strlen(tmp_str));
			*line = ft_strsub(link->str, 0, link->len);
			tmp = ft_strsub(tmp_str, 1, ft_strlen(tmp_str) - 1);
			ft_strdel(&link->str);
			link->str = ft_strsub(tmp, 0, ft_strlen(tmp));
			ft_strdel(&tmp);
			return (1);
		}
	if (action == 2 && (link->end = 1))
	{
		*line = ft_strsub(link->str, 0, ft_strlen(link->str));
		ft_strdel(&link->str);
		return (1);
	}
	return (0);
}

/*
** Fonction pour normee get_read_file()
** lance les actions necessaire pour chaque read fait
*/

int		get_read_loop(t_gnl *link, char *buf, char **line)
{
	char	*tmp_str;
	char	*tmp;

	link->str = ft_concat(link->str, buf);
	tmp_str = ft_strchr(link->str, END_LINE);
	link->len = 0;
	if (tmp_str && tmp_str[0] == END_LINE)
	{
		link->len = (ft_strlen(link->str) - ft_strlen(tmp_str));
		*line = ft_strsub(link->str, 0, link->len);
		tmp = ft_strsub(tmp_str, 1, ft_strlen(tmp_str) - 1);
		free(link->str);
		link->str = NULL;
		link->str = ft_strsub(tmp, 0, ft_strlen(tmp));
		ft_strdel(&tmp);
		return (1);
	}
	return (0);
}

/*
** Fonction qui permet de savoir quelle action faire :
** - Lire une ligne sauvegardee sans faire de read
** - faire un read si aucune ligne trouvee dans la sauvegarde
** - Lire une ligne dans la sauvegarde si rien n'as ete read et aucune
** ligne trouvee (fin de ligne == '\0')
*/

int		get_read_file(int fd, char **line, t_gnl *link)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];

	link->len = 0;
	ret = 0;
	if (link && link->end == 0 && link->str != NULL)
		if (get_line(link, 1, line) == 1)
			return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) && link && link->end == 0)
	{
		if (ret == -1 || !line)
			return (-1);
		buf[ret] = '\0';
		if (get_read_loop(link, buf, line) == 1)
			return (1);
	}
	if (link && link->str && ft_strlen(link->str) && link->len == 0 && ret == 0)
		if (get_line(link, 2, line) == 1)
			return (1);
	return (0);
}

/*
** Permet de trouver le bon maillon
** Ou de creer un maillon si aucun n'est trouve
*/

t_gnl	*gnl_lst(t_gnl **chain, int fd, t_gnl *link)
{
	t_gnl	*new;

	if (!*chain && (link = (t_gnl *)malloc(sizeof(t_gnl))))
	{
		link->str = NULL;
		link->end = 0;
		link->fd = fd;
		link->next = NULL;
		link->prev = NULL;
		*chain = link;
	}
	link = *chain;
	while (link->fd != fd && link->next)
		link = link->next;
	if (link->fd != fd && (new = (t_gnl *)malloc(sizeof(t_gnl))))
	{
		new->str = NULL;
		new->end = 0;
		new->fd = fd;
		new->next = NULL;
		link->next = new;
		new->prev = link;
		link = new;
	}
	return (link);
}

/*
** Fonction qui permet de lancer toutes les autres
** END_LINE => caractere qui designe la fin de la ligne
** RET_LEN premet de retourner la taille de line s'il est egal a 1
*/

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*chain;
	t_gnl			*link;
	int				ret;

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	link = NULL;
	link = gnl_lst(&chain, fd, link);
	ret = get_read_file(fd, line, link);
	if (link && (ret < 1 || link->end == 1))
	{
		if (link->prev && link->next)
			link->prev->next = link->next;
		if (link->prev && link->next)
			link->next->prev = link->prev;
		if (!link->prev)
			chain = link->next;
		if (link->prev && !link->next)
			link->prev->next = NULL;
		ft_strdel(&link->str);
		ft_memdel((void **)&link);
	}
	return ((RET_LEN == 1 && ret == 1) ? (ft_strlen(*line)) : (ret));
}
