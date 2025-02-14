/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abifkirn <abifkirn@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:25:02 by abifkirn          #+#    #+#             */
/*   Updated: 2025/02/09 14:52:21 by abifkirn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*get_read(int fd)
{
	char	*l;
	ssize_t	br;

	l = malloc(2);
	if (!l)
		return (NULL);
	br = read(fd, l, 1);
	if (br <= 0)
	{
		free(l);
		return (NULL);
	}
	l[br] = '\0';
	return (l);
}

char	*get_line(char	*res)
{
	char		*result;
	size_t		i;

	i = 0;
	while (res[i] != '\0' && res[i] != '\n')
		i++;
	if (res[i] == '\n')
		result = malloc(i + 2);
	else
		result = malloc(i + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (res[i] != '\0' && res[i] != '\n')
	{
		result[i] = res[i];
		i++;
	}
	if (res[i] == '\n')
	{
		result[i] = res[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*reset(char *reserv)
{
	size_t		i;
	size_t		j;
	char		*new;

	i = 0;
	j = 0;
	while (reserv[i] != '\0' && reserv[i] != '\n')
		i++;
	new = malloc((ft_strlen(reserv) - i) + 1);
	if (!new)
		return (NULL);
	if (reserv[i] == '\n')
		i++;
	while (reserv[i] != '\0')
	{
		new[j] = reserv[i];
		i++;
		j++;
	}
	new[j] = '\0';
	free(reserv);
	return (new);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*readed;

	readed = NULL;
	if (fd < 0)
		return (NULL);
	line = NULL;
	while (!ft_strchr(readed, '\n'))
	{
		line = get_read(fd);
		if (!line)
			break ;
		readed = ft_strjoin(readed, line);
	}
	if (!line && !readed)
		return (NULL);
	return (readed);
}
