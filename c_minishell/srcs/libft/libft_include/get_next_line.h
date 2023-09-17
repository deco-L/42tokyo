/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:50:41 by csakamot          #+#    #+#             */
/*   Updated: 2023/08/09 15:16:40 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 33
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

char		*get_next_line(int fd);
size_t		ft_strlen_gnl(const char *str);
char		*ft_strchr_gnl(const char *str, int c);
char		*ft_substr_gnl(const char *s, unsigned int start, size_t len);
char		*ft_strjoin_gnl(const char *s1, const char *s2);

#endif