/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 16:41:52 by elopukh           #+#    #+#             */
/*   Updated: 2018/08/15 16:41:53 by elopukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		check_width(char **matr)
{
	int i;
	int chis;
	int count;

	i = 0;
	chis = -1;
	while (matr[i] != '\0')
	{
		count = count_numb(matr[i]);
		if (chis == -1)
			chis = count;
		if (chis != count)
		{
			return (0);
		}
		count = 0;
		i++;
	}
	return (1);
}

void	fill_matr(t_window *win, char **matr)
{
	char	**tmp;

	win->h = 0;
	while (matr[win->h] != '\0')
	{
		win->map[win->h] = (int*)malloc(sizeof(int) * win->width);
		tmp = ft_strsplit(matr[win->h], ' ');
		free(matr[win->h]);
		win->w = 0;
		while (tmp[win->w] != '\0')
		{
			win->map[win->h][win->w] = ft_atoi(tmp[win->w]);
			free(tmp[win->w]);
			win->w++;
		}
		free(tmp);
		win->h++;
	}
	free(matr);
}

int		check_null(char **matr)
{
	int i;
	int j;

	i = -1;
	while (matr[++i] != '\0')
	{
		j = -1;
		while (matr[i][++j] != '\0')
		{
			if ((!(matr[0][j] >= '0' && matr[0][j] <= '9') && matr[0][j] != ' ')
			|| (!(matr[i][j] >= '0' && matr[i][j] <= '9') && matr[i][j] != ' '))
				return (0);
		}
	}
	i--;
	j = 0;
	while (matr[0][j] != '\0')
	{
		if ((!(matr[0][j] >= '1' && matr[0][j] <= '9') && matr[0][j] != ' ')
		|| (!(matr[i][j] >= '1' && matr[i][j] <= '9') && matr[i][j] != ' '))
			return (0);
		j++;
	}
	return (1);
}

void	free_matr(char **matr)
{
	int i;

	i = 0;
	while (matr[i] != '\0')
	{
		free(matr[i]);
		i++;
	}
	free(matr);
}

int		get_matr(char *str, t_window *win)
{
	char **matr;

	matr = readff(str);
	if (!matr || !check_width(matr) || !check_null(matr))
	{
		if (matr)
			free_matr(matr);
		return (0);
	}
	count_h(matr, win);
	win->width = count_numb(matr[0]);
	win->map = (int**)malloc(sizeof(int*) * win->height);
	fill_matr(win, matr);
	if (win->h < 4 || win->w < 4)
		return (0);
	return (1);
}
