/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:12:55 by csakamot          #+#    #+#             */
/*   Updated: 2023/05/23 21:32:31 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		rc;
	char	*line;
	char	*line_file;

	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	printf("fd : %d\n", fd);
	close(fd);
	printf("%d\n", fd);

	fd = open("./file.txt", O_RDONLY);
	line_file = get_next_line(fd);
	printf("%s\n", line_file);
	printf("%d\n", fd);
	close(fd);
	printf("%d\n", fd);
	// free(line);
	// free(line_file);
	return (0);
}
