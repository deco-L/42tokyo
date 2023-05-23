/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:32:13 by csakamot          #+#    #+#             */
/*   Updated: 2023/05/23 16:26:47 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);

char	*get_next_line(int fd)
{
	size_t			i;
	unsigned char	*sbuf;
	unsigned char	*line;

	i = 0;
	while (read(fd, sbuf, BUFFER_SIZE))
	{
		sbuf = (unsigned char *)malloc(BUFFER_SIZE * sizeof(unsigned char));
		while (i < BUFFER_SIZE)
		{
			if (sbuf[i] != '\n')
				line[]
			i++;
		}
	}
	return ((char *)line);
}
