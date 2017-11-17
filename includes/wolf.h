/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 11:59:49 by gauffret          #+#    #+#             */
/*   Updated: 2017/02/02 12:00:46 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <openGL/gl.h>
# include <stdio.h>
# include <pthread.h>
# include <key_mlx.h>
# include "/System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/X.h"

# define S_KNIFE	"afplay ./resources/Sound/Knife.wav &>/dev/null &"
# define S_PIST		"afplay ./resources/Sound/Pistol.wav &>/dev/null &"
# define S_MITR		"afplay ./resources/Sound/MachineGun.wav &>/dev/null &"
# define S_MACH		"afplay ./resources/Sound/GatlingGun.wav &>/dev/null &"
# define S_ALLRIGHT	"afplay ./resources/Sound/AllRight!.wav &>/dev/null &"
# define S_YEAH		"afplay ./resources/Sound/Yeeeah!.wav &>/dev/null &"
# define BUTTON		"afplay ./resources/Sound/MenuToggle.wav &>/dev/null &"
# define AUDIO_OFF	"killall afplay &>/dev/null"

# define IMG_0 			"./resources/img/HUD/0.xpm"
# define IMG_1 			"./resources/img/HUD/1.xpm"
# define IMG_2 			"./resources/img/HUD/2.xpm"
# define IMG_3 			"./resources/img/HUD/3.xpm"
# define IMG_4 			"./resources/img/HUD/4.xpm"
# define IMG_5 			"./resources/img/HUD/5.xpm"
# define IMG_6 			"./resources/img/HUD/6.xpm"
# define IMG_7 			"./resources/img/HUD/7.xpm"
# define IMG_8 			"./resources/img/HUD/8.xpm"
# define IMG_9 			"./resources/img/HUD/9.xpm"
# define IMG_INF		"./resources/img/HUD/infinity.xpm"
# define IMG_BOARD		"./resources/img/HUD/board.xpm"
# define IMG_SKY		"./resources/img/sky.xpm"
# define IMG_RES		"./resources/img/menu1.xpm"
# define IMG_QUI		"./resources/img/menu2.xpm"
# define IMG_STR		"./resources/img/start_screen.xpm"
# define IMG_GO			"./resources/img/game_over_coin.xpm"
# define IMG_PIST_S		"./resources/img/HUD/pist_shade.xpm"
# define IMG_PIST_R		"./resources/img/Weapons/de_rest.xpm"
# define IMG_PIST_F		"./resources/img/Weapons/de_fire.xpm"
# define IMG_MITR_S		"./resources/img/HUD/mitr_shade.xpm"
# define IMG_MITR_R		"./resources/img/Weapons/ak_rest.xpm"
# define IMG_MITR_F		"./resources/img/Weapons/ak_fire.xpm"
# define IMG_MACH_S		"./resources/img/HUD/mach_shade.xpm"
# define IMG_MACH_R		"./resources/img/Weapons/mach_02_5.xpm"
# define IMG_MACH_F		"./resources/img/Weapons/mach_03_5.xpm"
# define IMG_KNIFE_S	"./resources/img/HUD/knife_shade.xpm"
# define IMG_KNIFE_R	"./resources/img/Weapons/knife_02_7.xpm"
# define IMG_KNIFE_F	"./resources/img/Weapons/knife_03_8.xpm"

# define W_WIDTH 800
# define W_HEIGHT 800
# define NORTH 0x00CBA321
# define SOUTH 0x00A90707
# define EAST 0x0022B109
# define WEST 0x001C36C4
# define GROUND 0x00686C5E
# define TOP 0x00393939
# define COLOR 0x00CBA321

typedef struct		s_map
{
	int				**map;
	int				width;
	int				height;
	int				line;
	int				col;
}					t_map;

typedef struct		s_img
{
	void			*img;
	char			*img_data;
	void			*end;
	char			*board;
	void			*sky;
	void			*menu1;
	void			*menu2;
	void			*start;
	void			**nb;
	void			**shades;
	void			**sprites;
	int				*w_sprites;
	int				*h_sprites;
	int				*inf;
	int				i_nb;
	int				nb_bits;
	int				len_line;
	int				endian;
	int				w_img;
	int				h_img;
}					t_img;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				width;
	int				sav_width;
	int				height;
	int				sav_height;
	int				sound;
	int				score;
	int				i_weapon;
	int				i_sprites;
	int				*ammo;
	int				end_game;
	double			posx;
	double			posy;
	double			sav_posx;
	double			sav_posy;
	double			dirx;
	double			diry;
	double			planx;
	double			plany;
	double			camerax;
	double			cameray;
	double			ray_posx;
	double			ray_posy;
	double			ray_dirx;
	double			ray_diry;
	int				mapx;
	int				mapy;
	double			side_distx;
	double			side_disty;
	double			delta_distx;
	double			delta_disty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				wall_color;
	double			rotspeed;
	double			movespeed;
	int				quit;
	int				restart;
	int				start;
	int				first_draw;
	int				color_set;
	struct s_map	*map;
	struct s_img	*img;
}					t_env;

int					quit(t_env *e);
void				quit_error(t_env *e, int action);
void				quit_error_map(int **map, t_env *e, int action);
void				quit_malloc_error(t_env *e, int err);
void				supp_map(t_env *e);
void				supp_all_img(t_env *e);
void				restart(t_env *e);
void				game_over(t_env *e);
void				suppr_map(int **map, int height);
int					gere_key(int key, t_env *e);
int					repeat_key(int key, t_env *e);
int					gere_mouse(int code, int x, int y, t_env *e);
t_img				*create_image(t_env *e, long int x, long int y);
void				draw_center(t_env *var, int deg, int i, int j);
void				draw_multithread(t_env *e);
void				run_put_map(t_env *e);
void				draw(t_env *e, int x);
void				draw_bot(t_env *e);
void				draw_weapon(t_env *e);
int					**check_file(char *str, t_env *e);
void				verif_map(int **map, t_env *e);
void				draw_wall(int x, t_env *e);
void				draw_gate(int x, t_env *e, int color, int y);
void				init_weapon(t_img *img, t_env *e);
void				missing_img(t_env *e);
void				shoot(t_env *e);

#endif
