/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:32:13 by csakamot          #+#    #+#             */
/*   Updated: 2023/05/23 21:30:28 by csakamot         ###   ########.fr       */
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
	sbuf = (unsigned char *)malloc(sizeof(unsigned char) * BUFFER_SIZE);
	if (read(fd, sbuf, BUFFER_SIZE))
	{
		if (sbuf == NULL)
			return (NULL);
		while (line_len < BUFFER_SIZE && sbuf[line_len] != '\0')
		{
			if (sbuf[line_len] != '\n')
				line_len++;
		}
		printf("sbuf : %s\n",sbuf);
		line = (unsigned char *)malloc(sizeof(unsigned char) * (line_len + 1));
		i = 0;
		while (i < line_len)
		{
			line[i] = sbuf[i];
			i++;
		}
		line[i] = '\0';
		// free(sbuf);
	}
	return ((char *)line);
}
