/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 17:31:20 by elopukh           #+#    #+#             */
/*   Updated: 2018/08/24 17:31:21 by elopukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

char	**readff(char *file)
{
	char	*str;
	char	*tmp;
	char	**ret;
	int		fd;

	str = ft_strnew(0);
	tmp = NULL;
	fd = file_open(file);
	if (fd < 0 || fd > 8192)
		return (NULL);
	while (get_next_line(fd, &tmp) == 1)
	{
		if (!valid(tmp))
			return (NULL);
		str = readff1(tmp, str);
	}
	if (ft_strlen(str) == 0 || str[0] == '\n')
		return (NULL);
	ret = ft_strsplit(str, '\n');
	free(tmp);
	free(str);
	return (ret);
}

void	count_h(char **str, t_window *win)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		win->height += 1;
		i++;
	}
}

void	fill1(t_window *win, char *str, int i, int j)
{
	win->map[i][j] = ft_atoi(str);
	free(str);
}
