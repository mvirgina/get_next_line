/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvirgina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:55:22 by mvirgina          #+#    #+#             */
/*   Updated: 2020/11/23 12:10:28 by mvirgina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_str_new(unsigned int size)
{
	char	*str;

	if (!(str = malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}

static void	ft_str_clear(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

static char	*ft_calc_remains(char **rem, char **line)
{
	char *ptr_n;

	ptr_n = NULL;
	if (*rem)
		if ((ptr_n = ft_strchr(*rem, '\n')))
		{
			*ptr_n = '\0';
			*line = ft_strdup(*rem);
			ptr_n++;
			ft_strcpy(*rem, ptr_n);
		}
		else
		{
			*line = ft_strdup(*rem);
			ft_str_clear(&(*rem));
		}
	else
		*line = ft_str_new(0);
	return (ptr_n);
}

static int	ft_no_leaks(char *buf, char **line)
{
	char	*tmp;

	tmp = *line;
	if (!(*line = ft_strjoin(*line, buf)))
		return (-1);
	free(tmp);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	char		*buf;
	size_t		byte_read;
	static char	*rem[256];
	char		*ptr_n;

	if (!(buf = (char*)malloc(BUFFER_SIZE + 1)) || (read(fd, buf, 0) < 0) ||
			!line || BUFFER_SIZE <= 0 || fd > 255)
		return (-1);
	ptr_n = ft_calc_remains(&rem[fd], line);
	while (!ptr_n && (byte_read = read(fd, buf, BUFFER_SIZE)))
	{
		buf[byte_read] = '\0';
		if ((ptr_n = ft_strchr(buf, '\n')))
		{
			*ptr_n = '\0';
			if (!(rem[fd] = ft_strdup(++ptr_n)))
				return (-1);
		}
		if (ft_no_leaks(buf, line) == -1)
			return (-1);
	}
	ft_str_clear(&buf);
	return (ptr_n ? 1 : 0);
}
