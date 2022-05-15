/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrasi <cterrasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:21:24 by cterrasi          #+#    #+#             */
/*   Updated: 2022/05/15 16:18:00 by cterrasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	// NECESITO DESCUBRIR COMO INICIAR LA LÍNEA....
#include "get_next_line.h"

static char	*extract_line(char **collector, int max_len)
{
	char	*line;

	line = ft_substr(*collector, 0, max_len);
	*collector += max_len;
	return (line);
}

/*	Se supone que el collector entra aquí con el resto de la línea (si aplica). */
static int	read_and_compose_line(int fd, char **collector)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*line;
	int		bytes_read;

	/*	Leo el fd y retorno los bytes leídos. */
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (0);
	/*	Reservo memoria para la línea, con una longitud inicial
	de los bytes leídos (bytes_read) */
	line = malloc(sizeof(char) * (bytes_read + 1));
	if (!line)
		return (0);
	/*	Guardo lo que sea que tenga en el collector, en la línea.
	El collector puede entrar a esta función con su valor inicial (NULL)
	o con el resto de la línea (donde dejé el puntero al extraer lo que hay
	antes del salto de línea (\n)). */
	// line = ft_strdup(*collector);
	// ft_strlcpy(line, *collector, bytes_read + 1);
	/*	Como ya he copiado lo que sea que tenga dentro de collector,
	puedo liberar la memoria que ocupa. */
	printf("collector: %s\n", *collector);
	// free(*collector);
	// printf("freed_collector: %s\n", *collector);
	/*	Concateno lo que he leido (buffer), con lo que tenga en la línea;
	puede que tenga algo o que no tenga nada, porque ella tendrá lo que
	tenga en el collector... */
	printf("line: %s\n", line);
	ft_strlcat(line, buffer, bytes_read + ft_strlen(line) + 1);
	*collector = line;
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	int			i;
	int			bytes;
	char		*test;
	static char	*collector;

	i = 0;
	/*	Modifico el collector con la primera lectura*/
	read_and_compose_line(fd, &collector);
	/*	Solo itero si tengo algo en el collector. */
	while (collector)
	{
		bytes = read_and_compose_line(fd, &collector);
		// printf("bytes: %i\n", bytes);
		while (collector[i])
		{
			if (collector[i] == '\n')
			{
				test = extract_line(&collector, i + 1);
				return (test);
			}
			i++;
		}
		if (bytes == 0)
			break ;
	}
	return (collector);
}
