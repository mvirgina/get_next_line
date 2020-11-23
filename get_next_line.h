/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvirgina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:10:53 by mvirgina          #+#    #+#             */
/*   Updated: 2020/11/23 11:38:54 by mvirgina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
int		get_next_line(int fd, char **line);

#endif
