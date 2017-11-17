/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 13:43:28 by gauffret          #+#    #+#             */
/*   Updated: 2017/05/23 13:43:28 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

static void	put_commands(void)
{
	ft_putendl("");
	ft_putendl("  ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	ft_putendl("  ┃                                                 ┃");
	ft_putendl("  ┃  Liste des contôles :                           ┃");
	ft_putendl("  ┃                                                 ┃");
	ft_putendl("  ┃  Mouvements :                                   ┃");
	ft_putendl("  ┃     Avancer                : ↑, w               ┃");
	ft_putendl("  ┃     Reculer                : ↓, s               ┃");
	ft_putendl("  ┃     Tourner vers la gauche : ←, a               ┃");
	ft_putendl("  ┃     Tourner vers la droite : →, d               ┃");
	ft_putendl("  ┃                                                 ┃");
	ft_putendl("  ┃  Armes :                                        ┃");
	ft_putendl("  ┃     Couteau                : 1                  ┃");
	ft_putendl("  ┃     Pistolet               : 2                  ┃");
	ft_putendl("  ┃     Mitraillette           : 3                  ┃");
	ft_putendl("  ┃     Gatling                : 4                  ┃");
	ft_putendl("  ┃                                                 ┃");
	ft_putendl("  ┃  Tirer                     : command gauche     ┃");
	ft_putendl("  ┃                                                 ┃");
	ft_putendl("  ┃  Changer les couleurs      : Etoile (pave num.) ┃");
	ft_putendl("  ┃                                                 ┃");
	ft_putendl("  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}

static void	key_exit(int key, t_env *e)
{
	if (e->quit && e->restart && (key == KEY_ENTER || key == NUM_KEY_ENTER))
	{
		e->quit = 0;
		e->restart = 0;
		restart(e);
	}
	if (e->quit && !e->restart && (key == KEY_ENTER || key == NUM_KEY_ENTER))
		quit(e);
	if (e->quit && (key == KEY_ARROW_DOWN || key == KEY_S) && e->restart)
	{
		e->restart = 0;
		system(BUTTON);
		mlx_put_image_to_window(e->mlx, e->win, e->img->menu2, 0, 0);
	}
	if (e->quit && (key == KEY_ARROW_UP || key == KEY_W) && !e->restart)
	{
		e->restart = 1;
		system(BUTTON);
		mlx_put_image_to_window(e->mlx, e->win, e->img->menu1, 0, 0);
	}
	if (key == KEY_TILD)
		put_commands();
}

static void	change_weapon(int key, t_env *e)
{
	if (!e->end_game && !e->quit && !e->start)
	{
		if ((key == NUM_KEY_1 || key == KEY_1) && e->i_weapon != 0)
			e->i_weapon = 0;
		if ((key == NUM_KEY_2 || key == KEY_2) && e->i_weapon != 1)
			e->i_weapon = 1;
		if ((key == NUM_KEY_3 || key == KEY_3) && e->i_weapon != 2)
			e->i_weapon = 2;
		if ((key == NUM_KEY_4 || key == KEY_4) && e->i_weapon != 3)
			e->i_weapon = 3;
		if (key == NUM_KEY_MUL)
			e->color_set = !e->color_set;
		if (((key == NUM_KEY_1 || key == KEY_1) && e->i_weapon == 0) || \
			((key == NUM_KEY_2 || key == KEY_2) && e->i_weapon == 1) || \
			((key == NUM_KEY_3 || key == KEY_3) && e->i_weapon == 2) || \
			((key == NUM_KEY_4 || key == KEY_4) && e->i_weapon == 3) || \
			(key == NUM_KEY_MUL))
			run_put_map(e);
		if (key == KEY_SPACE)
			system(S_YEAH);
		if (key == KEY_CMD_L)
			shoot(e);
	}
}

int			gere_key(int key, t_env *e)
{
	if (key == 53 && e->quit)
	{
		e->quit = 0;
		e->restart = 0;
		if (!e->end_game)
			run_put_map(e);
		else
			game_over(e);
		return (1);
	}
	key_exit(key, e);
	if (key == 53 && !e->quit)
	{
		e->quit = 1;
		e->restart = 1;
		mlx_put_image_to_window(e->mlx, e->win, e->img->menu1, 0, 0);
		return (1);
	}
	change_weapon(key, e);
	if (e->start && !e->quit && (key == KEY_ENTER || key == NUM_KEY_ENTER))
	{
		e->start = 0;
		run_put_map(e);
	}
	return (1);
}
