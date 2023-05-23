/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:32:13 by csakamot          #+#    #+#             */
/*   Updated: 2023/05/23 17:12:20 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);

char	*get_next_line(int fd)
{
	size_t			line_len;
	size_t			i;
	unsigned char	*sbuf;
	unsigned char	*line;

	line_len = 0;
	while (read(fd, sbuf, BUFFER_SIZE))
	{
		sbuf = (unsigned char *)malloc(sizeof(unsigned char) * BUFFER_SIZE);
		if (sbuf == NULL)
			return (NULL);
		while (line_len < BUFFER_SIZE)
		{
			if (sbuf[line_len] != '\n')
				line_len++;
		}
		sbuf = (unsigned char *)malloc(sizeof(unsigned char) * (line_len + 1));
		i = 0;
		while (i < line_len)
		{
			line[i] = sbuf[i];
			i++;
		}
		free(sbuf);
	}
	return ((char *)line);
}
