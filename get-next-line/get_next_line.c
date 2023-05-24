/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:32:13 by csakamot          #+#    #+#             */
/*   Updated: 2023/05/24 17:32:23 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);

char	*get_next_line(int fd)
{
	size_t					line_len;
	size_t					i;
	static unsigned char	*sbuf;
	unsigned char			*line;

	if (fd == -1)
		return (NULL);
	line_len = 0;
	sbuf = (unsigned char *)malloc(sizeof(unsigned char) * BUFFER_SIZE);
	if (read(fd, sbuf, BUFFER_SIZE))
	{
		if (sbuf == NULL)
			return (NULL);
		while (line_len < BUFFER_SIZE)
		{
			if (sbuf[line_len] != '\n')
				line_len++;
			else
				break ;
		}
		printf("fd : %d\n", fd);
		printf("sbuf : %s\n",sbuf);
		printf("end : %d\n", sbuf[8]);
		line = (unsigned char *)malloc(sizeof(unsigned char) * (line_len + 1));
		i = 0;
		while (i < line_len)
		{
			line[i] = sbuf[i];
			i++;
		}
		line[i] = '\0';
	}
	return ((char *)line);
}
