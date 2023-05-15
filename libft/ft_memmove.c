/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakamoto <sakamoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:39:35 by sakamoto          #+#    #+#             */
/*   Updated: 2023/05/15 17:17:32 by sakamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size);

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	unsigned char	*result;
	unsigned char	*origin;

	if (size == 0 || dest == src)
		return (dest);
	result = (unsigned char *) dest;
	origin = (unsigned char *) src;
	if (dest <= src)
	{
		while (size--)
			*result++ = *origin++;
	}
	else
	{
		result += size;
		src += size;
		while (size--)
			*--result = *--origin;
	}
	return (dest);
}
