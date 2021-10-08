/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmota <marmota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 15:33:22 by marmota           #+#    #+#             */
/*   Updated: 2021/10/08 13:09:48 by marmota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ret_line(int fd, char **s, char **l)
{
	char	*tmp;
	char	*nl;

	nl = ft_strchr(s[fd], '\n');
	*nl++ = '\0';
	*l = ft_strdup(s[fd]);
	tmp = ft_strdup(nl);
	free(s[fd]);
	s[fd] = tmp;
	return (1);
}

static int	save_line(int fd, char *buf, char **s)
{
	char	*tmp;

	if (!s[fd])
		s[fd] = ft_strdup(buf);
	else
	{
		tmp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = tmp;
	}
	if (ft_strchr(s[fd], '\n'))
		return (1);
	return (0);
}

static int	ret_eof(int fd, char **s, char **l)
{
	if (!s[fd])
		*l = ft_strdup("");
	else
		*l = ft_strdup(s[fd]);
	free(s[fd]);
	s[fd] = NULL;
	return (0);
}

static int	read_line(int fd, char **s, char **l)
{
	int			br;
	char		*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	br = read(fd, buf, BUFFER_SIZE);
	while (br > 0)
	{
		buf[br] = '\0';
		if (save_line(fd, buf, s))
			break ;
		br = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (br < 0)
		return (-1);
	if (!s[fd] || !ft_strchr(s[fd], '\n'))
		return (ret_eof(fd, s, l));
	return (ret_line(fd, s, l));
}

int	get_next_line(int fd, char **line)
{
	static char	*store[FD_MAX];

	if (fd < 0 || fd >= FD_MAX || !line)
		return (-1);
	return (read_line(fd, store, line));

}
