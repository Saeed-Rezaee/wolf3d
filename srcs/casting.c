/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 14:30:16 by elopukh           #+#    #+#             */
/*   Updated: 2018/08/24 14:30:17 by elopukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	count_wall(t_window *win)
{
	win->camera_x = 2 * win->x / (double)W_WIN - 1;
	win->ray_dirx = win->dir_x + win->plane_x * win->camera_x;
	win->ray_diry = win->dir_y + win->plane_y * win->camera_x;
	win->mapx = win->pos_x;
	win->mapy = win->pos_y;
	win->deltadist_x = fabs(1 / win->ray_dirx);
	win->deltadist_y = fabs(1 / win->ray_diry);
	win->hit = 0;
}

void	calc_step(t_window *win)
{
	if (win->ray_dirx < 0)
	{
		win->step_x = -1;
		win->sidedist_x = (win->pos_x - win->mapx) * win->deltadist_x;
	}
	else
	{
		win->step_x = 1;
		win->sidedist_x = (win->mapx + 1.0 - win->pos_x) * win->deltadist_x;
	}
	if (win->ray_diry < 0)
	{
		win->step_y = -1;
		win->sidedist_y = (win->pos_y - win->mapy) * win->deltadist_y;
	}
	else
	{
		win->step_y = 1;
		win->sidedist_y = (win->mapy + 1.0 - win->pos_y) * win->deltadist_y;
	}
}

void	dda(t_window *win)
{
	while (win->hit == 0)
	{
		if (win->sidedist_x < win->sidedist_y)
		{
			win->sidedist_x += win->deltadist_x;
			win->mapx += win->step_x;
			win->side = 0;
		}
		else
		{
			win->sidedist_y += win->deltadist_y;
			win->mapy += win->step_y;
			win->side = 1;
		}
		if (win->map[win->mapx][win->mapy] > 0)
			win->hit = 1;
	}
	if (win->side == 0)
		win->perpwalldist = ((double)win->mapx - win->pos_x +
		(1.0 - (double)win->step_x) / 2.0) / win->ray_dirx;
	else
		win->perpwalldist = ((double)win->mapy - win->pos_y +
		(1.0 - (double)win->step_y) / 2.0) / win->ray_diry;
}

void	count_height(t_window *win)
{
	win->line_h = (H_WIN / win->perpwalldist);
	win->start = -win->line_h / 2 + H_WIN / 2;
	if (win->start < 0)
		win->start = 0;
	win->end = win->line_h / 2 + H_WIN / 2;
	if (win->end >= H_WIN)
		win->end = H_WIN - 1;
	win->texnum = win->map[win->mapx][win->mapy] - 1;
	if (win->side == 0)
		win->wallx = win->pos_y + win->perpwalldist * win->ray_diry;
	else
		win->wallx = win->pos_x + win->perpwalldist * win->ray_dirx;
	win->wallx -= floor((win->wallx));
	win->texx = (int)(win->wallx * (double)(TEXWIDTH));
	if (win->side == 0 && win->ray_dirx > 0)
		win->texx = TEXWIDTH - win->texx - 1;
	if (win->side == 1 && win->ray_diry < 0)
		win->texx = TEXWIDTH - win->texx - 1;
}

void	counts(t_window *win)
{
	win->d = win->y * 256 - H_WIN * 128 + win->line_h * 128;
	win->texy = ((win->d * TEXHEIGHT) / win->line_h) / 256;
	win->colour = win->texture[win->texnum][TEXHEIGHT * win->texy + win->texx];
	if (win->side == 1)
		win->colour = (win->colour >> 1) & 8355711;
	pixel_put_img(win, win->x, win->y, win->colour);
	win->y++;
}
