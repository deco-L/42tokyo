/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:50:41 by csakamot          #+#    #+#             */
/*   Updated: 2023/05/31 13:09:06 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 33
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