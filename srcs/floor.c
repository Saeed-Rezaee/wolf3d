/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:27:17 by elopukh           #+#    #+#             */
/*   Updated: 2018/08/24 15:27:18 by elopukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	check_side(t_window *win)
{
	if (win->side == 0 && win->ray_dirx > 0)
	{
		win->floorx_wall = win->mapx;
		win->floory_wall = win->mapy + win->wallx;
	}
	else if (win->side == 0 && win->ray_dirx < 0)
	{
		win->floorx_wall = win->mapx + 1.0;
		win->floory_wall = win->mapy + win->wallx;
	}
	else if (win->side == 1 && win->ray_diry > 0)
	{
		win->floorx_wall = win->mapx + win->wallx;
		win->floory_wall = win->mapy;
	}
	else
	{
		win->floorx_wall = win->mapx + win->wallx;
		win->floory_wall = win->mapy + 1.0;
	}
}

void	floorcasting(t_window *win)
{
	check_side(win);
	win->dist_wall = win->perpwalldist;
	win->dist_player = 0.0;
	if (win->end < 0)
		win->end = H_WIN;
	win->y = win->end + 1;
	while (win->y < H_WIN)
	{
		win->current_dist = H_WIN / (2.0 * win->y - H_WIN);
		win->weight = (win->current_dist - win->dist_player)
		/ (win->dist_wall - win->dist_player);
		win->current_floorx = win->weight * win->floorx_wall
		+ (1.0 - win->weight) * win->pos_x;
		win->current_floory = win->weight * win->floory_wall
		+ (1.0 - win->weight) * win->pos_y;
		win->floortx = (int)(win->current_floorx * TEXWIDTH) % TEXWIDTH;
		win->floorty = (int)(win->current_floory * TEXHEIGHT) % TEXHEIGHT;
		win->colour = (win->texture[5][TEXWIDTH * win->floorty
			+ win->floortx] >> 1) & 8355711;
		pixel_put_img(win, win->x, win->y, win->colour);
		win->colour = win->texture[6][TEXWIDTH * win->floorty + win->floortx];
		pixel_put_img(win, win->x, H_WIN - win->y, win->colour);
		win->y++;
	}
}
