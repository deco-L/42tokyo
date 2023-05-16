/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:14:22 by sakamoto          #+#    #+#             */
/*   Updated: 2023/05/16 16:14:07 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t size);

int	ft_memcmp(const void *s1, const void *s2, size_t size)
{
	size_t		i;
	const char	*c1;
	const char	*c2;

	i = 0;
	c1 = (const char *)s1;
	c2 = (const char *)s2;
	while (i < size && c1[i] != '\0' && c2[i] != '\0')
	{
		if (c1[i] != c2[i])
			break ;
		i++;
	}
	return (c1[i] - c2[i]);
}
