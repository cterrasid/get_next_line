/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrasi <cterrasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:21:24 by cterrasi          #+#    #+#             */
/*   Updated: 2022/06/05 19:39:08 by cterrasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	prepare_next_line(char **collector)
{
	char	*str;
	char	*aux;

	aux = *collector;
	while (**collector != '\n')
		(*collector)++;
	str = malloc(sizeof(char) * (*collector - aux) + 1);
	if (str)
	{
		(*collector)++;
		aux = *collector;
		ft_memcpy(str, *collector, (*collector - aux));
		str[*collector - aux] = '\0';
		*collector = str;
	}
}

static void	extract_line(char **collector, char **line)
{
	char	*str;

	str = *collector;
	while (*str != '\n')
		str++;
	*line = ft_substr(*collector, 0, str - *collector);
	*collector += (str - *collector);
}

static void	read_and_compose_line(int fd, char **collector)
{
	int		bytes_read;
	char	*buffer;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer)
	{
		while (!ft_strchr(*collector, '\n'))
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			*(buffer + bytes_read) = '\0';
			*collector = ft_strjoin(*collector, buffer);
		}
	}
}

char	*get_next_line(int fd)
{
	static char	*collector;
	char		*line;

	if (fd < 1 || BUFFER_SIZE < 1)
		return (0);
	read_and_compose_line(fd, &collector);
	if (!collector)
		return (NULL);
	extract_line(&collector, &line);
	prepare_next_line(&collector);
	return (line);
}
