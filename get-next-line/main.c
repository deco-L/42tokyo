/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:12:55 by csakamot          #+#    #+#             */
/*   Updated: 2023/05/31 02:17:06 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

// #include "leakdetect.h"
// #define malloc(s) leak_detelc_malloc(s, __FILE__, __LINE__)
// #define free leak_detect_free

// #include <libc.h>

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }

int	main(int argc, char **argv)
{
	int		count;
	int		fd;
	int		rc;
	char	*line;
	char	*line_file;

	// fd = open("./file.txt", O_RDONLY);
	// fd = 2;
	fd = open("./file.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("main.c : %s", line);
	line = get_next_line(fd);
	printf("main.c : %s", line);
	line = get_next_line(fd);
	printf("main.c : %s", line);
	line = get_next_line(fd);
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
