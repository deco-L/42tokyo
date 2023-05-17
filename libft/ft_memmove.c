/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:39:35 by sakamoto          #+#    #+#             */
/*   Updated: 2023/05/18 00:09:55 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size);

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	char	*result;
	char	*origin;

	if (size == 0 || dest == src)
		return (dest);
	result = (char *) dest;
	origin = (char *) src;
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
