/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrasi <cterrasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:34:04 by cterrasi          #+#    #+#             */
/*   Updated: 2022/05/06 16:45:54 by cterrasi         ###   ########.fr       */
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
* @brief Duplicates the string 's'. The memory obtained
* is done dynamically using malloc().
* @returns Pointer to a null-terminated byte string, which is a duplicate
* of the string pointed by 's'.
*/
char	*ft_strdup(const char *s);

/**
* @brief Appends at most 'size - strlen(dst) - 1' bytes of 'src' to 'dst'.
* @param dst The destination buffer.
* @param src The string to append to 'dst'.
* @param dstsize The size of the final string, including the NUL.
* @returns The combined length of 'src' and 'dst' (not counting their
* terminating null characters).
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

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
* @brief Copies a string 'src' to a destination buffer 'dst'.
* @param dst The string where will be copied 'size - 1' bytes of 'src'.
* @param src The string to copy in 'dst'.
* @param size The bytes of 'src' to copy in 'dst', including the NUL.
* @returns The length of 'src'.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

char	*get_next_line(int fd);

#endif /* GET_NEXT_LINE_H */
