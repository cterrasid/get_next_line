/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrasi <cterrasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:21:24 by cterrasi          #+#    #+#             */
/*   Updated: 2022/07/09 18:30:40 by cterrasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*prepare_next_line(char *collector)
{
	char	*next_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (collector[i] && collector[i] != '\n')
		i++;
	if (!collector[i])
	{
		free(collector);
		return (NULL);
	}
	next_line = malloc(sizeof(char) * (ft_strlen(collector) - i + 1));
	if (next_line)
	{
		i++;
		while (collector[i])
			next_line[j++] = collector[i++];
		*(next_line + j) = '\0';
		free(collector);
		return (next_line);
	}
	return (NULL);
}

static char	*extract_line(char *collector)
{
	char	*line;
	int		i;

	i = 0;
	if (!collector[i])
		return (NULL);
	while (collector[i] && collector[i] != '\n')
		i++;
	line = ft_substr(collector, 0, i + 1);
	i = 0;
	while (collector[i] && collector[i] != '\n')
	{
		line[i] = collector[i];
		i++;
	}
	return (line);
}

static void	read_and_compose_line(int fd, char **collector)
{
	char	*buffer;
	char	*join;
	int		bytes_read;

	if (!*collector)
	{
		*collector = malloc(1);
		**collector = '\0';
	}
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer && *collector)
	{
		bytes_read = 1;
		while (!ft_strchr(*collector, '\n') && bytes_read != 0)
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read == -1)
				free(buffer);
			*(buffer + bytes_read) = '\0';
			join = ft_strjoin(*collector, buffer);
			free(*collector);
			*collector = join;
		}
		free(buffer);
	}
}

char	*get_next_line(int fd)
{
	static char	*collector;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	read_and_compose_line(fd, &collector);
	if (!collector)
		return (NULL);
	line = extract_line(collector);
	collector = prepare_next_line(collector);
	return (line);
}
