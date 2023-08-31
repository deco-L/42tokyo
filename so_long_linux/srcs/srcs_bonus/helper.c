/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 23:05:41 by csakamot          #+#    #+#             */
/*   Updated: 2023/08/31 17:40:40 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_linux.h"

int	ft_strrncmp(const char *s1, const char *s2, size_t n)
{
	size_t				c1_len;
	size_t				c2_len;

	c1_len = ft_strlen(s1);
	c2_len = ft_strlen(s2);
	if (n == 0)
		return (0);
	while (n-- && s1[--c1_len] != '\0' && s2[--c2_len] != '\0')
	{
		if (s1[c1_len] != s2[c2_len])
			break ;
	}
	return (s1[c1_len] - s2[c2_len]);
}

static char	*ft_in_strjoin(char *result, const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i] != '\0')
		{
			result[i] = s1[i];
			i++;
		}
	}
	if (s2)
	{
		while (s2[j] != '\0')
		{
			result[i] = s2[j];
			i++;
			j++;
		}
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin_solong(const char *s1, const char *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL)
		s1_len = 0;
	else
		s1_len = ft_strlen(s1);
	if (s2 == NULL)
		s2_len = 0;
	else
		s2_len = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (result == NULL)
	{
		free((void *)s1);
		free((void *)s2);
		return (NULL);
	}
	result = ft_in_strjoin(result, s1, s2);
	free((void *)s1);
	free((void *)s2);
	return (result);
}
