/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrasi <cterrasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:34:04 by cterrasi          #+#    #+#             */
/*   Updated: 2022/07/09 18:04:21 by cterrasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

void	*ft_memcpy(void *dest, const void *src, size_t n);

char	*ft_strjoin(char *s1, char *s2);

char	*ft_substr(const char *str, unsigned int start, size_t max_len);

char	*ft_strchr(const char *str, int ch);

size_t	ft_strlen(const char *s);

char	*get_next_line(int fd);

#endif
