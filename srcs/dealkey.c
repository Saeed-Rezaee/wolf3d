/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealkey.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:54:33 by elopukh           #+#    #+#             */
/*   Updated: 2018/08/24 15:54:34 by elopukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	dealkey1(t_window *win, int key)
{
	if (key == 53)
	{
		system("killall afplay");
		exit(1);
	}
	if (key == 126)
	{
		clear_image(win);
		if (win->map[(int)(win->pos_x + win->dir_x
			* win->move_speed)][(int)win->pos_y] == 0
		|| win->map[(int)(win->pos_x + win->dir_x
			* win->move_speed)][(int)win->pos_y] == 9)
			win->pos_x += win->dir_x * (win->move_speed);
		if (win->map[(int)(win->pos_x)][(int)(win->pos_y
			+ win->dir_y * win->move_speed)] == 0
		|| win->map[(int)(win->pos_x)][(int)(win->pos_y
			+ win->dir_y * win->move_speed)] == 9)
			win->pos_y += win->dir_y * win->move_speed;
		scene1(win);
	}
}

void	dealkey2(t_window *win, int key)
{
	if (key == 125)
	{
		clear_image(win);
		if (win->map[(int)(win->pos_x - win->dir_x
			* win->move_speed)][(int)win->pos_y] == 0
		|| win->map[(int)(win->pos_x - win->dir_x
			* win->move_speed)][(int)win->pos_y] == 9)
			win->pos_x -= win->dir_x * (win->move_speed);
		if (win->map[(int)(win->pos_x)][(int)(win->pos_y
			- win->dir_y * win->move_speed)] == 0
		|| win->map[(int)(win->pos_x)][(int)(win->pos_y
			- win->dir_y * win->move_speed)] == 9)
			win->pos_y -= win->dir_y * win->move_speed;
		scene1(win);
	}
}

void	dealkey3(t_window *win, int key)
{
	double odirx;
	double olplane;

	if (key == 124)
	{
		clear_image(win);
		odirx = win->dir_x;
		win->dir_x = win->dir_x * cos(-win->rot_speed)
		- win->dir_y * sin(-win->rot_speed);
		win->dir_y = odirx * sin(-win->rot_speed)
		+ win->dir_y * cos(-win->rot_speed);
		olplane = win->plane_x;
		win->plane_x = win->plane_x * cos(-win->rot_speed)
		- win->plane_y * sin(-win->rot_speed);
		win->plane_y = olplane * sin(-win->rot_speed)
		+ win->plane_y * cos(-win->rot_speed);
		scene1(win);
	}
}

void	dealkey4(t_window *win, int key)
{
	if (key == 49)
	{
		if (win->perpwalldist < 2)
		{
			if (win->map[(int)(win->pos_x - win->perpwalldist
				+ win->dir_x * win->move_speed)][(int)win->pos_y] == 5)
				win->map[(int)(win->pos_x - win->perpwalldist
					+ win->dir_x * win->move_speed)][(int)win->pos_y] = 0;
			if (win->map[(int)(win->pos_x)][(int)(win->pos_y
				+ win->perpwalldist + win->dir_y * win->move_speed)] == 5)
				win->map[(int)(win->pos_x)][(int)(win->pos_y
					+ win->perpwalldist + win->dir_y * win->move_speed)] = 0;
			if (win->map[(int)(win->pos_x)][(int)(win->pos_y
				- win->perpwalldist + win->dir_y * win->move_speed)] == 5)
				win->map[(int)(win->pos_x)][(int)(win->pos_y
					- win->perpwalldist + win->dir_y * win->move_speed)] = 0;
			if (win->map[(int)(win->pos_x + win->perpwalldist
				+ win->dir_x * win->move_speed)][(int)win->pos_y] == 5)
				win->map[(int)(win->pos_x + win->perpwalldist
					+ win->dir_x * win->move_speed)][(int)win->pos_y] = 0;
		}
		scene1(win);
	}
}

void	dealkey5(t_window *win, int key)
{
	double odirx;
	double olplane;

	if (key == 123)
	{
		clear_image(win);
		odirx = win->dir_x;
		win->dir_x = win->dir_x * cos(win->rot_speed)
		- win->dir_y * sin(win->rot_speed);
		win->dir_y = odirx * sin(win->rot_speed)
		+ win->dir_y * cos(win->rot_speed);
		olplane = win->plane_x;
		win->plane_x = win->plane_x * cos(win->rot_speed)
		- win->plane_y * sin(win->rot_speed);
		win->plane_y = olplane * sin(win->rot_speed)
		+ win->plane_y * cos(win->rot_speed);
		scene1(win);
	}
}
