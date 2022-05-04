/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrasi <cterrasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:34:00 by cterrasi          #+#    #+#             */
/*   Updated: 2022/05/03 22:57:35 by cterrasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
RECUERDA PROBAR EN COMPOSE... TE FALTA MUY POCO!
*/

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
 * Reservo memoria con calloc,
 * @param fd El file descriptor que se va a leer.
 * @return El buffer creado, que contiene lo leído del 'fd'.
 */
static char	*read_file(int fd)
{
	char	*buffer;
	int		reading;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	//	Reservo memoria con malloc, porque así no hago bucles de más.
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	//	Leo el fd y guardo lo leído en el buffer. Además guardo el retorno en
	//	una variable (reading).
	reading = read(fd, buffer, BUFFER_SIZE);
	// Si la lectura salió mal, libero al buffer y retorno NULL.
	if (reading == -1)
	{
		free(buffer);
		return (NULL);
	}
	//	Ubico al buffer en la última posición, y lo aseguro con un nul.
	*(buffer + BUFFER_SIZE) = '\0';
	return (buffer);
}

/*	Función que se encarga de procesar la línea para extraer la línea y devolver
	el remainder, si aplica. */
// static void	extract_line(char **remainder, char **line)
// {
// 	char	*rem;

// 	rem = *remainder;
// 	while (*rem && *rem != '\n')
// 		rem++;
// 	*remainder = ft_substr(*remainder, 0, rem - *remainder);
// 	*line = ft_substr(*line, 0, rem - *remainder);
// }

/* Función que se encarga de crear la línea según el buffer */
/* El remainder es lo que queda despues del salto de línea, incluyendo al salto
	por lo que el inicio de la siguiente línea, será remainder + 1*/
static char	*compose_line(char **buffer, char **line, int fd)
{
	char	*line_remainder;
	// char	*unfinished_line;

	*buffer = read_file(fd);
	line_remainder = *line;
	ft_strlcat(*line, *buffer, ft_strlen(*line) + BUFFER_SIZE + 1);
	while (*line_remainder && *line_remainder != '\n')
		line_remainder++;
	*line = ft_substr(*line, 0, line_remainder - *line);
	// extract_line(line_remainder, new_line);
	printf("rem -> :%s:\n", line_remainder);
	printf("line_remainder in compose: :%s:\n", line_remainder + 1);
	return (line_remainder + 1);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*line;

	line = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	compose_line(&buffer, &line, fd);
	while (*line)
	{
		if (*line == '\n')
	}
	printf("line: :%s:\n", line);
	return (line);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR\n");
		return (0);
	}
	printf("result: %s\n", get_next_line(fd));
	close(fd);
	return (0);
}
