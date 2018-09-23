/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:09:13 by elopukh           #+#    #+#             */
/*   Updated: 2018/08/24 15:09:14 by elopukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		game_start(t_window *win)
{
	if (!(fill_texture(win)))
	{
		write(1, "Error on texture initialization!\n", 33);
		return (0);
	}
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->zast[11], 0, 0);
	system("afplay ./mus.mp3 &");
	return (1);
}

void	draw(t_window *win)
{
	char *str;

	str = ft_itoa((int)(1.0 / win->frame_time));
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->zast[10], 0, 875);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 0, 2,
		0xFFFFFF, str);
	free(str);
}

void	count_points(t_window *win)
{
	int flag;

	flag = win->points;
	while (flag > 9)
	{
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
			win->zast[flag % 10], 260, 920);
		flag = flag / 10;
	}
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
		win->zast[flag], 230, 920);
}

void	ray_cast(t_window *win)
{
	count_wall(win);
	calc_step(win);
	dda(win);
	count_height(win);
	win->y = win->start;
	win->open = 0;
	while (win->y < win->end)
	{
		counts(win);
	}
	win->buffer[win->x] = win->perpwalldist;
	floorcasting(win);
	win->x++;
}

void	scene1(t_window *win)
{
	clock_t	start_t;
	clock_t	end_t;

	win->x = 0;
	start_t = clock();
	while (win->x < W_WIN)
		ray_cast(win);
	spritecasting(win);
	end_t = clock();
	win->frame_time = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	win->move_speed = win->frame_time * 9;
	win->rot_speed = win->frame_time * 5;
	draw(win);
	count_points(win);
}
