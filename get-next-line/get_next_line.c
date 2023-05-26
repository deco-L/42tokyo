/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:32:13 by csakamot          #+#    #+#             */
/*   Updated: 2023/05/26 21:23:05 by csakamot         ###   ########.fr       */
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
		buf[fd] = (unsigned char *)ft_substr(stock, c - stock + 1, BUFFER_SIZE);
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
	char			*c;

	while (read(fd, s1, BUFFER_SIZE) || !ft_strchr(s1, '\0'))
	{
		s1[BUFFER_SIZE] = '\0';
		c = ft_strchr(s1, '\n');
		if (c)
		{
			result = ft_strjoin(result, ft_substr(s1, 0, c - s1 + 1));
			buf[fd] = (unsigned char *)ft_substr(s1, c - s1 + 1, BUFFER_SIZE);
			free(s1);
			return ((unsigned char *)result);
		}
		else
			result = ft_strjoin(result, s1);
	}
	if (s1)
	{
		buf[fd] = NULL;
		free(s1);
		return ((unsigned char *)result);
	}
	free(s1);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char					*stock;
	unsigned char			*result;
	static unsigned char	*buf[OPEN_MAX];

	if (fd < 0)
		return (NULL);
	result = ft_buf_check(fd, buf);
	if (result)
		return ((char *)result);
	if (buf[fd])
		result = buf[fd];
	else
	{
		result = malloc(0);
		result[0] = '\0';
	}
	stock = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (stock == NULL)
		return (NULL);
	result = ft_reader((char *)result, fd, buf, stock);
	return ((char *)result);
}

// unsigned char	*ft_buf_check(int fd, unsigned char **buf)
// {
// 	char			*c;
// 	unsigned char	*result;

// 	c = ft_strchr(buf[fd], '\n');
// 	result = malloc(0);
// 	if (*c && buf[fd])
// 	{
// 		result = ft_substr(buf[fd], 0, c - buf[fd]);
// 		buf[fd] = ft_substr(buf[fd], c - buf[fd], BUFFER_SIZE);
// 	}
// 	else (!*c && buf[fd])
// 	return (result);
// }

// unsigned char	*ft_reader(int fd, unsigned char *buf)
// {
// 	char	*c;
// 	char	*result = "";
// 	char	*stock;

// 	stock = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (stock == NULL)
// 		return (NULL);
// 	while (read(fd, stock, BUFFER_SIZE))
// 	{
// 		printf("%s\n\n", stock);
// 		c = ft_strchr(stock, '\n');
// 		if (*c)
// 		{
// 			printf("substr : %s\n", ft_substr(stock, 0, c - stock));
// 			result = ft_strjoin(result, ft_substr(stock, 0, c - stock));
// 			break ;
// 		}
// 		else
// 		{
// 			printf("ok\n");
// 			ft_strjoin(result, stock);
// 			ft_reader(fd, buf);
// 		}
// 	}
// 	printf("result : %s\n\n", result);
// 	return ((unsigned char *)result);
// }

// char	*get_next_line(int fd)
// {
// 	size_t					line_len;
// 	size_t					i;
// 	unsigned char			*rd_buf;
// 	unsigned char			*result;
// 	static unsigned char	*buf[OPEN_MAX];

// 	if (fd == -1)
// 		return (NULL);
// 	line_len = 0;
// 	rd_buf = (unsigned char *)malloc(sizeof(unsigned char) * BUFFER_SIZE);
// 	if (read(fd, rd_buf, BUFFER_SIZE))
// 	{
// 		if (rd_buf == NULL)
// 			return (NULL);
// 		while (line_len < BUFFER_SIZE && rd_buf[line_len] != '\0')
// 		{
// 			if (rd_buf[line_len] != '\n')
// 				line_len++;
// 			else
// 				break ;
// 		}
// 		printf("fd : %d\n", fd);
// 		printf("sbuf : %s\n", rd_buf);
// 		result = malloc(sizeof(unsigned char) * (line_len + 1));
// 		i = 0;
// 		while (i < line_len)
// 		{
// 			result[i] = rd_buf[i];
// 			i++;
// 		}
// 		result[i] = '\0';
// 	}
// 	return ((char *)result);
// }
