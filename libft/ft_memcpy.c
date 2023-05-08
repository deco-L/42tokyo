/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakamoto <sakamoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 03:26:24 by yayoi             #+#    #+#             */
/*   Updated: 2023/05/08 16:38:11 by sakamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n);

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*result;
	unsigned char	*origin;

	result = (unsigned char *) dst;
	origin = (unsigned char *) src;
	if (n == 0 || dst == src)
		return (dst);
	while (n--)
	{
		*result = *origin;
		result++;
		origin++;
	}
	return (dst);
}
