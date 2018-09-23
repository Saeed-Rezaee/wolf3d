/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 18:05:42 by elopukh           #+#    #+#             */
/*   Updated: 2018/08/23 18:05:43 by elopukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		it1(t_window *win)
{
	void	*temp;

	if (!(temp = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/bluegrey.xpm", &win->texw, &win->texh)))
		return (0);
	if (!(win->texture[0] = (int*)mlx_get_data_addr(temp, &win->bpp,
	&win->size_line, &win->endian)))
		write(1, "Error on getting mlx data addr!\n", 32);
	if (!(temp = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/redbrick.xpm", &win->texw, &win->texh)))
		return (0);
	if (!(win->texture[1] = (int*)mlx_get_data_addr(temp, &win->bpp,
	&win->size_line, &win->endian)))
		write(1, "Error on getting mlx data addr!\n", 32);
	if (!(temp = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/bluestone.xpm", &win->texw, &win->texh)))
		return (0);
	if (!(win->texture[2] = (int*)mlx_get_data_addr(temp, &win->bpp,
	&win->size_line, &win->endian)))
		write(1, "Error on getting mlx data addr!\n", 32);
	return (1);
}

int		it2(t_window *win)
{
	void	*temp;

	if (!(temp = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/greystone.xpm", &win->texw, &win->texh)))
		return (0);
	if (!(win->texture[5] = (int*)mlx_get_data_addr(temp, &win->bpp,
	&win->size_line, &win->endian)))
		write(1, "Error on getting mlx data addr!\n", 32);
	if (!(temp = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/wood.xpm", &win->texw, &win->texh)))
		return (0);
	if (!(win->texture[6] = (int*)mlx_get_data_addr(temp, &win->bpp,
	&win->size_line, &win->endian)))
		write(1, "Error on getting mlx data addr!\n", 32);
	if (!(temp = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/greenlight.xpm", &win->texw, &win->texh)))
		return (0);
	if (!(win->texture[7] = (int*)mlx_get_data_addr(temp, &win->bpp,
	&win->size_line, &win->endian)))
		write(1, "Error on getting mlx data addr!\n", 32);
	return (1);
}

int		it3(t_window *win)
{
	void *temp;

	if (!(temp = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/sp_bra.xpm", &win->texw, &win->texh)))
		return (0);
	if (!(win->texture[10] = (int*)mlx_get_data_addr(temp, &win->bpp,
	&win->size_line, &win->endian)))
		write(1, "Error on getting mlx data addr!\n", 32);
	if (!(temp = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/sp_derevo.xpm", &win->texw, &win->texh)))
		return (0);
	if (!(win->texture[11] = (int*)mlx_get_data_addr(temp, &win->bpp,
	&win->size_line, &win->endian)))
		write(1, "Error on getting mlx data addr!\n", 32);
	if (!(temp = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/sp_green.xpm", &win->texw, &win->texh)))
		return (0);
	if (!(win->texture[12] = (int*)mlx_get_data_addr(temp, &win->bpp,
	&win->size_line, &win->endian)))
		write(1, "Error on getting mlx data addr!\n", 32);
	return (1);
}

int		it4(t_window *win)
{
	void *temp;

	if (!(temp = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/sp_kletkd.xpm", &win->texw, &win->texh)))
		return (0);
	if (!(win->texture[15] = (int*)mlx_get_data_addr(temp, &win->bpp,
	&win->size_line, &win->endian)))
		write(1, "Error on getting mlx data addr!\n", 32);
	if (!(temp = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/sp_kletskil.xpm", &win->texw, &win->texh)))
		return (0);
	if (!(win->texture[16] = (int*)mlx_get_data_addr(temp, &win->bpp,
	&win->size_line, &win->endian)))
		write(1, "Error on getting mlx data addr!\n", 32);
	if (!(temp = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/sp_knife.xpm", &win->texw, &win->texh)))
		return (0);
	if (!(win->texture[17] = (int*)mlx_get_data_addr(temp, &win->bpp,
	&win->size_line, &win->endian)))
		write(1, "Error on getting mlx data addr!\n", 32);
	return (1);
}

int		it5(t_window *win)
{
	void *temp;

	if (!(temp = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/sp_pillar.xpm", &win->texw, &win->texh)))
		return (0);
	if (!(win->texture[20] = (int*)mlx_get_data_addr(temp, &win->bpp,
	&win->size_line, &win->endian)))
		write(1, "Error on getting mlx data addr!\n", 32);
	if (!(temp = mlx_xpm_file_to_image(win->mlx_ptr,
	"./pics/sp_sin_bochka.xpm", &win->texw, &win->texh)))
		return (0);
	if (!(win->texture[21] = (int*)mlx_get_data_addr(temp, &win->bpp,
	&win->size_line, &win->endian)))
		write(1, "Error on getting mlx data addr!\n", 32);
	if (!(temp = mlx_xpm_file_to_image(win->mlx_ptr, "./pics/sp_skelet.xpm",
	&win->texw, &win->texh)))
		return (0);
	if (!(win->texture[22] = (int*)mlx_get_data_addr(temp, &win->bpp,
	&win->size_line, &win->endian)))
		write(1, "Error on getting mlx data addr!\n", 32);
	return (1);
}
