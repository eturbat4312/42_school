/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturbat <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:19:36 by eturbat           #+#    #+#             */
/*   Updated: 2022/03/31 13:37:56 by eturbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*keep_remaining(char *sline)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (sline[i] && sline[i] != '\n')
		i++;
	if (!sline[i])
	{
		free(sline);
		return (NULL);
	}
	ptr = malloc(sizeof(char) * (ft_strlen(sline) - i + 1));
	if (!ptr)
		return (NULL);
	i++;
	while (sline[i])
		ptr[j++] = sline[i++];
	ptr[j] = '\0';
	free(sline);
	return (ptr);
}

char	*copy_lines(char *sline)
{
	char	*line;
	int		i;

	i = 0;
	if (!sline[i])
		return (NULL);
	while (sline[i] && sline[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (sline[i] && sline[i] != '\n')
	{
		line[i] = sline[i];
		i++;
	}
	if (sline[i] == '\n')
	{
		line[i] = sline[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_buffer(int fd, char *sline)
{
	char	buff[2];
	int		ret;

	ret = 1;
	while (ft_strchr(sline, '\n') != 1 && ret != 0)
	{
		ret = read(fd, buff, 1);
		if (ret == -1)
			return (NULL);
		buff[ret] = '\0';
		sline = ft_strjoin(sline, buff);
	}
	return (sline);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*sline;

	if (fd < 0)
		return (NULL);
	sline = read_buffer(fd, sline);
	if (!sline)
		return (NULL);
	line = copy_lines(sline);
	sline = keep_remaining(sline);
	return (line);
}
