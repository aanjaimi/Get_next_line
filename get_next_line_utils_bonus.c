/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:49:40 by aanjaimi          #+#    #+#             */
/*   Updated: 2021/11/30 15:49:49 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char	*src)
{
	int		i;
	int		j;
	char	*dest;
	char	*p;

	i = 0;
	p = (char *)src;
	while (p[i] != 0)
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	j = 0;
	while (j < i)
	{
		dest[j] = p[j];
		j++;
	}
	dest[j] = 0;
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (!s)
		return (NULL);
	if (start < ft_strlen(s))
	{
		if (ft_strlen(s) < len)
			len = ft_strlen(s);
		ptr = (char *)malloc(len + 1);
		if (!ptr)
			return (NULL);
		while (i < len)
			ptr[i++] = s[start++];
	}
	else
		ptr = malloc(1);
	if (!ptr)
		return (ptr);
	*(ptr + i) = 0;
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tp;
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	if (!s1)
		s1 = ft_strdup("");
	tp = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!tp)
		return (NULL);
	while (s1[i])
	{
		tp[i] = s1[i];
		i++;
	}
	while (s2[x])
		tp[i++] = s2[x++];
	free(s1);
	tp[i] = '\0';
	return (tp);
}

int	line_in_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
