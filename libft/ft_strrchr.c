/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:47:31 by csakamot          #+#    #+#             */
/*   Updated: 2023/05/16 20:28:04 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strrchr(const char *s, int c);

char	*strrchr(const char *s, int c)
{
	int		i;
	int		buff;
	char	*s1;

	i = 0;
	buff = 0;
	s1 = (char *)s;
	while (s1[i] != '\0')
	{
		if (s1[i] == c)
			buff = i;
		i++;
	}
	if (buff)
		return (s1[buff]);
	return (NULL);
}
