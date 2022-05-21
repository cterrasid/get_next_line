/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrasi <cterrasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:21:24 by cterrasi          #+#    #+#             */
/*   Updated: 2022/05/21 21:41:21 by cterrasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Funciona con BUFFER_SIZE bajo... si es un valor muy grande, explota y no se por que.*/
#include "get_next_line.h"

static char	*extract_line(char **collector, int max_len)
{
	char	*line;

	line = ft_substr(*collector, 0, max_len);
	*collector += max_len;
	return (line);
}

/*	Se encarga de leer y componer la línea.
	Recibe el collector, y lo modifica.
	El collector, puede venir vacío (estado inicial) o con el resto de la línea.
*/
static int	read_and_compose_line(int fd, char **collector)
{
	char	buffer[BUFFER_SIZE];
	char	*line;
	int		bytes_read;

	/*	Leo el fd y retorno los bytes leídos.
		El collector no ha sido modificado.
	*/
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (0);
	/*	Reservo memoria para la línea, con una longitud inicial
	de los bytes leídos (bytes_read) + 1 */
	line = malloc(sizeof(char) * (bytes_read + 1));
	if (!line)
		return (0);
	/*	Concateno lo que he leido (buffer), con lo que tenga en la línea;
	puede que tenga algo o que no tenga nada, porque ella tendrá lo que
	tenga en el collector en el momento... */
	ft_strlcat(line, buffer, bytes_read + ft_strlen(line) + 1);
	*collector = line;
	free(line);
	// free(*collector);
	line = NULL;
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	int			i;
	static char	*collector;

	i = 0;
	/*	Modifico el collector con la primera lectura.*/
	read_and_compose_line(fd, &collector);
	/*	Solo itero si tengo algo en el collector. */
	while (collector)
	{
		read_and_compose_line(fd, &collector);
		printf("%s\n", collector);
		while (collector[i])
		{
			if (collector[i] == '\n')
				return (extract_line(&collector, i));
			i++;
		}
	}
	return (collector);
}

/* 	Creo que el collector está avanzando según lo que lee y no
	*/
