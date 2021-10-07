/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmota <mmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:42:40 by marmota           #+#    #+#             */
/*   Updated: 2021/04/20 14:56:20 by mmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (*s++)
		++i;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	if (!src && !dst)
		return (0);
	i = 0;
	while (src[i] && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	unsigned int	len;
	char			*str;

	len = ft_strlen(s);
	str = malloc(len + 1);
	if (!str)
		return (0);
	ft_strlcpy(str, s, len + 1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if ((char)c == 0)
		return (str);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*s;
	char			*ret;
	unsigned int	l1;
	unsigned int	l2;

	if (!s1 || !s2)
		return (ft_strdup(""));
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	s = malloc(sizeof(char) * (l1 + l2 + 1));
	if (!s)
		return (0);
	ret = s;
	while (l1--)
		*s++ = *s1++;
	while (l2--)
		*s++ = *s2++;
	*s = 0;
	return (ret);
}
