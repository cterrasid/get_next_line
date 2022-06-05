/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrasi <cterrasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:34:04 by cterrasi          #+#    #+#             */
/*   Updated: 2022/06/04 21:56:46 by cterrasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif /* BUFFER_SIZE */

/**
* @brief Calculates the length of a given string 's'.
*/
size_t	ft_strlen(const char *s);

/**
* @brief Allocates memory with malloc(), to return a new string based on 's'.
* The new string begins at 'start' and has a max length of 'len'.
* @param str The reference string to form the substring.
* @param start The index of 'str' from which the substring will be created.
* @param max_len The maximum length of the substring.
* @returns Pointer to the obtained substring.
*/
char	*ft_substr(const char *str, unsigned int start, size_t max_len);

/**
* @brief Allocates memory with malloc() to create a new string,
* based on the join	of 's1' and 's2'.
* @param s1	The prefix string.
* @param s2	The sufix string.
* @returns Pointer to the string created from the join of 's1' and 's2'.
*/
char	*ft_strjoin(char *s1, char *s2);

/**
* @brief Copies 'n' bytes of the memory area pointed by 'src',
* to the memory area pointed by 'dest'.
* @param dst Memory area where will be copied 'n' bytes of 'src'.
* @param src Memory area from where will be copied 'n' bytes
* to 'dst'.
* @param n Bytes of 'src' which will be copied to 'dst'.
* @returns Pointer to 'dst'.
*/
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strchr(const char *str, int ch);
char	*get_next_line(int fd);

#endif /* GET_NEXT_LINE_H */
