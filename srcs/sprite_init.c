/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:13:56 by elopukh           #+#    #+#             */
/*   Updated: 2018/08/24 15:13:57 by elopukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	is1(t_window *win)
{
	win->sprites[0].x = 3;
	win->sprites[0].y = 8;
	win->sprites[0].t = 7;
	win->sprites[0].f = 0;
	win->sprites[1].x = 2;
	win->sprites[1].y = 18;
	win->sprites[1].t = 7;
	win->sprites[1].f = 0;
	win->sprites[2].x = 9;
	win->sprites[2].y = 17;
	win->sprites[2].t = 7;
	win->sprites[2].f = 0;
	win->sprites[3].x = 10;
	win->sprites[3].y = 2.5;
	win->sprites[3].t = 17;
	win->sprites[3].f = 0;
	win->sprites[4].x = 10;
	win->sprites[4].y = 4.5;
	win->sprites[4].t = 17;
	win->sprites[4].f = 0;
	win->sprites[5].x = 12;
	win->sprites[5].y = 8;
	win->sprites[5].t = 22;
	win->sprites[5].f = 0;
}

void	is2(t_window *win)
{
	win->sprites[6].x = 5;
	win->sprites[6].y = 5;
	win->sprites[6].t = 26;
	win->sprites[6].f = 0;
	win->sprites[7].x = 2;
	win->sprites[7].y = 7;
	win->sprites[7].t = 26;
	win->sprites[7].f = 0;
	win->sprites[8].x = 3;
	win->sprites[8].y = 6;
	win->sprites[8].t = 27;
	win->sprites[8].f = 0;
	win->sprites[9].x = 12;
	win->sprites[9].y = 2;
	win->sprites[9].t = 26;
	win->sprites[9].f = 0;
	win->sprites[10].x = 13;
	win->sprites[10].y = 2;
	win->sprites[10].t = 26;
	win->sprites[10].f = 0;
	win->sprites[11].x = 1.7;
	win->sprites[11].y = 20.5;
	win->sprites[11].t = 12;
	win->sprites[11].f = 0;
}

void	is3(t_window *win)
{
	win->sprites[12].x = 3.2;
	win->sprites[12].y = 20.5;
	win->sprites[12].t = 12;
	win->sprites[12].f = 0;
	win->sprites[13].x = 1.5;
	win->sprites[13].y = 15;
	win->sprites[13].t = 15;
	win->sprites[13].f = 0;
	win->sprites[14].x = 3.5;
	win->sprites[14].y = 15;
	win->sprites[14].t = 16;
	win->sprites[14].f = 0;
	win->sprites[15].x = 2;
	win->sprites[15].y = 16;
	win->sprites[15].t = 26;
	win->sprites[15].f = 0;
	win->sprites[16].x = 3;
	win->sprites[16].y = 18;
	win->sprites[16].t = 26;
	win->sprites[16].f = 0;
	win->sprites[17].x = 4.5;
	win->sprites[17].y = 8;
	win->sprites[17].t = 23;
	win->sprites[17].f = 0;
}

void	is4(t_window *win)
{
	win->sprites[18].x = 10.5;
	win->sprites[18].y = 18;
	win->sprites[18].t = 19;
	win->sprites[18].f = 0;
	win->sprites[19].x = 10.5;
	win->sprites[19].y = 19;
	win->sprites[19].t = 21;
	win->sprites[19].f = 0;
	win->sprites[20].x = 10.5;
	win->sprites[20].y = 17;
	win->sprites[20].t = 21;
	win->sprites[20].f = 0;
	win->sprites[21].x = 15;
	win->sprites[21].y = 15;
	win->sprites[21].t = 25;
	win->sprites[21].f = 0;
	win->sprites[22].x = 14;
	win->sprites[22].y = 24;
	win->sprites[22].t = 24;
	win->sprites[22].f = 0;
	win->sprites[23].x = 13;
	win->sprites[23].y = 28;
	win->sprites[23].t = 11;
	win->sprites[23].f = 0;
}

void	init_sprites(t_window *win)
{
	is1(win);
	is2(win);
	is3(win);
	is4(win);
}
