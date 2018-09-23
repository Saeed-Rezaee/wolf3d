/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 18:43:12 by elopukh           #+#    #+#             */
/*   Updated: 2018/07/06 18:43:13 by elopukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	initdata(t_window *win)
{
	win->udiv = 1;
	win->vdiv = 1;
	win->vmove = 0;
	win->pos_x = 2;
	win->pos_y = 2;
	win->dir_x = -1;
	win->dir_y = 0;
	win->plane_x = 0;
	win->plane_y = 0.66;
	win->points = 0;
	win->size_line = W_WIN;
	win->bpp = 32;
	win->endian = 0;
	win->colour = 265;
	win->texw = 128;
	win->texh = 128;
	win->img =
	mlx_get_data_addr(win->img_ptr, &win->bpp, &win->size_line, &win->endian);
}

int		key_handler(int key, void *p)
{
	t_window *win;

	win = (t_window*)p;
	dealkey1(win, key);
	dealkey2(win, key);
	dealkey3(win, key);
	dealkey4(win, key);
	dealkey5(win, key);
	return (1);
}

int		exit_x(void *par)
{
	par = NULL;
	system("killall afplay");
	exit(1);
	return (0);
}

void	loop(t_window *win)
{
	mlx_hook(win->win_ptr, 2, 1L << 0, key_handler, win);
	mlx_hook(win->win_ptr, 17, 1L << 17, exit_x, win);
	mlx_loop(win->mlx_ptr);
}

int		main(int argc, char **argv)
{
	t_window *win;

	if (argc < 2)
	{
		write(1, "Please, more arguments\n", 23);
		return (0);
	}
	win = (t_window*)malloc(sizeof(t_window));
	init(win);
	init_sprites(win);
	if (!get_matr(argv[1], win) ||
	win->map[(int)win->pos_x][(int)win->pos_y] != 0)
	{
		write(1, "Error map!\n", 11);
		return (0);
	}
	if (!game_start(win))
		return (0);
	loop(win);
}
