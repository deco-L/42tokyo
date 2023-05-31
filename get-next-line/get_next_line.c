/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:32:13 by csakamot          #+#    #+#             */
/*   Updated: 2023/05/31 14:12:36 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*get_next_line(int fd);
unsigned char	*ft_buf_check(int fd, char **buf);
unsigned char	*ft_reader(char *result, int fd, unsigned char **buf, char *s1);
int				ft_rech(char *res, int fd, unsigned char **buf, long long len);

unsigned char	*ft_buf_check(int fd, char **buf)
{
	char			*s1;
	char			*c;
	unsigned char	*result;

	if (buf[fd] == NULL)
		return (NULL);
	c = ft_strchr((char *)buf[fd], '\n');
	if (c)
	{
		s1 = (char *)buf[fd];
		buf[fd] = ft_substr(s1, c - s1 + 1, ft_strlen((const char *)buf[fd]));
		result = ((unsigned char *)ft_substr((char *)s1, 0, c - s1 + 1));
		free(s1);
		return (result);
	}
	else
	{
		return (NULL);
	}
}

int	ft_rech(char *res, int fd, unsigned char **buf, long long len)
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

unsigned char	*ft_reader(char *result, int fd, unsigned char **buf, char *s1)
{
	long long		len;
	long long		sep;
	char			*c;

	len = 1;
	while (len)
	{
		len = read(fd, s1, BUFFER_SIZE);
		if (ft_rech(result, fd, buf, len) == 1)
			return ((unsigned char *)result);
		else if (ft_rech(result, fd, buf, len) == 0)
			return (NULL);
		s1[len] = '\0';
		c = ft_strchr(s1, '\n');
		if (c)
		{
			sep = c - s1 + 1;
			result = ft_strjoin_gnl(result, ft_substr(s1, 0, sep));
			buf[fd] = (unsigned char *)ft_substr(s1, c - s1 + 1, len - sep);
			return ((unsigned char *)result);
		}
		else
			result = ft_strjoin_gnl(result, ft_substr(s1, 0, len));
	}
	return ((unsigned char *)result);
}

char	*get_next_line(int fd)
{
	char					*stock;
	unsigned char			*result;
	static unsigned char	*buf[OPEN_MAX];

	if (fd < 0)
		return (NULL);
	result = ft_buf_check(fd, (char **)buf);
	if (result)
		return ((char *)result);
	if (buf[fd])
		result = buf[fd];
	else
		result = NULL;
	stock = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (stock == NULL)
		return (NULL);
	result = ft_reader((char *)result, fd, buf, stock);
	free(stock);
	return ((char *)result);
}
