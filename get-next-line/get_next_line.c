/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:32:13 by csakamot          #+#    #+#             */
/*   Updated: 2023/05/31 02:12:37 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*get_next_line(int fd);
unsigned char	*ft_buf_check(int fd, unsigned char **buf);
unsigned char	*ft_reader(char *result, int fd, unsigned char **buf, char *s1);

unsigned char	*ft_buf_check(int fd, unsigned char **buf)
{
	char			*stock;
	char			*c;
	unsigned char	*result;

	if (buf[fd] == NULL)
		return (NULL);
	c = ft_strchr((char *)buf[fd], '\n');
	if (c)
	{
		stock = (char *)buf[fd];
		buf[fd] = (unsigned char *)ft_substr(stock, c - stock + 1, ft_strlen(buf[fd]));
		result = ((unsigned char *)ft_substr((char *)stock, 0, c - stock + 1));
		return (result);
	}
	else
	{
		return (NULL);
	}
}

unsigned char	*ft_reader(char *result, int fd, unsigned char **buf, char *s1)
{
	long long		len;
	char			*c;

	len = 1;
	s1[BUFFER_SIZE] = '\0';
	while (len)
	{
		len = read(fd, s1, BUFFER_SIZE);
		if (len == -1)
			return (NULL);
		else if (len == 0)
		{
			if (result == NULL)
				return NULL;
			buf[fd] = NULL;
			return ((unsigned char *)result);
		}
		c = ft_strchr(s1, '\n');
		if (c)
		{
			result = ft_strjoin(result, ft_substr(s1, 0, c - s1 + 1));
			buf[fd] = (unsigned char *)ft_substr(s1, c - s1 + 1, len);
			printf("%p\n",buf[fd]);
			return ((unsigned char *)result);
		}
		else
			result = ft_strjoin(result, ft_substr(s1, 0, len));
	}
	printf("%p\n", result);
	return ((unsigned char *)result);
}

char	*get_next_line(int fd)
{
	char					*stock;
	unsigned char			*result;
	static unsigned char	*buf[20];

	if (fd < 0)
		return (NULL);
	result = ft_buf_check(fd, buf);
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
