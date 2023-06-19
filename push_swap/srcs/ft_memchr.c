/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:38:38 by sakamoto          #+#    #+#             */
/*   Updated: 2023/05/29 12:19:11 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int c, size_t n);

void	*ft_memchr(const void *buf, int c, size_t n)
{
	int					flag;
	size_t				i;
	const unsigned char	*dest;
	unsigned char		cbuf;
	void				*result;

	i = 0;
	flag = 0;
	dest = (const unsigned char *) buf;
	cbuf = (unsigned char)c;
	while (i < n)
	{
		if (dest[i] == cbuf)
		{
			result = (void *)&dest[i];
			return (result);
		}
		i++;
	}
	return (NULL);
}
