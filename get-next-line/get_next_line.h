/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:32:16 by csakamot          #+#    #+#             */
/*   Updated: 2023/05/31 14:13:59 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

char		*get_next_line(int fd);
size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *str, int c);
char		*ft_substr(const char *s, unsigned int start, size_t len);
char		*ft_strjoin_gnl(const char *s1, const char *s2);

#endif