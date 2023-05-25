/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:32:13 by csakamot          #+#    #+#             */
/*   Updated: 2023/05/25 11:43:32 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);

char	*get_next_line(int fd)
{
	size_t					line_len;
	size_t					i;
	unsigned char			*rd_buf;
	unsigned char			*result;
	static unsigned char	*buf[OPEN_MAX];

	if (fd == -1)
		return (NULL);
	line_len = 0;
	rd_buf = (unsigned char *)malloc(sizeof(unsigned char) * BUFFER_SIZE);
	if (read(fd, rd_buf, BUFFER_SIZE))
	{
		if (rd_buf == NULL)
			return (NULL);
		while (line_len < BUFFER_SIZE && rd_buf[line_len] != '\0')
		{
			if (rd_buf[line_len] != '\n')
				line_len++;
			else
				break ;
		}
		printf("fd : %d\n", fd);
		printf("sbuf : %s\n", rd_buf);
		result = malloc(sizeof(unsigned char) * (line_len + 1));
		i = 0;
		while (i < line_len)
		{
			result[i] = rd_buf[i];
			i++;
		}
		result[i] = '\0';
	}
	return ((char *)result);
}
