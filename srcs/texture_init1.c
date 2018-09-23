/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 14:15:56 by elopukh           #+#    #+#             */
/*   Updated: 2018/08/25 14:15:57 by elopukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		it7(t_window *win)
{
	void *temp;

	if (!(temp = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/03.xpm", &win->texw, &win->texh)))
		return (0);
	if (!(win->texture[28] = (int*)mlx_get_data_addr(temp,
	&win->bpp, &win->size_line, &win->endian)))
		write(1, "Error on getting mlx data addr!\n", 32);
	if (!(temp = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/door.xpm", &win->texw, &win->texh)))
		return (0);
	if (!(win->texture[4] = (int*)mlx_get_data_addr(temp, &win->bpp,
	&win->size_line, &win->endian)))
		write(1, "Error on getting mlx data addr!\n", 32);
	if (!(temp = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/redgrey.xpm", &win->texw, &win->texh)))
		return (0);
	if (!(win->texture[3] = (int*)mlx_get_data_addr(temp, &win->bpp,
	&win->size_line, &win->endian)))
		write(1, "Error on getting mlx data addr!\n", 32);
	return (1);
}

int		it8(t_window *win)
{
	void *temp;

	if (!(temp = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/eagle.xpm", &win->texw, &win->texh)))
		return (0);
	if (!(win->texture[8] = (int*)mlx_get_data_addr(temp, &win->bpp,
	&win->size_line, &win->endian)))
		write(1, "Error on getting mlx data addr!\n", 32);
	if (!(temp = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/sp_barrel.xpm", &win->texw, &win->texh)))
		return (0);
	if (!(win->texture[9] = (int*)mlx_get_data_addr(temp, &win->bpp,
	&win->size_line, &win->endian)))
		write(1, "Error on getting mlx data addr!\n", 32);
	if (!(temp = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/sp_kletka.xpm", &win->texw, &win->texh)))
		return (0);
	if (!(win->texture[14] = (int*)mlx_get_data_addr(temp, &win->bpp,
	&win->size_line, &win->endian)))
		write(1, "Error on getting mlx data addr!\n", 32);
	return (1);
}

int		it9(t_window *win)
{
	void *temp;

	if (!(temp = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/sp_key.xpm", &win->texw, &win->texh)))
		return (0);
	if (!(win->texture[13] = (int*)mlx_get_data_addr(temp, &win->bpp,
	&win->size_line, &win->endian)))
		write(1, "Error on getting mlx data addr!\n", 32);
	if (!(temp = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/sp_lezskelet.xpm", &win->texw, &win->texh)))
		return (0);
	if (!(win->texture[18] = (int*)mlx_get_data_addr(temp, &win->bpp,
	&win->size_line, &win->endian)))
		write(1, "Error on getting mlx data addr!\n", 32);
	if (!(temp = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/sp_pech.xpm", &win->texw, &win->texh)))
		return (0);
	if (!(win->texture[19] = (int*)mlx_get_data_addr(temp, &win->bpp,
	&win->size_line, &win->endian)))
		write(1, "Error on getting mlx data addr!\n", 32);
	return (1);
}

int		it10(t_window *win)
{
	void *temp;

	if (!(temp = mlx_xpm_file_to_image(win->mlx_ptr, "./pics/sp_stol.xpm",
	&win->texw, &win->texh)))
		return (0);
	if (!(win->texture[23] = (int*)mlx_get_data_addr(temp, &win->bpp,
	&win->size_line, &win->endian)))
		write(1, "Error on getting mlx data addr!\n", 32);
	if (!(temp = mlx_xpm_file_to_image(win->mlx_ptr, "./pics/sp_zol1.xpm",
	&win->texw, &win->texh)))
		return (0);
	if (!(win->texture[24] = (int*)mlx_get_data_addr(temp, &win->bpp,
	&win->size_line, &win->endian)))
		write(1, "Error on getting mlx data addr!\n", 32);
	return (1);
}
