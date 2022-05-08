/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrasi <cterrasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:34:00 by cterrasi          #+#    #+#             */
/*   Updated: 2022/05/08 19:08:21 by cterrasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Lee un 'fd' y guarda lo leído en un buffer.
 * 
 * @param fd El file descriptor que se va a leer.
 * @return El buffer creado, que contiene lo leído del 'fd'.
 */
static int	read_file(int fd, char **buffer)
{
	int		bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		bytes_read = 0;
	*buffer[bytes_read] = '\0';
	return (bytes_read);
}

// static char	*extract_line(char	**collector, int len)
// {
// 	char	*line;

// 	line = ft_substr(*collector, 0, len);
// 	return (line);
// }

/* Función que se encarga de crear la línea según el buffer */
static char	*compose_line(int fd, char **collector)
{
	int		bytes_read;
	char	*buffer;
	char	*line;

	buffer = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	bytes_read = read_file(fd, &buffer);
	printf("buffer: %s\n", buffer);
	printf("bytes_read: %d\n", bytes_read);
	line = ft_strdup(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	int			i;
	static char	*collector;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	compose_line(fd, &collector);
	printf("collector: %s\n", collector);
	return (collector);
}
