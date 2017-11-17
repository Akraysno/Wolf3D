/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:03:57 by gauffret          #+#    #+#             */
/*   Updated: 2017/02/10 12:10:40 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"

# define BUFF_SIZE 42
# define END_LINE '\n'
# define RET_LEN 0

typedef struct		s_gnl
{
	char			*str;
	int				end;
	int				len;
	int				fd;
	struct s_gnl	*next;
	struct s_gnl	*prev;
}					t_gnl;

int					get_next_line(const int fd, char **line);

#endif
