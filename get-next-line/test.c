/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:00:52 by csakamot          #+#    #+#             */
/*   Updated: 2023/05/23 16:14:23 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str);

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	main(int argc, char **argv)
{
	size_t			count;
	size_t			i;
	size_t			len;
	unsigned char	*s_test;

	printf("argc : %d\n", argc);
	count = 1;
	len = ft_strlen(argv[0]);
	s_test = (void *)malloc(sizeof(char) * (len + 1));
	while (count < argc)
	{
		i = 0;
		while (argv[count][i] != '\0')
		{
			s_test[i] = argv[count][i];
			i++;
		}
		argv[count][i] = '\0';
		count++;
	}
	printf("s_test : %s\n", s_test);
	free(s_test);
	printf("s_test : %s\n", s_test);
	return (0);
}
