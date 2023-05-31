/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:12:55 by csakamot          #+#    #+#             */
/*   Updated: 2023/05/31 14:02:55 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

// #include "leakdetect.h"
// #define malloc(s) leak_detelc_malloc(s, __FILE__, __LINE__)
// #define free leak_detect_free

#include <libc.h>

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	argc = 0;
	// fd = open("./file.txt", O_RDONLY);
	// fd = 2;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	free (line);
	printf("main.c : %s", line);
	line = get_next_line(fd);
	free (line);
	printf("main.c : %s", line);
	line = get_next_line(fd);
	free (line);
	printf("main.c : %s", line);
	line = get_next_line(fd);
	free (line);
	printf("main.c : %s", line);
	line = get_next_line(fd);
	free (line);
	printf("main.c : %s", line);
	line = get_next_line(fd);
	free (line);
	printf("main.c : %s", line);
	printf("fd : %d\n", fd);
	printf("%d\n", fd);

	// fd = open("./test_003.txt", O_RDONLY);
	// count = 0;

	// line_file = get_next_line(fd);
	// printf("main.c : %s", line_file);
	// // fd = open("./file2.txt", O_RDONLY);
	// line_file = get_next_line(fd);
	// printf("main2.c : %s", line_file);
	// line_file = get_next_line(fd);
	// printf("main.c : %s", line_file);
	// line_file = get_next_line(fd);
	// printf("main.c : %s", line_file);
	// line_file = get_next_line(fd);
	// printf("main.c : %s", line_file);
	// line_file = get_next_line(fd);
	// printf("main.c : %s", line_file);
	// free(line_file);
	// printf("fd : %d\n", fd);
	// close(fd);
	// printf("%d\n", fd);
	// free(line);

	return (0);
}
