/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:32:06 by csakamot          #+#    #+#             */
/*   Updated: 2023/05/26 02:54:40 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *str, int c);
char		*ft_substr(const char *s, unsigned int start, size_t len);
char		*ft_strjoin(const char *s1, const char *s2);
static char	*ft_in_strjoin(char *result, const char *s1, const char *s2);

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *str, int c)
{
	int				i;
	int				flag;
	unsigned char	cbuf;
	unsigned char	*result;

	i = 0;
	flag = 0;
	result = (unsigned char *)str;
	cbuf = (unsigned char)c;
	if (cbuf == '\0')
		flag++;
	while (result[i] != '\0')
	{
		if (result[i] == cbuf)
			return ((char *)&result[i]);
		i++;
	}
	if (flag)
		return ((char *)&result[i]);
	return (NULL);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*result;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return ((char *)malloc(1));
	i = 0;
	result = (char *)malloc(len + 1);
	if (result == NULL)
		return (NULL);
	while (i < len && s[start] != '\0')
	{
		result[i] = s[start];
		start++;
		i++;
	}
	result[i] = '\0';
	return (result);
}

static char	*ft_in_strjoin(char *result, const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (result == NULL)
		return (NULL);
	result = ft_in_strjoin(result, s1, s2);
	return (result);
}
