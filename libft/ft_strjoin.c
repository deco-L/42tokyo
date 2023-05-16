/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:40:51 by sakamoto          #+#    #+#             */
/*   Updated: 2023/05/16 16:14:37 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_in(char *result, const char *s1, const char *s2, size_t len);

char	*ft_in(char *result, const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (s1[i] != '\0')
			result[i] = s1[i];
		else if (s1[i] == '\0')
		{
			result[i] = s2[j];
			j++;
		}
		i++;
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
	result = ft_in(result, s1, s2, s1_len + s2_len);
	return (result);
}
