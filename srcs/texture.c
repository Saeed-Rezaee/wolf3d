/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 18:17:22 by elopukh           #+#    #+#             */
/*   Updated: 2018/08/23 18:17:23 by elopukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		it6(t_window *win)
{
	void *temp;

	if (!(temp = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/sp_zol2.xpm", &win->texw, &win->texh)))
		return (0);
	if (!(win->texture[25] = (int*)mlx_get_data_addr(temp,
	&win->bpp, &win->size_line, &win->endian)))
		write(1, "Error on getting mlx data addr!\n", 32);
	if (!(temp = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/sp_zol3.xpm", &win->texw, &win->texh)))
		return (0);
	if (!(win->texture[26] = (int*)mlx_get_data_addr(temp, &win->bpp,
	&win->size_line, &win->endian)))
		write(1, "Error on getting mlx data addr!\n", 32);
	if (!(temp = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/sp_zol4.xpm", &win->texw, &win->texh)))
		return (0);
	if (!(win->texture[27] = (int*)mlx_get_data_addr(temp, &win->bpp,
	&win->size_line, &win->endian)))
		write(1, "Error on getting mlx data addr!\n", 32);
	return (1);
}

int		z1(t_window *win)
{
	if (!(win->zast[10] = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/zast.xpm", &win->texw, &win->texh)))
		return (0);
	if (!(win->zast[11] = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/first.xpm", &win->texw, &win->texh)))
		return (0);
	if (!(win->zast[0] = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/0", &win->texw, &win->texh)))
		return (0);
	if (!(win->zast[1] = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/1", &win->texw, &win->texh)))
		return (0);
	if (!(win->zast[2] = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/2", &win->texw, &win->texh)))
		return (0);
	if (!(win->zast[3] = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/3", &win->texw, &win->texh)))
		return (0);
	if (!(win->zast[4] = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/4", &win->texw, &win->texh)))
		return (0);
	return (1);
}

int		fill_texture(t_window *win)
{
	if (!it1(win) || !it2(win) || !it3(win) || !it4(win)
	|| !it5(win) || !it6(win) || !it7(win) || !it8(win)
	|| !it9(win) || !it10(win))
		return (0);
	if (!z1(win))
		return (0);
	if (!(win->zast[5] = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/5", &win->texw, &win->texh)))
		return (0);
	if (!(win->zast[6] = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/6", &win->texw, &win->texh)))
		return (0);
	if (!(win->zast[7] = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/7", &win->texw, &win->texh)))
		return (0);
	if (!(win->zast[8] = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/8", &win->texw, &win->texh)))
		return (0);
	if (!(win->zast[9] = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/9", &win->texw, &win->texh)))
		return (0);
	return (1);
}

void	clear_image(t_window *win)
{
	int i;
	int j;

	i = -1;
	while (++i < H_WIN)
	{
		j = -1;
		while (++j < W_WIN)
			pixel_put_img(win, j, i, 0x000000);
	}
}
