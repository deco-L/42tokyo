/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakamoto <sakamoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:22:08 by sakamoto          #+#    #+#             */
/*   Updated: 2023/05/15 17:28:05 by sakamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n);

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*buf;
	char			cbuf;

	buf = (unsigned char *) s;
	cbuf = (char) c;
	i = 0;
	while (i < n)
	{
		buf[i] == cbuf;
		i++;
	}
	return (s);
}
