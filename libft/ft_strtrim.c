/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:03:00 by csakamot          #+#    #+#             */
/*   Updated: 2023/05/18 16:19:22 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set);

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*result;
	char	*start;
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(set);
	if (len_s1 < len_s2)
		return (NULL);
	start = ft_strnstr(s1, set, len_s1);
	result = (char *)malloc(sizeof(char) * (len_s1 - len_s2 + 1));
	if (result == NULL || !(*start))
		return (NULL);
	i = 0;
	while (i < len_s1 + 1)
	{
		if (&s1[i] == start)
			i += len_s2;
		*result = s1[i];
		result++;
		i++;
	}
	result -= (len_s1 - len_s2 + 1);
	return (result);
}
