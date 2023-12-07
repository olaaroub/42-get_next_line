/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 21:02:28 by olaaroub          #+#    #+#             */
/*   Updated: 2023/12/07 21:05:04 by olaaroub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_new_line(char *stat)
{
	int		i;
	int		is_newline;
	char	*line;

	i = 0;
	if (!stat || stat[0] == '\0')
		return (NULL);
	while (stat[i] != '\n' && stat[i] != '\0')
		i++;
	if (stat[i] == '\n')
		is_newline = 1;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (free(stat), NULL);
	i = 0;
	while (stat[i] != '\n' && stat[i] != '\0')
	{
		line[i] = stat[i];
		i++;
	}
	if (is_newline == 1)
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_rest(char *stat)
{
	char	*rest;
	int		j;
	int		i;

	j = 0;
	i = 0;
	if (!stat || stat[0] == '\0')
		return (free(stat), NULL);
	while (stat[j] != '\n' && stat[j] != '\0')
		j++;
	if (stat[j] == '\0')
		return (free(stat), NULL);
	rest = malloc(sizeof(char) * ((ft_strlen(stat) - j) + 1));
	if (!rest)
		return (free(stat), NULL);
	j++;
	while (stat[j])
	{
		rest[i] = stat[j];
		j++;
		i++;
	}
	rest[i] = '\0';
	return (free(stat), rest);
}

char	*get_bytes(char *stat, int fd)
{
	ssize_t	readed;
	char	*tmp;
	char	*buf;

	buf = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buf)
		return (free(stat), NULL);
	readed = 1;
	tmp = NULL;
	while (readed > 0)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed == -1)
			return (free(buf), free(stat), NULL);
		buf[readed] = '\0';
		tmp = ft_strdup(stat);
		free(stat);
		stat = ft_strjoin(tmp, buf);
		free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (stat);
}

char	*get_next_line(int fd)
{
	static char	*stat[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(stat[fd]), NULL);
	stat[fd] = get_bytes(stat[fd], fd);
	line = get_new_line(stat[fd]);
	stat[fd] = get_rest(stat[fd]);
	return (line);
}
