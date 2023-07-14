/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:14:58 by csakamot          #+#    #+#             */
/*   Updated: 2023/07/14 21:43:53 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_buf_check(int fd, char **buf)
{
	char	*s1;
	char	*c;
	char	*result;

	if (buf[fd] == NULL)
		return (NULL);
	c = ft_strchr(buf[fd], '\n');
	if (c)
	{
		s1 = buf[fd];
		buf[fd] = ft_substr(s1, c - s1 + 1, ft_strlen((const char *)buf[fd]));
		result = (ft_substr(s1, 0, c - s1 + 1));
		free(s1);
		return (result);
	}
	else
		return (NULL);
}

int	ft_read_check(char *res, int fd, char **buf, long long len)
{
	if (len == -1)
		return (0);
	else if (len == 0)
	{
		if (!ft_strlen(res))
			return (0);
		buf[fd] = NULL;
		return (1);
	}
	return (2);
}

char	*ft_input(char *result, int fd, char **buf, char *s1)
{
	long long	len;
	char		*c;

	len = 1;
	while (len)
	{
		len = read(fd, s1, BUFFER_SIZE);
		if (ft_read_check(result, fd, buf, len) == 1)
			return (result);
		else if (ft_read_check(result, fd, buf, len) == 0)
		{
			free(result);
			return (NULL);
		}
		s1[len] = '\0';
		c = ft_strchr(s1, '\n');
		if (c)
		{
			result = ft_strjoin_gnl(result, ft_substr(s1, 0, c - s1 + 1));
			buf[fd] = ft_substr(s1, c - s1 + 1, len - (c - s1 + 1));
			return (result);
		}
		result = ft_strjoin_gnl(result, ft_substr(s1, 0, len));
	}
	return (result);
}

char	*get_next_line(int fd)
{
	char			*stock;
	char			*result;
	static char		*buf[FOPEN_MAX] = {NULL};

	if (fd < 0)
		return (NULL);
	result = ft_buf_check(fd, buf);
	if (result)
		return ((char *)result);
	if (buf[fd])
		result = buf[fd];
	stock = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (stock == NULL)
		return (NULL);
	result = ft_input(result, fd, buf, stock);
	free(stock);
	return ((char *)result);
}
