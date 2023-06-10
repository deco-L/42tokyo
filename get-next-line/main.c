/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:12:55 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/10 18:33:57 by csakamot         ###   ########.fr       */
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

// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*line;

// 	argc = 0;
// 	fd = open(argv[1], O_RDONLY);
// 	line = get_next_line(fd);
// 	free (line);
// 	printf("main.c : %s", line);
// 	line = get_next_line(fd);
// 	free (line);
// 	printf("main.c : %s", line);
// 	line = get_next_line(fd);
// 	free (line);
// 	printf("main.c : %s", line);
// 	line = get_next_line(fd);
// 	free (line);
// 	printf("main.c : %s", line);
// 	line = get_next_line(fd);
// 	free (line);
// 	printf("main.c : %s", line);
// 	line = get_next_line(fd);
// 	free (line);
// 	printf("main.c : %s", line);

// 	printf("\n-------\n");
// 	fd = open("./test_003.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("main2.c : %s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("main2.c : %s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("main2.c : %s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("main2.c : %s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("main2.c : %s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("main2.c : %s", line);
// 	free(line);
// 	close(fd);
// 	printf("\n------\n");
// 	return (0);
// }

int	main(void)
{
	int		i;
	int		fd1;
	int		fd2;
	char	*buf1;
	char	*buf2;

	i = 0;
	fd1 = open("./test_002.txt", O_RDONLY);
	fd2 = open("./text2.txt", O_RDONLY);
	while (1)
	{
		buf1 = get_next_line(fd1);
		buf2 = get_next_line(fd2);
		printf("%s", buf1);
		printf("%s", buf2);
		free(buf1);
		free(buf2);
		if (buf1 == NULL || buf2 == NULL)
			break ;
	}
}