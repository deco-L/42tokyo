/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 02:47:41 by yayoi             #+#    #+#             */
/*   Updated: 2023/05/16 16:14:00 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n);

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	int				flag;
	size_t			i;
	unsigned char	*result;
	unsigned char	*origin;

	flag = 0;
	i = 0;
	result = (unsigned char *) dest;
	origin = (unsigned char *) src;
	while (i < n)
	{
		if (result[i] == c)
		{
			flag = 1;
			break ;
		}
		result[i] = origin[i];
		i++;
	}
	if (flag == 1)
	{
		dest = (void *)&result[i + 1];
		return (dest);
	}
	return (NULL);
}
