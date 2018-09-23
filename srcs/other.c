/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 16:12:56 by elopukh           #+#    #+#             */
/*   Updated: 2018/08/24 16:12:57 by elopukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	pixel_put_img(t_window *win, int x, int y, int colour)
{
	if (x < H_WIN || y < W_WIN)
	{
		colour = mlx_get_color_value(win->mlx_ptr, colour);
		ft_memcpy(win->img + 4 * W_WIN * y + x * 4, &colour, sizeof(int));
	}
}

void	verline(int x, t_window *win)
{
	while (win->start < win->end - 1)
	{
		pixel_put_img(win, x, win->start, win->colour);
		win->start++;
	}
}

void	ft_swapd(double *a, double *b)
{
	double c;

	c = *a;
	*a = *b;
	*b = c;
}

void	check(int *space)
{
	*space = (*space * 10) / 13;
	if (*space == 9 || *space == 10)
		*space = 11;
	if (*space < 1)
		*space = 1;
}

void	sorting(int *order, double *dist, int amount)
{
	int space;
	int flag;
	int j;
	int i;

	space = amount;
	flag = 0;
	while (space > 1 || flag)
	{
		check(&space);
		flag = 0;
		i = 0;
		while (i < amount - space)
		{
			j = i + space;
			if (dist[i] < dist[j])
			{
				ft_swapd(&dist[i], &dist[j]);
				ft_swap(&order[i], &order[j]);
				flag = 1;
			}
			i++;
		}
	}
}
