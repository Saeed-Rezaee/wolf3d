/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 18:19:35 by elopukh           #+#    #+#             */
/*   Updated: 2018/06/02 18:19:38 by elopukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "./minilibx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <pthread.h>
# include "../libft/libft.h"
# include <errno.h>

# define DIST 100
# define H_WIN 1000
# define W_WIN 1000
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define NUMSPRITES 24
# define NUMTEX	29

typedef struct		s_sprite
{
	double			x;
	double			y;
	int				t;
	int				f;
}					t_sprite;

typedef struct
{
	int				h;
	int				w;
	int				points;
	int				open;
	void			*im;
	int				udiv;
	int				vdiv;
	double			vmove;
	double			spritex;
	double			spritey;
	double			invdet;
	double			transformx;
	double			transformy;
	int				spritescreenx;
	int				spriteheight;
	int				spritewidth;
	int				drawstartx;
	int				drawstarty;
	int				drawendy;
	int				drawendx;
	t_sprite		sprites[NUMSPRITES];
	int				i;
	int				x;
	int				y;
	int				y1;
	double			floorx_wall;
	double			floory_wall;
	double			dist_wall;
	double			dist_player;
	double			current_dist;
	int				spriteorder[NUMSPRITES];
	double			spritedistance[NUMSPRITES];
	int				mapx;
	int				mapy;
	int				texw;
	int				texh;
	int				colour;
	double			buffer[W_WIN + 100];
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				size_line;
	int				bpp;
	int				endian;
	int				t_min;
	int				t_max;
	char			*img;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			wallx;
	int				texnum;
	int				texx;
	int				texy;
	int				d;
	double			plane_x;
	double			plane_y;
	double			time;
	double			oldtime;
	double			camera_x;
	double			ray_dirx;
	double			ray_diry;
	double			move_speed;
	int				step_x;
	int				step_y;
	double			deltadist_x;
	int				hit;
	int				side;
	double			sidedist_x;
	double			sidedist_y;
	double			deltadist_y;
	double			perpwalldist;
	double			frame_time;
	double			rot_speed;
	int				stripe;
	int				**map;
	int				*texture[NUMTEX];
	int				*pics;
	double			current_floorx;
	double			current_floory;
	int				movescreen;
	int				floortx;
	int				floorty;
	double			weight;
	int				width;
	int				height;
	int				line_h;
	int				start;
	int				end;
	void			*zast[12];
}					t_window;

int					file_open(char *file);
char				*readff1(char *tmp, char *str);
int					valid(char *str);
void				fill1(t_window *win, char *str, int i, int j);
void				clear_image(t_window *win);
char				**readff(char *file);
int					count_numb(char *str);
void				count_h(char **str, t_window *win);
int					get_matr(char *str, t_window *win);
int					it1(t_window *win);
int					it2(t_window *win);
int					it3(t_window *win);
int					it4(t_window *win);
int					it5(t_window *win);
int					it6(t_window *win);
int					it7(t_window *win);
int					it8(t_window *win);
int					it9(t_window *win);
int					it10(t_window *win);
void				dealkey1(t_window *win, int key);
void				dealkey2(t_window *win, int key);
void				dealkey3(t_window *win, int key);
void				dealkey4(t_window *win, int key);
void				dealkey5(t_window *win, int key);
int					fill_texture(t_window *win);
void				count_wall(t_window *win);
void				calc_step(t_window *win);
void				dda(t_window *win);
void				count_height(t_window *win);
void				counts(t_window *win);
void				pixel_put_img(t_window *win, int x, int y, int colour);
int					game_start(t_window *win);
void				scene1(t_window *win);
void				spritecasting(t_window *win);
void				floorcasting(t_window *win);
void				init_sprites(t_window *win);
void				floorcasting(t_window *win);
void				spritecasting(t_window *win);
void				sorting(int *order, double *dist, int amount);
void				init(t_window *win);
void				initdata(t_window *win);

#endif
