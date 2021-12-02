/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:47:57 by aanjaimi          #+#    #+#             */
/*   Updated: 2021/11/30 15:48:00 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*str[1024];
	char		*line;
	char		buf[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (line_in_str(str[fd]))
	{
		line = aff_line(str[fd]);
		str[fd] = after_line(str[fd]);
		return (line);
	}
	k = read(fd, buf, BUFFER_SIZE);
	if (k <= 0)
	{
		str[fd] = freeee(str[fd]);
		if (str[fd] == NULL)
			return (NULL);
		return (to_ret(&str[fd]));
	}
	buf[k] = 0;
	str[fd] = ft_strjoin(str[fd], buf);
	return (get_next_line(fd));
}
