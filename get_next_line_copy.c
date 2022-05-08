/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrasi <cterrasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:34:00 by cterrasi          #+#    #+#             */
/*   Updated: 2022/05/08 14:40:29 by cterrasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// PASOS
// 1. Crear un buffer con suficiente espacio para guardar lo
// que leo. Funciona con malloc o creando la variable con el tamaño definido.
// 2. Creo una variable estática para guardar la línea.
// 2. Leo el fd por primera vez (con el read directamente o con una funcion)
// 3. Guardo esa primera lectura en la variable que contiene la línea.
// 4. Limpio el buffer.
// 6. Empiezo a componer la línea con una funcion que concatena lo que tenga en una static
// más lo que tenga en el buffer.
// 	6.1 Necesito encontrar la posición del '\n', entonces hago una especie de strrchr
//		moviendo el puntero hasta la coincidencia con el caracter y restándolo con un
//		puntero en la posición inicial.
	// 6.1 Busco la posición del '\n' en el buffer original
	// Necesito una función que revise el buffer
	// realiza una copia del buffer hasta que consiga el '\n'
	// retorna al puntero del buffer original hasta esa posición
	// la copia del buffer es la que voy a meter en la línea
	// Si consigo un '\n', entonces lo 
	// No tengo que modificar el buffer, sino la línea... La línea tomará todo el buffer
	// la línea final 

/**
 * @brief Lee un 'fd' y guarda lo leído en un buffer.
 * 
 * @param fd El file descriptor que se va a leer.
 * @return El buffer creado, que contiene lo leído del 'fd'.
 */

static char	*read_file(int fd, int *bytes_read)
{
	char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	*bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (*bytes_read < 0)
		return (NULL);
	return (buffer);
}

/*	Se encarga de comprobar si la línea contiene un '\n';
	Si contiene un '\n', lo extrae con ft_substr.
*/
// static void	extract_line(char **line)
// {
// 	int	i;

// 	i = 0;
// 	while (line[0][i])
// 	{
// 		if (line[0][i] == '\n')
// 			break ;
// 		i++;
// 	}
// 	*line = ft_substr(*line, 0, i);
// }

/* Función que se encarga de crear la línea según el buffer */
static void	compose_line(int fd, char **collector, char **buffer, int *bytes)
{
	int		collector_len;

	*buffer = read_file(fd, bytes);
	*collector = malloc(sizeof(char) * *bytes + 1);
	if (!collector)
		collector = NULL;
	collector_len = ft_strlen(*collector);
	ft_strlcat(*collector, *buffer, collector_len + *bytes + 1);
}

char	*get_next_line(int fd)
{
	int			state;
	int			bytes_read;
	char		*buffer;
	static char	*collector;

	state = 0;
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	compose_line(fd, &collector, &buffer, &bytes_read);
	if (buffer)
	printf("last: %c\n", buffer[bytes_read - 1]);
	printf("collector: %s\n", collector);
	printf("buffer: %s\n", buffer);
	printf("bytes_read: %i\n", bytes_read);
	return (collector);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		printf("ERROR\n");
	printf("result: %s\n", get_next_line(fd));
	close(fd);
	return (0);
}
