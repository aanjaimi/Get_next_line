/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:49:03 by aanjaimi          #+#    #+#             */
/*   Updated: 2021/11/30 21:55:56 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*aff_line(char *str)
{
	char	*p;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n')
		i++;
	p = ft_substr(str, 0, i + 1);
	return (p);
}

char	*after_line(char *str)
{
	char	*p;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n')
		i++;
	p = ft_substr(str, i + 1, ft_strlen(str) - i);
	free(str);
	return (p);
}

char	*to_ret(char **str)
{
	char	*line;

	line = ft_strdup(*str);
	free(*str);
	*str = NULL;
	return (line);
}

char	*freeee(char *str)
{
	if (!str)
		return (NULL);
	if (!*str)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	ssize_t		k;
	static char	*str;
	char		*line;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (line_in_str(str))
	{
		line = aff_line(str);
		str = after_line(str);
		return (free(buf), line);
	}
	k = read(fd, buf, BUFFER_SIZE);
	if (k <= 0)
	{
		str = freeee(str);
		if (str == NULL)
			return (free(buf), NULL);
		return (free(buf), to_ret(&str));
	}
	buf[k] = 0;
	str = ft_strjoin(str, buf);
	return (free(buf), get_next_line(fd));
}
