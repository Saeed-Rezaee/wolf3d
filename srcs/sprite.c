/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srite.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:40:40 by elopukh           #+#    #+#             */
/*   Updated: 2018/08/24 15:40:41 by elopukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	setsprite(t_window *win)
{
	win->spritex = win->sprites[win->spriteorder[win->i]].x - win->pos_x;
	win->spritey = win->sprites[win->spriteorder[win->i]].y - win->pos_y;
	win->invdet = 1.0 / (win->plane_x * win->dir_y - win->dir_x * win->plane_y);
	win->transformx = win->invdet *
	(win->dir_y * win->spritex - win->dir_x * win->spritey);
	win->transformy = win->invdet *
	(-win->plane_y * win->spritex + win->plane_x * win->spritey);
	win->movescreen = (int)(win->vmove / win->transformy);
	win->spritescreenx = (int)((W_WIN / 2) * (1 + win->transformx
	/ win->transformy));
	win->spriteheight = abs((int)(H_WIN / (win->transformy))) / win->vdiv;
	win->drawstarty = -win->spriteheight / 2 + H_WIN / 2 + win->movescreen;
	if (win->drawstarty < 0)
		win->drawstarty = 0;
	win->drawendy = win->spriteheight / 2 + H_WIN / 2 + win->movescreen;
	if (win->drawendy >= H_WIN)
		win->drawendy = H_WIN - 1;
	win->spritewidth = abs((int)(H_WIN / (win->transformy))) / win->udiv;
	win->drawstartx = -win->spritewidth / 2 + win->spritescreenx;
	if (win->drawstartx < 0)
		win->drawstartx = 0;
	win->drawendx = win->spritewidth / 2 + win->spritescreenx;
	if (win->drawendx >= W_WIN)
		win->drawendx = W_WIN - 1;
}

void	draws(t_window *win)
{
	win->d = (win->y - win->movescreen) * 256 - H_WIN *
	128 + win->spriteheight * 128;
	win->texy = ((win->d * TEXHEIGHT) / win->spriteheight) / 256;
	win->colour = win->texture[win->sprites[win->spriteorder[win->i]].t]
		[TEXWIDTH * win->texy + win->texx];
	if ((win->colour & 0x00FFFFFF) != 0 && win->colour != 0x980088)
		pixel_put_img(win, win->stripe, win->y, win->colour);
}

void	drawsprite(t_window *win)
{
	if (fabs(win->spritex) < 1 && fabs(win->spritey) < 1
	&& (win->sprites[win->spriteorder[win->i]].t == 24
	|| win->sprites[win->spriteorder[win->i]].t == 25
	|| win->sprites[win->spriteorder[win->i]].t == 26
	|| win->sprites[win->spriteorder[win->i]].t == 27)
	&& win->sprites[win->spriteorder[win->i]].f == 0)
	{
		win->sprites[win->spriteorder[win->i]].f = 1;
		win->points++;
	}
	win->texx = (int)(256 * (win->stripe - (-win->spritewidth
	/ 2 + win->spritescreenx)) * TEXWIDTH / win->spritewidth) / 256;
	if (win->transformy > 0 && win->stripe > 0 &&
	win->stripe < W_WIN && win->transformy
	< win->buffer[win->stripe] && win->sprites[win->spriteorder[win->i]].f == 0)
	{
		win->y = win->drawstarty;
		while (win->y < win->drawendy)
		{
			draws(win);
			win->y++;
		}
	}
	win->stripe++;
}

void	spritecasting(t_window *win)
{
	win->i = 0;
	while (win->i < NUMSPRITES)
	{
		win->spriteorder[win->i] = win->i;
		win->spritedistance[win->i] = ((win->pos_x - win->sprites[win->i].x) *
		(win->pos_x - win->sprites[win->i].x)
		+ (win->pos_y - win->sprites[win->i].y)
		* (win->pos_y - win->sprites[win->i].y));
		win->i++;
	}
	sorting(win->spriteorder, win->spritedistance, NUMSPRITES);
	win->i = 0;
	while (win->i < NUMSPRITES)
	{
		setsprite(win);
		win->stripe = win->drawstartx;
		while (win->stripe < win->drawendx)
			drawsprite(win);
		win->i++;
	}
}
