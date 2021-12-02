/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:13:23 by aanjaimi          #+#    #+#             */
/*   Updated: 2021/11/30 14:41:24 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<stdlib.h>
# include<stddef.h>
# include<fcntl.h>
# include<sys/types.h>
# include<unistd.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
int		line_in_str(char *str);
char	*aff_line(char *str);
char	*after_line(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*to_ret(char **str);
char	*freeee(char *str);

#endif
