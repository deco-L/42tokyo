/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:22:08 by sakamoto          #+#    #+#             */
/*   Updated: 2023/05/22 14:20:05 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n);

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*buf;
	unsigned char	cbuf;

	buf = (unsigned char *) s;
	cbuf = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		buf[i] = cbuf;
		i++;
	}
	return (s);
}
