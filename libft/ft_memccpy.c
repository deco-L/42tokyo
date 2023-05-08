/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayoi <yayoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 02:47:41 by yayoi             #+#    #+#             */
/*   Updated: 2023/05/09 02:53:02 by yayoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n);

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*result;
	unsigned char	*origin;

	result = (unsigned char *) dest;
	origin = (unsigned char *) src;
	if (n == 0 || dest == src)
		return (dest);
	while (n-- && *result != c)
	{
		*result = *origin;
		result++;
		origin++;
	}
	return (dest);
}
