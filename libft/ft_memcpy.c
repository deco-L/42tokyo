/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 03:26:24 by yayoi             #+#    #+#             */
/*   Updated: 2023/05/16 16:14:09 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*result;
	unsigned char	*origin;

	result = (unsigned char *) dest;
	origin = (unsigned char *) src;
	if (n == 0 || dest == src)
		return (dest);
	while (n--)
	{
		*result = *origin;
		result++;
		origin++;
	}
	return (dest);
}
