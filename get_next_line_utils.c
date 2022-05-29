/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrasi <cterrasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:34:11 by cterrasi          #+#    #+#             */
/*   Updated: 2022/05/29 17:30:03 by cterrasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	const char	*s2;

	/*	Modificación del strlen:
		- Si la str llega NULL, la longitud es 0.*/
	if (!s)
		return (0);
	s2 = s;
	while (*s)
		s++;
	return (s - s2);
}

char	*ft_substr(const char *str, unsigned int start, size_t max_len)
{
	unsigned int	i;
	size_t			slen;
	size_t			substr_len;
	char			*substring;

	if (!str)
		return (NULL);
	i = 0;
	slen = ft_strlen(str);
	substr_len = ft_strlen(str + start);
	if (slen < start)
		max_len = 0;
	if (substr_len < max_len)
		max_len = substr_len;
	substring = (char *)malloc(sizeof(char) * max_len + 1);
	if (!substring)
		return (NULL);
	while (max_len--)
		substring[i++] = str[start++];
	substring[i] = '\0';
	return (substring);
}

// char	*ft_strchr(char *str, int ch)
// {
// 	size_t	len_str;

// 	len_str = ft_strlen(str);
// 	if (!str)
// 		return (NULL);
// 	while (*str)
// 	{
// 		if (*str == (char)ch)
// 			return (str + len_str);
// 		str++;
// 	}
// 	if (ch == '\0')
// 		return (str + len_str);
// 	return (NULL);
// }

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*str;

	/*	Modificación para cuando s1 llegue NULL.
		- Si llega NULL, reservo un espacio en memoria,
		- y ahora s1 es igual a \0.*/
	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		*s1 = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, s1len);
	ft_memcpy(str + s1len, s2, s2len);
	str[s1len + s2len] = '\0';
	return (str);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int	i;

	i = 0;
	if ((dest == '\0' && src == '\0') || !n)
		return (dest);
	while (n--)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
