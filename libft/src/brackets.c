/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 10:14:06 by gauffret          #+#    #+#             */
/*   Updated: 2017/01/13 10:14:09 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	verif_nb_brackets(char *str)
{
	int nb_a;
	int nb_c;
	int nb_p;
	int i;

	nb_a = 0;
	nb_c = 0;
	nb_p = 0;
	i = -1;
	while (str && str[++i])
	{
		if (str[i] == '[')
			nb_c++;
		if (str[i] == ']')
			nb_c--;
		if (str[i] == '{')
			nb_a++;
		if (str[i] == '}')
			nb_a--;
		if (str[i] == '(')
			nb_p++;
		if (str[i] == ')')
			nb_p--;
	}
	return (((nb_a == 0 && nb_c == 0 && nb_p == 0) ? (1) : (0)));
}

static int	verif_brackets(char *str, int i)
{
	while (str && str[i])
	{
		if (str[i] == '(' && (i = i + verif_brackets(str + i + 1, 0) + 2))
		{
			if (str[i - 1] != ')')
				return (0);
			continue ;
		}
		if (str[i] == '{' && (i = i + verif_brackets(str + i + 1, 0) + 2))
		{
			if (str[i - 1] != '}')
				return (0);
			continue ;
		}
		if (str[i] == '[' && (i = i + verif_brackets(str + i + 1, 0) + 2))
		{
			if (str[i - 1] != ']')
				return (0);
			continue ;
		}
		if (str[i] == ')' || str[i] == '}' || str[i] == ']')
			return (i);
		i++;
	}
	return (1);
}

/*
** return (0) => error
** return (1) => brackets ok
*/

int			brackets(char *str)
{
	if (!verif_nb_brackets(str))
		return (0);
	return (verif_brackets(str, 0));
}
