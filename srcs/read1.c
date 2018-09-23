/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 17:30:37 by elopukh           #+#    #+#             */
/*   Updated: 2018/08/24 17:30:37 by elopukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		count_numb(char *str)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;
		if (str[i] != ' ' && str[i] != '\0')
		{
			while (str[i] != ' ' && str[i] != '\0')
				i++;
			count++;
		}
	}
	return (count);
}

char	*ft_strjoinfree(char const *s1, char const *s2)
{
	char *str;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(*str) *
		(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	free((void *)s1);
	free((void *)s2);
	return (str);
}

char	*readff1(char *tmp, char *str)
{
	char	*tmp_1;

	tmp_1 = ft_strjoinfree(str, tmp);
	str = ft_strdup(tmp_1);
	free(tmp_1);
	tmp = ft_strjoin(str, "\n");
	free(str);
	str = ft_strdup(tmp);
	free(tmp);
	return (str);
}

int		file_open(char *file)
{
	int fd;

	fd = open(file, O_DIRECTORY);
	if (fd > 0)
		return (-1);
	else
		fd = open(file, O_RDONLY);
	return (fd);
}

int		valid(char *str)
{
	int i;

	i = 0;
	if (str[0] != '\0' && !(str[i] >= '1' && str[i] <= '9'))
		return (0);
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ' ')
			return (0);
		i++;
	}
	i--;
	if (str[i] != '\0' && !(str[i] >= '1' && str[i] <= '9'))
		return (0);
	return (1);
}
