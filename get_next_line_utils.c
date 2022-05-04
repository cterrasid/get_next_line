/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrasi <cterrasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:34:11 by cterrasi          #+#    #+#             */
/*   Updated: 2022/05/02 16:39:02 by cterrasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	const char	*s2;

	s2 = s;
	while (*s)
		s++;
	return (s - s2);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*p;
	size_t			i;

	p = malloc(count * size);
	if (p && (size <= UINT_MAX || count <= UINT_MAX))
	{
		i = 0;
		while (i < count * size)
			*(p + i++) = '\0';
		return (p);
	}
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*d;
	size_t	s_len;
	int		i;

	i = 0;
	s_len = ft_strlen(s);
	d = (char *)malloc(sizeof(char) * s_len + 1);
	if (d == NULL)
		return (NULL);
	while (s_len--)
	{
		d[i] = s[i];
		i++;
	}
	d[s_len] = '\0';
	return (d);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	slen;
	size_t	dlen;

	dlen = ft_strlen((const char *)dst);
	slen = ft_strlen(src);
	i = 0;
	j = dlen;
	if (size <= dlen)
		return (slen + size);
	while (src[i] && i < size - dlen - 1)
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (dlen + slen);
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
