/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrasi <cterrasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:34:00 by cterrasi          #+#    #+#             */
/*   Updated: 2022/05/08 22:09:52 by cterrasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// static char	*extract_line(char	**collector, int len)
// {
// 	char	*line;

// 	line = ft_substr(*collector, 0, len);
// 	return (line);
// }

/* Función que se encarga de crear la línea según el buffer */
static int	compose_line(int fd, char **collector)
{
	int		bytes_read;
	char	*line;
	char	buffer[BUFFER_SIZE + 1];

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (0);
	line = malloc(sizeof(char) * bytes_read + 1);
	if (!line)
		return (0);
	*collector = ft_strdup(buffer);
	ft_strlcat(line, buffer, bytes_read + ft_strlen(*collector) + 1);
	*collector = line;
	free(*collector);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	int			i;
	char		*line;
	static char	*collector;

	i = 0;
	line = collector;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	compose_line(fd, &collector);
	// while (*collector != '\n')
	// {
	// 	collector++;
	// }
	compose_line(fd, &collector);
	printf("line: %s\n", line);
	return (collector);
}
