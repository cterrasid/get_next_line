/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrasi <cterrasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:21:24 by cterrasi          #+#    #+#             */
/*   Updated: 2022/05/29 17:30:05 by cterrasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*	Esta función se encarga de extraer la línea (desde el inicio hasta el primer \n)
	del *collector. Pasos:
	1. Creo una variable char *str, que me va a servir para determinar
	cuantas posiciones hay hasta el \n.
	2. Igualo el *str, al *collector.
	3. Itero sobre *str mientras sea diferente a \n. De este modo, aumento
	a *str y luego podré hacer resta de punteros para determinar lo descrito
	en 1.
	4. Luego de iterar, hago un ft_substr:
		- De el *collector,
		- empezando por la posición 0,
		- voy a extraer un máximo de (str - *collector) <- Esto es una resta de punteros.
	5. Avanzo al *collector hasta el salto de línea.
*/
static void	extract_line(char **collector, char **line)
{
	char	*str;

	str = *collector;
	while (*str != '\n')
		str++;
	*line = ft_substr(*collector, 0, str - *collector);
	*collector += (str - *collector);
}

/*	Esta función se encarga de detectar si tengo \n dentro de un str (el collector).
	Es una adaptación del ft_strchr. Pasos:
	1. Verifico que llegue un str válido; si lo es, continúo, si no, retorno NULL.
	2. Itero sobre el str:
		- Si un caracter de str es igual a \n, retorno el str en la 
		última posicion (CREO).
		- Si no consigo a \n, retorno NULL. */
static char	*is_newline(char *str)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == '\n')
		{
			// printf("CREO: %lu\n", *str + ft_strlen(str));
			// printf("CREO222: %i\n", *str);
			return (str + ft_strlen(str));
		}
			// Este return (str + ft_strlen(str));
			// o este return (str); ...DUDOSO...
		str++;
	}
	/*	Si devuelve NULL, significa que no ha encontrado un \n. */
	return (NULL);
}

/*	Esta función se encarga de leer y componer la línea, transformando a
	el *collector. Pasos:
	1. Creo dos variables:
		- int	bytes_read, para almacenar la cantidad de bytes leídos.
		- char	*buffer, para almacenar el contenido de lo que he leído.
	2. Reservo memoria para el buffer, con un tamaño de lo definido en
	BUFFER_SIZE.
	3. Si la reserva sale bien, realizo el procedimiento:
		- Itero mientras lo que consiga en *collector no sea un \n;
		creo (!is_newline(*collector)).
		- Dentro del bucle, leo lo que tengo en el fd, lo guardo en el
		buffer y devuelvo los bytes leidos.
		- Si la lectura sale mal (bytes_read < 0), entonces libero el buffer.
		- Si la lectura sale bien, agrego un \0 en la última posición del buffer, y
		- concateno dentro del collector, lo que tenga en él, más lo que tengo
		en el buffer.
		- Por último libero al buffer.
*/
static void	read_and_compose_line(int fd, char **collector)
{
	int		bytes_read;
	char	*buffer;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer)
	{
		while (!is_newline(*collector))
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read < 0)
				free(buffer);
			*(buffer + bytes_read) = '\0';
			*collector = ft_strjoin(*collector, buffer);
		}
		free(buffer);
	}
}

char	*get_next_line(int fd)
{
	static char	*collector;
	char		*line;

	read_and_compose_line(fd, &collector);
	extract_line(&collector, &line);
	return (line);
}
