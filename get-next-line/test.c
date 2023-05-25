/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:00:52 by csakamot          #+#    #+#             */
/*   Updated: 2023/05/25 11:43:14 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

size_t	ft_strlen(const char *str);

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

// int	main(int argc, char **argv)
// {
// 	size_t			count;
// 	size_t			i;
// 	size_t			len;
// 	unsigned char	*s_test;

// 	printf("argc : %d\n", argc);
// 	count = 1;
// 	len = ft_strlen(argv[0]);
// 	s_test = (void *)malloc(sizeof(char) * (len + 1));
// 	while (count < argc)
// 	{
// 		i = 0;
// 		while (argv[count][i] != '\0')
// 		{
// 			s_test[i] = argv[count][i];
// 			i++;
// 		}
// 		argv[count][i] = '\0';
// 		count++;
// 	}
// 	printf("s_test : %s\n", s_test);
// 	free(s_test);
// 	printf("s_test : %s\n", s_test);
// 	return (0);
// }

// static array
char	**static_test(char *list, int nbr)
{
	size_t					i;
	static unsigned char	*buf[OPEN_MAX];

	i = nbr;
	while (i < 20)
	{
		buf[i] = malloc(sizeof(char) * 20);
		*buf[i] = list[i];
		i++;
	}
	return ((char **)buf);
}

int	main(void)
{
	size_t	i;
	char	**result;
	char	**result2;
	char	*list = "abcdefghijklmnopqrstuvwxyz";
	char	*list2 = "1234567890123456789012345";


	result = static_test(list, 0);
	i = 0;
	while (i < 20)
	{
		printf("result[%zu] : %s\n", i, result[i]);
		i++;
	}
	printf("\n");
	result2 = static_test(list2, 10);
	i = 0;
	while (i < 20)
	{
		printf("result2[%zu] : %s\n", i, result2[i]);
		i++;
	}
	return (0);
}
