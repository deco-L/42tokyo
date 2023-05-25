/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:32:13 by csakamot          #+#    #+#             */
/*   Updated: 2023/05/25 14:18:20 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*get_next_line(int fd);
unsigned char	*ft_reader(int fd, unsigned char *buf);

unsigned char	*ft_reader(int fd, unsigned char *buf)
{
	char	*c;
	char	*result;
	char	*stock;

	stock = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (stock == NULL)
		return (NULL);
	while (read(fd, stock, BUFFER_SIZE))
	{
		printf("%s\n\n", stock);
		c = ft_strchr(stock, '\n');
		if (*c)
		{
			printf("ok\n");
			ft_strjoin(result, ft_substr(stock, 0, c - stock));
			break ;
		}
		else
		{
			printf("ok\n");
			ft_strjoin(result, stock);
			ft_reader(fd, buf);
		}
	}
	printf("%s\n\n", result);
	return ((unsigned char *)result);
}

char	*get_next_line(int fd)
{
	unsigned char			*result;
	static unsigned char	*buf[OPEN_MAX];

	result = ft_reader(fd, buf[fd]);
	return ((char *)result);
}

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
